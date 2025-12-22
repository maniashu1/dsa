#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// optimal solution using unordered set
int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
        }
        for(auto it : st){
            if(st.find(it - 1) == st.end()){
                int count = 1;
                int x = it;
                while(st.find(x+1) != st.end()){
                    x = x + 1;
                    count = count + 1;
                }
                longest = max(longest , count);
            }
        }
        return longest;
    }

    int main(){
        int n;
        cout << "Enter the size of the array : ";
        cin >> n;

        vector<int> nums(n);
        
        cout << "Enter the element of the array : ";

        for(int i=0; i<n; i++){
            cin >> nums[i];
        }

        int result = longestConsecutive(nums);

        cout << "The longest consecutive array is : " << result;
    }