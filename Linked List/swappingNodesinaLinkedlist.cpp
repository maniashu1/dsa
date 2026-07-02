
// Leetcode 1721 ( Swapping nodes in a linked list ) Medium

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
    ListNode* swapNodes(ListNode* head, int k) {
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        temp = head;
        for(int i=1; i<k; i++){
            temp = temp->next;
        }
        ListNode* temp2 = head;
        for(int i=1; i<count-k+1; i++){
            temp2 = temp2->next;
        }
        swap(temp->val,temp2->val);

        return head;
    }
};

int main(){


    return 0;
}