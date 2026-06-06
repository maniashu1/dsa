/*

given a number n you can perform any of the following operstions om it some number of times 
1. reduce to n-1
2. if n is divisible by 2 , make it n/2
3. if n is divisible by 3 , make it n/3
find out in how many minimum steps you can reduce n to 1

*/

#include<iostream>
#include<algorithm>
#include<vector>
#define inf INT_MAX
using namespace std;

vector<int> dp;

// recursive solution
int fun(int n){
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;
     //NOTE :  use curly {} braces to compare more than two numbers inside the min function
    return 1 + min({fun(n-1),(n%2==0) ? fun(n/2) : inf , (n%3==0) ? fun(n/3) : inf});
}

// top down dynamic programming approach
int ftd(int n){
    if(n == 1) return 0;
    if(n == 2 || n == 3) return 1;
    if(dp[n] != -1) return dp[n]; // return pre comupted nth state
    return dp[n] = 1 + min({ftd(n-1),(n%2==0) ? ftd(n/2) : inf , (n%3==0) ? ftd(n/3) : inf});
}

// bottom up approach
int fbu(int n){
     dp.clear();  // clearing prestored garbage value
     dp.resize(n+1,-1);
     dp[1] = 0; 
     dp[2] = 1; 
     dp[3] = 1;
     for(int i=4; i<=n; i++){
         dp[i] = 1 + min({dp[i-1],(n%2==0) ? dp[i/2] : inf , (n%3==0) ? dp[i/3] : inf});
     }
     return dp[n];
}

int main(){
    int n;
    cin >> n;
    dp.clear();  // clearing prestored garbage value
    dp.resize(n+1,-1);
    cout << ftd(n);

    return 0;
}