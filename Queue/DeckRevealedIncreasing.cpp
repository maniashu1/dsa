// Leetcode 950 ( medium ) Deck reveal increasing 

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin() , deck.end());
        vector<int> ans(n);
        queue<int> q;
        for(int i=0; i<n; i++){
            q.push(i);
        }
        for(int i=0; i<n; i++){
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            //poping front and pushing it to the back
            q.push(q.front());
            q.pop();
        }
        return ans;
    }

int main(){

    return 0;
}