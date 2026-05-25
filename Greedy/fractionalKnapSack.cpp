#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// custome cpmparater function to return higher profit upon weight ratio
bool cmp(pair<int,int>& p1 , pair<int,int>& p2){
    double r1 = (p1.first*1.0) / (p1.second*1.0);
    double r2 = (p2.first*1.0) / (p2.second*1.0);
    return r1 > r2;  // if r1 > r2 it will return true and r1 will be selected otherwise r2 will be sleected 
}

// defining fractional knapsack function  

double fractionalKnapsack(vector<int>& profit , vector<int>& weights , int n, int w){

      vector<pair<int,int> > arr;
      for(int i=0; i<n; i++){
        arr.push_back({profit[i],weights[i]});
      }
      sort(arr.begin(),arr.end(),cmp); // sort the arr on decreasing order of the profit/weight ratio 

      double maxProfit = 0;
      for(int i=0; i<n; i++){
        if(arr[i].second <= w){
            maxProfit += arr[i].first;
            w -= arr[i].second;
        } else {
            maxProfit += ((arr[i].first*1.0) / (arr[i].second*1.0)) * w; // calculating final remainng weight 
            w = 0;  // required  weigths achieved 
            break;
        }
      }
      return maxProfit;
}

int main(){

    vector<int> profits = {100 , 200 , 500};
    vector<int> weights = {3 , 5 , 9};
    int n = 3;
    double w = 10;

    double ans = fractionalKnapsack(profits,weights,n,w);

    cout << ans ;

    return 0;
}
