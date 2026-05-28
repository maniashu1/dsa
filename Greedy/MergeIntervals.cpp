// leetcode 56 ( Merge intervals ) medium 


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// it will compare second index of every vector
bool cmp(vector<int>& a , vector<int>& b){
    return a[1] < b[1];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;    // to store answer
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);  // sort on the basis of ending time 

        ans.push_back(intervals[n-1]);   // store last ele into the ans now compare from n-2th ele to 0th ele

        for(int i=n-2; i>=0; i--){  // now traverse from second last 
           vector<int> curr;
           curr = intervals[i];

           if(curr[1] >= ans[ans.size()-1][0]){  // it means overlapping
            ans[ans.size()-1][0] = min(curr[0],ans[ans.size()-1][0]);
            ans[ans.size()-1][1] = max(curr[1],ans[ans.size()-1][1]);
           }
            else {     // not overlapping directly push to ans
               ans.push_back(intervals[i]); 
           }
        }
        // for ordered ans we can reverse the ans 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main(){

    return 0;
}