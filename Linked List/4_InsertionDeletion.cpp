#include <iostream>
#include<vector>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int data1 , node* next1){
        data=data1;
        next=next1;

    }
    node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

node* convertArrayToLL(vector<int> &arr){
    node* head= new node(arr[0]);
    node * mover= head;
    for(int i=1 ;i<arr.size(); i++){
        node* temp= new node(arr[i]);
        mover->next=temp;
        mover=mover->next;
    }
    return head;
}
node* removeHead(node* head){
   //single line code
   //  return head->next;

   if (head==nullptr) return head;
   node* temp= head;
   head=head->next;
   delete temp;
   return head;
}

node* removeTail(node* head){

    if(head==nullptr || head->next==nullptr)
        return NULL;

    node * temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;

    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
node* removeKthNode(node* head ,int k){

    // edge case for k=1:
    if (k==1)
    {
       // return head->next;
       return removeHead(head);
    }
    
    int count =1;
    node* temp= head;
    while(count!=k-1){
        temp=temp->next;
        count++;
    }
    temp->next=temp->next->next;

    return head;
}

node * removeByvalue(node* head , int val){
    //edge case for the first val

    node* temp=head;
    if(temp->data==val){
        
        head=temp->next;
        free(temp);
        return head;
    }
    node * prev = nullptr;
    
    while (temp!=nullptr)
    {
        if (temp->data==val)
        {
            
            prev->next=prev->next->next; 
            free(temp); 
            return head;          
        }
        prev =temp;
        temp=temp->next;
    }
    return head;
    
}
node* InsertHead(node * head ,  int val){
    node* temp= new node(val , head);
    return temp;
}
node * InsertTail(node * head ,  int val){
    if (head == nullptr ){
        return new node(val);
    }
    node * temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    node * newNode = new node(val);
    temp->next= newNode;
    return head;
}

node * InsertAtK(node* head , int val ,int k){
    node* temp = head ;
    if(head==nullptr){
        if (k==1){
            node* newN = new node(val ,nullptr);
            return newN;
        }
        return nullptr;
    }
    if(k==1){
        node* newN = new node(val ,temp);
        return newN;
    }
    int cnt=1;
    while (temp!=nullptr){
        
        if(cnt==k-1){
            node * newNode= new node(val,temp->next );
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
        cnt++;
    }
    return head;

}
int main(){
    vector<int> nums ={9,2,4,8,5};
    node * head1= convertArrayToLL(nums); 
    //h1=removeHead(h1);
    //h1=removeTail(h1);
    //h1=removeKthNode(h1,4);
    //h1= InsertHead(h1 , 3);
    //h1 = InsertTail(h1,9 );
    //h1 =removeByvalue(h1 , 0);

    head1 = InsertAtK(head1, 0, 1);
    node* temp=head1;

    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
