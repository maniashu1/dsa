
// leetcode 1005 ( maximise sum of the array after k negation ) easy

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

    int largestSumAfterKNegations(vector<int>& nums, int k) {

        priority_queue<int,vector<int> , greater<int>> pq; // creating a min heap
        // we can also initialize pq like
        // priority_queue<int,vector<int>,greater<int>> pq(nums.begin(),nums.end());
        int sum = 0; 
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
            sum += nums[i];
        }
        while(k--){
            if(pq.top() == 0){
                break;
            }
            int ele = pq.top();
            pq.pop();
            sum -= ele;
            pq.push(-ele);
            sum += (-ele);
        }
        return sum;
    }


int main(){
    int n ;
    cout << "Enter the size of the array : "  ;
    cin >> n;

    cout << "Enter the elements of the array : ";

    vector<int> nums(n);
    for(int i=0; i<n; i++){
       cin >> nums[i];
    }
   
    int k;
    cout << "Enter the number of times you want to apply negations : ";
    cin >> k;

    int ans = largestSumAfterKNegations(nums,k);

    cout << " The maximum sum of array after k negation is : " << ans ;

    return 0;
}