#include<iostream>
#include<stack>
using namespace std;

void displayrec(stack<int>& st){
    if(st.size() == 0){
        return ;
    }
    int x = st.top();
    cout << x << " ";
    st.pop();
    displayrec(st);
    st.push(x);
    cout << endl;
}


int main (){
stack<int> st;
st.push(10);
st.push(20);
st.push(30);
st.push(40);
displayrec(st);
cout << st.size() << endl;

// printing the element of the stack but stack get also empty
// while(st.size() > 0){
//     cout << st.top() << " ";
//     st.pop();
// }

// printing the element of the stack and putback to the stack
stack<int> temp;
while(st.size() > 0){
    cout << st.top() << " ";
    int x = st.top();
    st.pop();
    temp.push(x);
}
while(temp.size() > 0){
    int x = temp.top();
    temp.pop();
    st.push(x);
}

// printing the element of the stack in same order

stack<int> temp2;
// psuhing all the element on other stack

while(st.size() > 0){
    int x = st.top();
    temp2.push(x);
    st.pop();
}
cout << endl;
// now print the element of the stack while poping and psuhing into the original stack
while(temp2.size() > 0){
    cout << temp2.top() << " ";
    int x = temp2.top();
    temp2.pop();
    st.push(x);
}
//we can also do the above task by using 3 stack


    return 0;
}  