#include<iostream>
using namespace std;
struct Node{
    int data ;
    Node* next;

    Node(int data , Node* next){
        this->data=data;
        this->next=next;
    }
    Node(int val){
        this->data=val;
        this->next=nullptr;
    }
};
Node*  arrayToLL(int *arr){
    Node* head= new Node(arr[0]);
    Node* mover= head;
    for (int i=1;i< 5; i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }   
    return head; 
}

int searchIfPresent(Node* head,  int  val){
    Node* temp = head;
    while(temp){
        if (temp->data==val){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int main(){
    int arr[5]= {5,7,1,6,9};
    Node * head = arrayToLL(&arr[0]);
    int ans = searchIfPresent(head , 8);
    cout<< ans;

}