// rearrange array with equal number of positive and negative number

#include<iostream>
#include<vector>
using namespace std;

 vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 0);
        int posIdx = 0;
        int negIdx = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                ans[negIdx] = nums[i];
                negIdx += 2;
            } else if(nums[i] > 0){
                ans[posIdx] = nums[i];
                posIdx += 2;
            }
        }
        return ans;
    }

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> ans(n,0);

    ans = rearrangeArray(nums);

    for(int i=0; i<n; i++){
        cout << ans[i] << " ";
    }

    return 0;
}