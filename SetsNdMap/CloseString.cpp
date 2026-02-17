
// Leetcode 1657 ( Determinig that given two strings are close or not)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool closeStrings(string word1, string word2) {
        // if length of both string not equal then return false
        if(word1.length() != word2.length()) return false;
       
        unordered_map<char,int> mp1 , mp2;

        for(int i=0; i<word1.length(); i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        for(auto ele : mp1){
            char ch = ele.first;
            // checking if there is any different character are present or not ?
            // if it is present then it can never be a close string.
            if(mp2.find(ch) == mp2.end()) return false;
        }

        // now we have to create two another map of frequencies

        unordered_map<int,int> h1,h2;

        for(auto x : mp1){
            int freq = x.second;
            h1[freq]++;
        }

        for(auto x : mp2){
            int freq = x.second;
            h2[freq]++;
        }

        // now compare these two helper function

        for(auto y : h1){
            int key = y.first;
            if(h2.find(key) == h2.end()) return false;
            if(h2[key] != h1[key]) return false;

        }
        
        return true;
    }

    int main(){

        return 0;
    }