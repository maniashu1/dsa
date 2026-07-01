
// Leetcode 1669 ( Merge in Between Linked list ) Medium

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail = list2;
        // find tail pointer of list 2
        while (tail->next != NULL) {
            tail = tail->next;
        }
        ListNode* temp1 = list1;
        for(int i=0; i<a-1; i++){
            temp1 = temp1->next;
        }
        ListNode* temp2 = temp1->next;
        temp1->next = list2;
        for(int i=a; i<b; i++){
            temp2 = temp2->next;
        }
        tail->next = temp2->next;
        
        return list1;
    }
};

int main(){


    return 0;
}