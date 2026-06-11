
// Leetcode 1137 ( Nth tribonacci ) Easy

#include<iostream>
#include<vector>
using namespace std;


    vector<int> dp;
    int fun(int n){
        if(n == 0) return 0;
        if(n==1 || n==2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = fun(n-1)+fun(n-2)+fun(n-3);
    }
    int tribonacci(int n) {
       dp.clear();
       dp.resize(1000,-1);
       return fun(n);
    }


int main(){

    int n;
    cin >> n;

    cout << tribonacci(n);


    return 0;

}