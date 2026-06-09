/*

CSES problem set : Dice combination
Your task is to count the number of ways to construct the sum n by throwing the dice one or more times

input: 
n = 3

output:
4

Explanation:
1 + 1 + 1 = 3
1 + 2 = 3
2 + 1 = 3
3 = 3

*/

// f(n) = summation f(n-i) , for all i E[0,6]

#include<iostream>
#include<vector>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<int> dp(1000005,-1);

int fun(int n){
   if(n == 0) return 1; // for 0 there is 1 way i.e, do not throw the dice
   ll ways = 0;
   if(dp[n] != -1) return dp[n];
   for(int i=1 ; i<=6 ; i++){
    if(n-i < 0) break;
      ways = (ways%mod + fun(n-i)%mod)%mod;  // (a+b) mod c = (a%mod + b%mod)%mod c
   }
   return dp[n] = ways%mod;
}


int main(){
 int n;
 cin >> n;

 cout << fun(n);

    return 0;
}