#include<iostream>
#include<vector>
using namespace std;

int longestSubArrayequaltoSum(vector<int> &nums , int k){
    int n = nums.size();
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int maxlen = 0;
    while(right < n){
        if(left <= right && sum > k){
            sum -= nums[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen , right - left+1);
        }
        right++;
        if(right < n) {
            sum += nums[right];
        }
    }
    return maxlen;
}

int main(){

    int n ;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the elements of the array : ";

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int k;
    cout << "enter the sum value : ";
    cin >> k;

    int result = longestSubArrayequaltoSum(nums , k);

    cout << "The length of the longest subarray equal to sum is : " << result ;

    return 0;
}