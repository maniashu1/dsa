
// leetcode 2208 ( minimum number of operation to half array sum ) medium 

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 int halveArray(vector<int>& nums) {
        int n = nums.size();
        double sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        double halfSum = sum / 2.0;
        priority_queue<double> pq;
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        int nopr = 1;
        
        while(!pq.empty() && sum > halfSum){
            float k = pq.top();
            pq.pop();
            sum -= (k/2);
            if(sum <= halfSum){
                return nopr;
                break;
            } else {
                pq.push(k/2);
                nopr++;
            }
        }
        return nopr;
    }

    int main(){

        return 0;
    }