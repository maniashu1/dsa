// leetcode 435 ( Non - overlapping interval ) medium

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// comparater function to compare ending time 
bool cmp(vector<int>& a , vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort the intervals in increasing order on the basis of their end time 
        sort(intervals.begin(),intervals.end(),cmp);
        int ans = 0;
        int lastEndtime = intervals[0][1];
        
        for(int i=1; i<intervals.size(); i++){
             if(intervals[i][0] < lastEndtime){
                ans++;
             } else {
                 lastEndtime = intervals[i][1];
             }
        }
        return ans;
    }
};

int main(){

    return 0;
}