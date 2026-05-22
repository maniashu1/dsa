// Leetcode 451 ( sort character by frequency ) medium

#include<iostream>
#include<string>
#include<unordered_map>
#include<queue>
using namespace std;

#define pp pair<int,char>
class Solution {
public:
    string frequencySort(string s) {

        // count freq of each string and store into a map
        unordered_map<char,int> mp;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }

        // psuhing all the mp value in priority queue or a max heap
        priority_queue<pp> pq; // max heap
        for(auto ele : mp){
            char key = ele.first;
            int freq = ele.second;
            pq.push({freq,key});
        }
        
        string ans = "";
        while(!pq.empty()){
            pp curr = pq.top();
            pq.pop();
            for(int i=0; i<curr.first; i++){
                ans += curr.second;
            }
        }
        return ans;
    }
};

int main(){


    return 0;

}