// Leetcode 2094 ( Finding the three digits of even number )

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// first we solve using set but here is element is repeating
// thats why we solve using map and using frequecy count

vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto ele : digits){
            mp[ele]++;
        }
        for(int i=100; i<=999; i+=2){
            int x = i;
            int a = x%10;
            x /= 10;
            int b = x%10;
            x /= 10;
            int c = x;
            if(mp.find(a) != mp.end()){
                mp[a]--;
                if(mp[a] == 0) mp.erase(a);
                if(mp.find(b) != mp.end()){
                    mp[b]--;
                    if(mp[b] == 0) mp.erase(b);
                 if(mp.find(c) != mp.end())
                    ans.push_back(i);
                    mp[b]++;
                }
                mp[a]++;
            }
     
        }
        return ans;
    }

    int main(){

        return 0;
    }