#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data ;
    Node* next;
    Node(int data , Node* next ){
        // a wrong way to initialize because
        /*this statement assigns the value of member variable `this->data
        to the local variable data(which is a parameter to the function)`*/
        // data =this->data;
        // next=this->next;
        //Assigns the member variable's (uninitialized) value to the 
        //constructor parameter, leaving the member variable uninitialized or with its old value.
         
         this->data= data;
         this->next=next;
    }
};
int main(){

    // creating an object 
    Node x = Node( 92, nullptr);
    cout<<x.next;
    cout<<"\n";
    cout<<x.data;  
      cout<<"\n";
    Node * y= &x;
    cout<< y;
    cout<<"\n";
    //cout<<y.data; // gives an error 
    cout<<y->data;
        cout<<"\n";
    cout<<(*y).data;
        cout<<"\n";
    cout<<y->next;
}
