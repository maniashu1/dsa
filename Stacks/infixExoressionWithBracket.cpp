
// Infix expression evalution using stack

#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;   // if ch = '*' and '/'
}

int solve(int val1 , int val2 , char ch){
    if(ch == '+') return val1 + val2;
    else if(ch == '-') return val1 - val2;
    else if(ch == '*') return val1 * val2;
    else return val1 / val2;
}


int main(){

  string s = "(2+6)*4/8-3";

  // we need two stack one for value and other for operator

  stack<int> val;
  stack<char> opr;

  for(int i=0; i<s.length(); i++){
    // checking if s[i] is a digit ( 0 - 9 )
    if(s[i] >= 48 && s[i] <= 57){
        val.push(s[i] - '0');    // converting character to integer before pushing 
    } else if(opr.size() == 0 ) {opr.push(s[i]);} 
      else if(s[i] == '(') {opr.push(s[i]);}
      else if(opr.top() == '(') {opr.push(s[i]);}
      else if(s[i] == ')') {
        while(opr.top() != '('){
             char ch = opr.top();
                opr.pop();
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = solve(val1,val2,ch);
                val.push(ans);
        }
            opr.pop();
      } else if(priority(s[i]) > priority(opr.top())) {opr.push(s[i]);}
          else {
            while(opr.size()>0 && priority(s[i]) <= priority(opr.top())){
                char ch = opr.top();
                opr.pop();
                int val2 = val.top();
                val.pop();
                int val1 = val.top();
                val.pop();
                int ans = solve(val1,val2,ch);
                val.push(ans);
            }
            opr.push(s[i]);
        }     
    }
  
    // the operator stack can have value
    // so make it empty
  
    while(opr.size() > 0){
        char ch = opr.top();
        opr.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1,val2,ch);
        val.push(ans);
    }

    cout << val.top();

    return 0;
}