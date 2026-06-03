
#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

int countBinaryStrings(int n){
    if(n == 1) return 2;  // string will be 0,1
    if(n == 2) return 3;  // string will be 00,01,10
    if(dp[n] != -1) return dp[n];
    return dp[n] = countBinaryStrings(n-1) + countBinaryStrings(n-2);
}

int main(){
    int n;
    cin >> n;
    dp.clear();
    dp.resize(n+1,-1);
    int ans = countBinaryStrings(n);
    cout << ans ;
    return 0;
}