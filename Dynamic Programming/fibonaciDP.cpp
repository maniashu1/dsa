#include<iostream>
#include<vector>
using namespace std;

vector<int> dp; // a global vector dp

int fun(int n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];   // if dp != -1 i.e, it is calculated 
    return dp[n] = fun(n-1) + fun(n-2);
 }

int main(){
    int n;
    cin>>n;
    dp.clear();                 // erase if any garbage value present inside the dp. 
    dp.resize(n+1 , -1);        // make dp of size n+1 and initialize with -1        

    cout << fun(n) ;

    return 0;
}