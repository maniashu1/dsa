
// Letcode 123 ( Best time to buy and sell stock iii ) Hard

#include<iostream>
#include<vector>
using namespace std;


    
    int dp[100005][15][2];

    int fun(vector<int>& prices,int i,int k,bool on){
        if(i == prices.size()) return 0;
        if(dp[i][k][on] != -1) return dp[i][k][on];
        int ans = INT_MIN;
        ans = fun(prices,i+1,k,on);  // avoid buying on ith day
        if(on){
            ans = max(ans,prices[i]+fun(prices,i+1,k-1,false));  // buy on ith day
        } else {
            if(k>0){
                ans = max(ans,fun(prices,i+1,k,true) - prices[i]); // sell om ith day
            }
        }
        return dp[i][k][on] = ans;
    }
    
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return fun(prices,0,2,false);
    }


int main(){

    return 0;

}