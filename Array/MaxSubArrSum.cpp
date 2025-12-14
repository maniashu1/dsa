// kadane's algorithm

#include<iostream>
#include<vector>
using namespace std;

 int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            if(sum > maxi){
                maxi = sum;
            } if(sum < 0){
               sum = 0;
            }
        }
       return maxi;
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

    int maxSum = maxSubArray(nums);

    cout << "The maxium sum of the subarray is : " << maxSum ;

    return 0;
}