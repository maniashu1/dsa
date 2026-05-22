
//  Leetcode 23 ( Merge k sorted lists ) hard

#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class ListNode{
  public:
  int val;
  ListNode* next;
};

// custom comparater function for building min heap 

class cmp{
    public:
    bool operator()(const ListNode* l1 , const ListNode* l2){
         return l1->val > l2->val;
    }  
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // making priority queue of type L  ListNode* , which will store all the head node of the lists
        priority_queue<ListNode* , vector<ListNode*> , cmp> pq; 

        // psuhing first node of the every list to the pq
        for(int i=0; i<lists.size(); i++){
            if(lists[i] == NULL) continue;
            pq.push(lists[i]);
        }

        // now making a dummy node
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr = dummy;

        //now traversing in pq
        while(!pq.empty()){
            ListNode* curr = pq.top();
            pq.pop();
            if(curr->next != NULL) pq.push(curr->next); // psuhing next node of the list into the pq
            ptr->next = curr;
            ptr = ptr->next;
        }
        return dummy->next;
    }
};


int main(){


    return 0;
}