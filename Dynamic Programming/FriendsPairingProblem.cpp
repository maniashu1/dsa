// friends pairing problem - friends can go in party either in single or in a pair 

#include<iostream>
#include<vector>
using namespace std;

vector<int> dp;

/*
 f(n) = f(n-1) + (n-1)*(f(n-2))

 if n=4 i.e, {A B C D} -> CASE 1: D want to  go alone ..-> f(n-1) ways 
                          CASE 2: D want to go in pair , D can pair with A , B , C
                                n-1
                                   C  * f(n-2) ways 
                                    1
                             
*/ 

int countNoWays(int n){
    if(n == 1) return 1;
    if(n == 2) return 2; // both can go in a pair or can go as a single person
    if(dp[n] != -1) return dp[n];
    return dp[n] = countNoWays(n-1) + ((n-1)*countNoWays(n-2));
}

int main(){

    int n;
    cin >> n;

    dp.clear();
    dp.resize(n+1,-1);
    
    int ans = countNoWays(n);
    cout << ans;
    
    return 0;
}