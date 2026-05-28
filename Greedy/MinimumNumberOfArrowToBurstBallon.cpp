
// leetcode 452 ( minimum number of arrow required to burst the ballon ) medium

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(vector<int>&a ,vector<int>&b){
    return a[1]<b[1];
} 

// first calculate the non overlapping interval
// then subtract non overlapping from the size of the points
// bcoz overlapping will brust together in single arrow

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int ans = 0;
        int n = points.size();
        int lastPoint = points[0][1];
        for(int i=1; i<n; i++){
           if(points[i][0] <= lastPoint){
            ans++;
           } else {
             lastPoint = points[i][1];
           }
        }
        int result = n - ans;
        return result;
    }
};

int main(){

    return 0;
}