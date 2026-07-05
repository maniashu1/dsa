
// Leetcode 2181 ( Merge Nodes in between zeroes ) Medium

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
    ListNode* mergeNodes(ListNode* head) {

    ListNode* dummy = new ListNode(0);
    ListNode* temp2 = dummy;

    ListNode* temp = head;

    while(temp){

        int sum = 0;

        // first zero skip
        temp = temp->next;

        while(temp && temp->val != 0){
            sum += temp->val;
            temp = temp->next;
        }

        if(sum > 0){
            temp2->next = new ListNode(sum);
            temp2 = temp2->next;
        }
    }

    return dummy->next;
}
};

int main(){

    return 0;
}