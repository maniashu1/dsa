
// Infix expression evalution using stack

#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch == '+' || ch == '-') return 1;
    else return 2;   // if ch = '*' and '/'
}

string solve(string val1 , string val2 , char ch){
      string s;
      s += val1;
      s += val2;
      s.push_back(ch);
      return s;
}

int main(){

  string s = "(7+9)*4/8-3";

  // we need two stack one for value and other for operator

  stack<string> val;
  stack<char> opr;

  for(int i=0; i<s.length(); i++){
    // checking if s[i] is a digit ( 0 - 9 )
    if(s[i] >= 48 && s[i] <= 57){
        val.push(to_string(s[i] - '0'));    // converting character and digit to string 
    } else if(opr.size() == 0 ) {opr.push(s[i]);} 
      else if(s[i] == '(') {opr.push(s[i]);}
      else if(opr.top() == '(') {opr.push(s[i]);}
      else if(s[i] == ')') {
        while(opr.top() != '('){
             char ch = opr.top();
                opr.pop();
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1,val2,ch);
                val.push(ans);
        }
            opr.pop();
      } else if(priority(s[i]) > priority(opr.top())) {opr.push(s[i]);}
          else {
            while(opr.size()>0 && priority(s[i]) <= priority(opr.top())){
                char ch = opr.top();
                opr.pop();
                string val2 = val.top();
                val.pop();
                string val1 = val.top();
                val.pop();
                string ans = solve(val1,val2,ch);
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
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1,val2,ch);
        val.push(ans);
    }

    cout << val.top();

    return 0;
}