#include<iostream>
#include<vector>
using namespace std;

class NodeDLL
{
public:
    int data;
    NodeDLL* next;
    NodeDLL* back;
public:
    NodeDLL(int data ,NodeDLL* next , NodeDLL* back){
        this->data= data;
        this->back=back;
        this->next=next;
    };
    NodeDLL(int data){
        this->data=data;
        back=nullptr;
        next=nullptr;

    }
};
NodeDLL* convertArr2Dll(vector<int> &arr){
    NodeDLL* head= new NodeDLL(arr[0]);
    NodeDLL* prev = head;
    for(int i=1 ; i<arr.size() ;i++){
        NodeDLL* temp= new NodeDLL(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;   //prev = prev->next;
    }
    return head;
}
void printDLL(NodeDLL* head){
    NodeDLL* temp = head;
    while (temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }   
}
//Deleting the head , tail, kth node and given node

NodeDLL * DeleteHead(NodeDLL* head){
    if (head == NULL || head->next==nullptr)
    {
        return nullptr;
    }
    
    NodeDLL* temp=head;
    head=head->next;
    (*head).back = nullptr;
    temp->next=nullptr;
    delete(temp);
    return head;
    
}
NodeDLL * DeleteTail(NodeDLL * head){
    if (head == NULL || head->next==nullptr)
    {
        return nullptr;
    }
    NodeDLL * temp= head;
    while (temp->next!=nullptr) //if we put temp!=nullptr; //=>temp will become null 
    {
        temp= temp->next;
    }
    temp->back->next=nullptr;
    free (temp);
    return head;
}
NodeDLL * DeleteKth (NodeDLL* head, int k){
    int count =0;
    if(head==nullptr) return nullptr;
    NodeDLL* kthNode= head;
    while (kthNode!=nullptr)
    {
        count++;
        if(count==k){
            break;
        }
        kthNode=kthNode->next;
    }
    // If k-th node doesn't exist
    if (kthNode == nullptr) {
        return head;  // k is out of bounds, return original list
    }
    
    NodeDLL * prev= kthNode->back;
    NodeDLL * front = kthNode->next;
    if (prev==nullptr)
    {
        return DeleteHead(head);    
    }
    else if (front==nullptr)
    {
       return DeleteTail(head);
    }
    else{
        prev->next=front;
        front->back=prev;
        kthNode->next=nullptr;
        kthNode->back = nullptr;
        delete kthNode;          // Use delete instead of free
    }   
    return head;
}

// one left deleting the given node

// now insertion before: head, tail, kth node  

NodeDLL * Insertb4Head(NodeDLL * head , int val){
    if (head==nullptr)
    {
        return head= new NodeDLL(val);
    }
    NodeDLL * newHead = new NodeDLL(val , head , nullptr);
    head->back=newHead;
    return newHead;
}
NodeDLL * Insertb4kth(NodeDLL * head , int k , int val){
    if(k==1){
        return Insertb4Head(head , val);
    }
    int count =0;
    NodeDLL* temp = head;
    while (temp!=nullptr)
    {
        count++;
        if(count==k) break;
        temp= temp->next;

    }
    NodeDLL * prev= temp->back;
    NodeDLL * newNode = new NodeDLL(val , temp ,prev);
    prev-> next= newNode;
    temp->back=newNode;
    return head;
}
int main(){
    vector<int> arr= {7,3,1,8,0,5};
    NodeDLL* head1 =convertArr2Dll(arr);
    //head1=DeleteHead(head1);
    //head1=DeleteTail(head1);
    // head1=DeleteKth(head1 , 4);
    // head1= Insertb4Head(head1 , -39);
    head1=Insertb4kth(head1 , 3, -4);
    printDLL(head1);
}

