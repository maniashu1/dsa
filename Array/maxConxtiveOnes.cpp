#include<iostream>
#include<vector>
using namespace std;

 int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        vector<int> ans;
        for(int i=0; i<len; i++){
            if(nums[i] == 1){
                count++;
            } else if(nums[i] == 0){
                ans.push_back(count);
                count = 0;
            }
        }
        // if it ends with 1 then push the latest count in the ans
        ans.push_back(count);
        int max_count = ans[0];
        for(int i=1; i<ans.size(); i++){
            if(ans[i] > max_count){
                max_count = ans[i];
            }
        }
        return max_count;
    }

int main(){
    int n;
    cout << "Enter the size of the array :";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elememt of the array containing 0 and 1 : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int result = findMaxConsecutiveOnes(nums);

    cout << "The maximum consecutive ones present in the array is : " << result ;

    return 0;
}