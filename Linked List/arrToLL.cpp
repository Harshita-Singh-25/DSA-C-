#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct nodeOfLL{
    int data;
    nodeOfLL* next;
    nodeOfLL(int data1, nodeOfLL* next1){
        this->data=data;
        this->next=next1;   
    }
    //multiple constructor
    nodeOfLL(int data1){
        this->data=data1;
        this->next=nullptr;
    }
};

/*
nodeOfLL* ArrtoLL(vector<int> arr ){
 // here a copy of the vector will be passed and the orignal vector 
    will not be modified 
}
*/
nodeOfLL* ArrtoLL(vector<int> &arr ){
    nodeOfLL* head =new nodeOfLL(arr[0]);
    nodeOfLL* mover = head;
     for(int i=1;i<arr.size();i++){
       nodeOfLL* temp = new nodeOfLL(arr[i]);
       mover->next =temp;
       // now for  moving the mover to the next node you can either:
       //mover=temp; ///or:
       mover=mover->next;
    }  
    return head; 
}

// function to find the length of a linked list
//=  traversal and incrementing the count
int LengthofLL(nodeOfLL* head){
    int count=0;
    nodeOfLL* temp = head;

    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}
int main(){
    int arr[5]={77,5,2,1,3};
    vector<int> nums ={58,99,71,86,1};
    nodeOfLL * head1 = ArrtoLL(nums);
   
    cout<< head1->data<<"\n";
    nodeOfLL* temp =head1;
    // Traversal in a LInked List:
    while (temp)
    {
        cout<< temp->data<<" ";
        temp=temp->next;
    }
    cout<< "The length of LL is"<<LengthofLL(head1);
    
}  

