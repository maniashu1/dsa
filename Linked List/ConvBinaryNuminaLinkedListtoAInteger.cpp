
// Leetcode 1290 ( Convert Binary number in a Linked list to a integer ) Easy

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
    int getDecimalValue(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            len++;
        }
        // if list has only one element 
        if(head->next == NULL){
            if(head->val == 0){
                return 0;
            } return 1;
        }
        int ans = 0;
        temp = head;
        len--;
        while(temp){
            if(temp->val == 1){
                ans += pow(2,len)*1;
                len--;
                temp = temp->next;
            } else {
                temp = temp->next;
                len--;
            }           
        }
        return ans;
    }
};

int main(){

    return 0;
}