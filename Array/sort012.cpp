#include<iostream>
#include<vector>
using namespace std;

void sortColors(vector<int>& nums) {
        int left = 0;
        int mid = 0;
        int right = nums.size() - 1;
        while(mid <= right){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[left]);
                mid++;
                left++;
            } else if(nums[mid] == 1){
                mid++;
            } else if(nums[mid] == 2){
                swap(nums[mid] , nums[right]);
                right--;
            }
        }
    }

int main(){

    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the element of the array : ";

    for(int i=0; i<n; i++){
        cin >> nums[i] ;
    }

    cout << "Sorted array : ";

    sortColors(nums);

     for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }


    return 0;
}