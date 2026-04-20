#include<iostream>
#include<stack>
using namespace std;

void display(stack<int> st){
     while(st.size() > 0){
        cout << st.top() << " ";
        st.pop();
     }
     cout << endl;
}

// psuh at bottom 
void pushAtbottom(stack<int>& st , int val){
    stack<int> temp;
    while(st.size() > 0){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
}

// push at any index

void pushAtindex(stack<int>& st , int idx , int val){
    stack<int> temp;
    while(st.size() > idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
}

int main (){

stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);

display(st);

pushAtbottom(st,80);

display(st);

pushAtindex(st,2,90);

display(st);

    return 0;
}  