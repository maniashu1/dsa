// leetcode 881 ( Boat to save people ) medium

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int boatCount = 0;
        int i = 0;
        int j = people.size()-1;
        while(i <= j){
            if((people[i]+people[j]) <= limit){
                i++;
                j--;
                boatCount++;   // allocate boat to the pair 
            } else {
                j--;  // allocate boat to the heaviest person
                boatCount++;
            }
        }
        return boatCount;
}

int main(){

    return 0;
}