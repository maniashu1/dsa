// Leetcode 692 ( top k frequent word ) medium 

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
using namespace std;


// in this question we use min heap and take -ve value of freq
// so that we cant need to write comparater function 
/*
 Example With Positive Frequency

Suppose:

(2,"i")
(2,"love")

Now compare:

First values equal:

2 == 2

So compare strings:

"love" > "i"

Therefore:

(2,"love") > (2,"i")

So max heap puts:

(2,"love")

on top.

But problem wants:

"i"

first.

So max heap fails.

Why Negative Frequency Works

Now store:

(-2,"i")
(-2,"love")
*/

#define pp pair <int,string> 

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // creatre a unordered map and store all the word with there frequencies
        unordered_map<string,int> mp;
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        // creating a priority queue (min heap) to store all the words
        // min heap naturally gives lexicographically smaller strings first. if freq is same 
        priority_queue<pp,vector<pp>,greater<pp> >pq;
        for(auto entry : mp){
            int freq = entry.second;
            string word = entry.first;
           // trick : smaller negative value means larger frequency
           // and for same frequency, lexicographically smaller word automatically comes first
            pq.push({-freq,word}); 
        }
        vector<string> ans; 
        pp topWord;
        while(k-- && !pq.empty()){
            topWord = pq.top();
            pq.pop();
            ans.push_back(topWord.second);
        }
        return ans;
    }
};

int main(){

    return 0;
}