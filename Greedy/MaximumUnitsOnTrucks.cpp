// leetcode 1710 ( maximum units on a truck ) easy 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// custome comparater to comopare no of units
bool cmp(vector<int>& a , vector<int>& b){
    return a[1] > b[1];
}


    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort the boxes in decreasing order on the basics of no of units
        sort(boxTypes.begin(),boxTypes.end(),cmp); 
        int maxUnits = 0;
        for(int i=0; i<boxTypes.size(); i++){
            if(boxTypes[i][0] <= truckSize){
                maxUnits += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0]; 
            } else { // pick the remainng box of remaining units
                maxUnits += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
            if(truckSize == 0) break;
        } 
        return maxUnits;
    }



int main(){

    return 0;
}