// Leetcode 242 ( Valid anagram)

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
        int a = s.size();
        int b = t.size();
        // if(a != b) return false;
        // else sort(s.begin(),s.end());
        //      sort(t.begin(),t.end());
        //      if(s == t) return true;
        //      else return false;
        if(a != b) return false;
        unordered_map<char,int> mp;
        for(int i=0; i<a; i++){
            mp[s[i]]++;
        }
        for(int i=0; i<b; i++){
            char ch = t[i];
            if(mp.find(ch) != mp.end()){
                mp[ch]--;
                if(mp[ch] == 0) mp.erase(ch);
            }
            else return false;
        }
        if(mp.size() > 0) return false;
        else return true;
         
    }

    int main(){

        retrurn 0;
    }