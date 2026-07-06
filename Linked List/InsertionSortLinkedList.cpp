
// Leetcode 147 ( Insertion sort on linked list ) Medium

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
    ListNode* insertionSortList(ListNode* head) {
        // creating a dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;

        while(curr){
            
            ListNode* prev = dummy;
            ListNode* cur = dummy->next;

            while(cur && cur->val <= curr->val){
                prev = prev->next;
                cur = cur->next;
            }

            ListNode* nex = curr->next;
            curr->next = cur;
            prev->next = curr;
            curr = nex;
        }

        return dummy->next;
    }
};

int main(){

    return 0;
}