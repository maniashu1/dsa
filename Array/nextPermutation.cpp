#include<iostream>
#include<vector>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &nums){
   int n = nums.size();
   int idx = -1;
   for(int i=n-2; i>=0; i--){
    if(nums[i] < nums[i+1]){
        idx = i;
        break;
    }
   }
   if(idx == -1){
    reverse(nums.begin() , nums.end());
    return nums;
   }
   for(int i=n-1; i>idx; i--){
    if(nums[i] > nums[idx]){
        swap(nums[i] , nums[idx]);
        break;
    }
   }
   reverse(nums.begin() + idx + 1 , nums.end());
   return nums;

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
    
    nextGreaterPermutation(nums);

    cout << "Next permutation is : ";

    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    return 0;
}