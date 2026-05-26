
// leetcode 2182 ( construct String with Repeat limit ) medium 

#include<iostream>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;


    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        priority_queue<pair<char, int>> pq;
        for (auto p : mp) {
            pq.push(p);
        }
        string ans = "";
        while (!pq.empty()) {
            pair<char, int> largest = pq.top();
            pq.pop();
            int len = min(repeatLimit, largest.second);
            for (int i = 0; i < len; i++) {
                ans += largest.first;
            }
            pair<char, int> secondlargest;
            if (largest.second - len > 0) {
                if (!pq.empty()) {
                    secondlargest = pq.top();
                    pq.pop();
                    ans += secondlargest.first;
                } else {
                    return ans;
                }
                if (secondlargest.second - 1 > 0)
                    pq.push({secondlargest.first, secondlargest.second - 1});
                pq.push({largest.first, largest.second - len});
            }
        }
        return ans;
    }


int main(){

    return 0;
}
