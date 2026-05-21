// Leetcode 1046 ( last stone weight ) easy

#include<iostream>
#include<queue>
#include<vector>
using namespace std;


int lastStoneWeight(vector<int>& stones) {
        int x;
        int y;
        int len = stones.size();
        if(len == 0) return 0;
        if(len == 1) return stones[0];
        priority_queue<int> pq(stones.begin(),stones.end()); // by default it is a maxheap
        while(len >= 2){
           y = pq.top();
           pq.pop();
           x = pq.top();
           if(x == y){
             pq.pop();
             len -= 2;
           } else {
             pq.pop();
             pq.push(y-x);
             len -= 1;
           }
        }
        if(len == 1) return pq.top();
         else return 0;
    }


// c by t    

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
           int p1 = pq.top(); // first maximum
           pq.pop();
           int p2 = pq.top(); // second maximum
           pq.pop();
           int sub = abs(p1 - p2);
           if(sub != 0) pq.push(sub);

        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};


int main(){

    return 0;
}