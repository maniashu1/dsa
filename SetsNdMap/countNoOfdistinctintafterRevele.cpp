#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int reverse(int n){
      int r = 0;
      while(n > 0){
          r *= 10;
          r += (n%10);
          n = n/10;
      }
      return r;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0; i<n; i++){
            int rev = reverse(nums[i]);
            s.insert(nums[i]);
            s.insert(rev);
        }
        return s.size();
    }

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    cout << endl;

    cout << "Original array : ";

    for(int i=0; i<n; i++){
        cout << nums[i] << " ";
    }

    cout << endl;

    int result = countDistinctIntegers(nums);

    cout << "No of distinct inregers is : " << result ;

    return 0;

}