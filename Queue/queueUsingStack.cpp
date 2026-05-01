// Leetcode 232 ( Implementing Queue using stack )

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class MyQueue {
public:
    stack<int> st;
    stack<int> helper;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop()  { 
        // remoivng from the front                
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        helper.pop();
        while(helper.size() > 0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() {      
        // retrive front of the queue           
        while(st.size() > 0){
            helper.push(st.top());
            st.pop();
        }
        int x = helper.top();
        while(helper.size() > 0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {
        if(st.size() == 0) return true;
        else return false;
    }
};


int main(){


    return 0;
}
