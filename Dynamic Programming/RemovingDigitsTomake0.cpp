/*

Removing digits : cses problem set
you are given an integer n . On each step , you may subtract one of the digits from the number .
How many steps are required are to make the numbeer 0 ?

input:
27
output:
5

Explanation: 27 -> 20 -> 18 -> 10 -> 9 -> 0

*/

// fun(n) = 1 + min(ans,fun(n-d[i]));

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> get_digit(int n){
    vector<int> result;
    while(n > 0){
        if(n % 10 != 0){
        result.push_back(n%10);
    } 
       n = n/10;
    }
    return result;
}

vector<int> dp;

int removingDigits(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    dp.clear();
    dp.resize(n+1,-1);
    if(dp[n] != -1) return dp[n];
    vector<int> d = get_digit(n);
    int ans = INT_MAX;
    for(int i=0; i<d.size(); i++){
        ans = min(ans,removingDigits(n-d[i]));
    }
    return dp[n] =  1+ans;
}

int main(){

    int n;
    cin >> n;
    
    int ans = removingDigits(n);
    cout <<  ans;

    return 0;
}