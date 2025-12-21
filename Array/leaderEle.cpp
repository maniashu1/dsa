#include<iostream>
#include<vector>
using namespace std;

vector<int> leaderElemets(vector<int> &arr , int n){
     vector<int> ans;
     int max = INT_MIN;
     for(int i=n-1; i>=0; i--){
        if(arr[i] > max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
     }
     return ans;
}

int main(){
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array : ";

    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    
    vector<int> result;

    result = leaderElemets(arr,n);

    cout << "Leder element is : ";

    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}

