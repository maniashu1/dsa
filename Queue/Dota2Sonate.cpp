
// Leetcode 649 ( Medium )  Dota2Sonate

#include<iostream>
#include<queue>
using namespace std;


string predictPartyVictory(string s) {
        queue<int> q;
        queue<int> r;
        queue<int> d;
        for(int i=0; i<s.length(); i++){
            q.push(i);
            if(s[i] == 'R'){
                r.push(i);
            } else {
                d.push(i);
            }
        }
        while(q.size() > 1){
            if(s[q.front()] == 'X'){
                q.pop();
            } else if(s[q.front()] == 'R'){
                // announce victory
                if(d.size() == 0) return "Radiant";
                else {      // take rights of next d
                    s[d.front()] = 'X';
                    d.pop();
                    q.push(q.front());
                    q.pop();
                    r.push(r.front());
                    r.pop();
                }
            }        // if(s[q.front()] == 'D')
                else if(s[q.front()] == 'D'){
                // announce victory
                if(r.size() == 0) return "Dire";
                else {      // take rights of next r
                    s[r.front()] = 'X';
                    r.pop();
                    q.push(q.front());
                    q.pop();
                    d.push(d.front());
                    d.pop();
                }
            }
            }
        if(s[q.front()] == 'R') return "Radiant";
        else return "Dire";
    }

int main(){

    return 0;
}