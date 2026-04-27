

// Leetcode 503 ( Medium ) Next greater element II

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        int n = nums.size();
        vector<int> nge;

        for(int i=2*n-1; i>=0; i--){ // we have using hypothetical index and imaging array is doubled 
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i < n){ 
                int ng = st.empty() ? -1 : st.top();
                nge.push_back(ng);
            }
            st.push(nums[i%n]);
        }
        reverse(nge.begin() , nge.end());
        return nge;
    }

int main(){

    return 0;
}