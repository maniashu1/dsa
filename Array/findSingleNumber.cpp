#include<iostream>
#include<vector>
using namespace std;


int singleNumber(vector<int>& nums) {
        int xorr = 0;

        for(int i=0; i<nums.size(); i++){
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }

int main(){
    int n ;
    cout << "Enter the sizre of the array :";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the element of the array : ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int ans = singleNumber(nums);

    cout << "The number doent repeate in the array : " << ans ;
    return 0;
}