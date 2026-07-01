
// Leetcode 2095 ( Delete Middle node of the linked list )  Medium

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        if(head == NULL || head->next == NULL) {
            return NULL;
        }
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is pointing to mid
        prev->next = slow->next;
        return head;
    }
};

int main(){

    return 0;
}
