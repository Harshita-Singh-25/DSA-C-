
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode * temp1 =  l1; 
      ListNode * temp2 = l2;
      ListNode * ans= new ListNode(0);
      ListNode * temp= ans;
     // ListNode * dummy;
      int buffer=0;
      while( temp1!= nullptr || temp2!= nullptr){
        if(temp1==nullptr){
            temp1=new ListNode(0);

        }
        if(temp2 == nullptr){
            temp2= new ListNode(0);
        }

        buffer = temp1->val + temp2->val;

        if(buffer>=10){
            int mod = buffer%10;
            temp->val+=mod;
            temp->next=new ListNode(1);
        }
        else{
            temp->val+= buffer;
            temp->next= new ListNode(0);
        }
        
        temp1=temp1->next;
        temp2=temp2->next;
        temp=temp->next;
      }
    return ans;   
    }
};