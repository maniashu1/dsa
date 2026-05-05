// Leetcode 735 ( Asteroid collision ) medium

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& ast) {

        stack<int> st;

        for (int i = 0; i < ast.size(); i++) {
            bool destroyed = false;

            while (!st.empty() && ast[i] < 0 && st.top() > 0) {
                if (abs(ast[i]) > st.top()) {
                    st.pop();
                } else if (abs(ast[i]) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(ast[i]);
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

int main(){

    return 0;
}