
// Leetcode 188 ( Best time to buy and sell stock - iv) Hard

#include<iostream>
#include<vector>
using namespace std;


    int dp[1005][105][2];
    int fun(vector<int>& prices,int i,int k, bool on){
         if(i == prices.size()) return 0;
         if(dp[i][k][on] != -1) return dp[i][k][on];
         int ans = INT_MIN;
         ans = fun(prices,i+1,k,on); // avoid buying
         if(on){
            ans = max(ans,prices[i] + fun(prices,i+1,k-1,false));  // buy it 
         } else {
            if(k > 0){
                ans = max(ans,fun(prices,i+1,k,true)-prices[i]); // sell it 
            }
         }
         return dp[i][k][on] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        memset(dp,-1,sizeof dp);
        return fun(prices,0,k,false);
    }


int main(){

    return 0;
}