
// Leetcode 1207 ( Unique numbaer of occurences )

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
           mp[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto ele : mp){
            int freq = ele.second;
            if(s.find(freq) != s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }


    int main(){

        return 0;
    }