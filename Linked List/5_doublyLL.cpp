#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
struct NodeOfDLL{
    int data ;
    NodeOfDLL* next ;
    NodeOfDLL* prev;
    NodeOfDLL(int data1,NodeOfDLL* prev1 ,NodeOfDLL* next1){
        data= data1;
        prev =prev1;
        next= next1;
    }
    NodeOfDLL(int data ){
        this->data=data;
        next=nullptr;
        prev=nullptr;

    }
};
//convert an array to DLL
NodeOfDLL* ConvertArrToDLL(vector<int> & arr){
    NodeOfDLL* head =new NodeOfDLL(arr[0]);
    NodeOfDLL* mover =head;
    NodeOfDLL* tail;
    //NodeOfDLL* prev;
    for(int i=1; i< arr.size();i++){
        NodeOfDLL* temp= new NodeOfDLL(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        //mover=mover->next; 
        mover=temp;
    }
    tail = mover;
    return tail;
}
int main(){
    
    vector<int> nums={9, 6 , 5,0,7};
    // NodeOfDLL * h1 = ConvertArrToDLL(nums);
    // NodeOfDLL* temp1 = h1;
    // while(temp1!= nullptr){
    //     cout<<temp1->data<<" ";
    //     temp1=temp1->next;
    // }
    NodeOfDLL * tail = ConvertArrToDLL(nums);
    NodeOfDLL * temp = tail;
    while (temp)
    {
        cout<<temp->data<<" ";
         temp=temp->prev;

    }
    return 0;
}