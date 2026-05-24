// leetcode 1642 ( furthest building you can reach ) medium 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0;
        int bricksUsed = 0;
        for(; i<heights.size()-1; i++){
            if(heights[i] >= heights[i+1]){  // directly jump to another building 
                continue;
            }
            int heightDiff = heights[i+1] - heights[i];
            if(heightDiff + bricksUsed <= bricks){ // check if we have enough bricks to used 
                bricksUsed += heightDiff;
                pq.push(heightDiff);
            } else if(ladders > 0){
                if(!pq.empty() && pq.top() > heightDiff){   // it means we can use bricks instead of using ladders
                    bricksUsed = bricksUsed - pq.top() + heightDiff;
                    pq.pop();
                    pq.push(heightDiff);
                } 
                ladders--;
            } else {
                break; // cant move forward 
            } 
        }
        return i;
    }
};

int main(){


    return 0;
}