
// Leetcode 2130 ( Maximum twin sum of a linked list ) Medium

#include<iostream>
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:

     ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
       ListNode* curr = head;
       ListNode* Next = NULL;
       while(curr){
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
       }
       return prev;
    }

    int pairSum(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }   
        temp = head;
        int ans = INT_MIN;

        // if list has only two element
        if(len == 2){
          return ans = max(ans,temp->val+temp->next->val);
        }

        for(int i=1; i<(len/2); i++){
            temp = temp->next;
        }
        
        // creating new list of half list 
        ListNode* head2 = new ListNode(0);
        head2 = temp->next;
        temp->next = NULL;

        // reverse half list 

        head2 = reverseList(head2);    
    
        ListNode* temp1 = head;
        ListNode* temp2 = head2;
       
        while(temp1){
           ans = max(ans,temp1->val + temp2->val);
           temp1 = temp1->next;
           temp2 = temp2->next;
        }

        return ans;
    }
};

int main(){

    return 0;
}