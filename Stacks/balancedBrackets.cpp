#include<iostream>
#include<stack>
using namespace std;

bool isbalanced(string s){
    // if string lenth is odd then it can never be a balanced paranthesis
    if(s.length() % 2 != 0) return false;
    stack<char> st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        } else if(st.size() == 0){
            return false;
        } else {
            st.pop();
        }
    }
    if(st.size() == 0) return true;
    else return false; 
}

int main(){
    string s = "{({{{[()]}}})}";
    cout << isbalanced(s);

    return 0;
}