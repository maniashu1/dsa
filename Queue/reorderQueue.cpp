// reoreder queue ( interleaving 1st half and 2nd half of the queue) using only one stack

#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void display(queue<int>& q){
  int n = q.size();
  for(int i=0; i<n; i++){
    int x = q.front();
    cout << x << " ";
    q.pop();
    q.push(x);
  }
  cout << endl;
}

void reorder(queue<int>& q){

    stack<int> st;
    int n = q.size();

    // pushing first half into the stack while poping from queue
    for(int i=1; i<=n/2; i++){
        st.push(q.front());
        q.pop();
    }
    // now push back to the queue while poping from the stack
    while(st.size() > 0){
        q.push(st.top());
        st.pop();
    }
    // pushing second half into the stack while poping from queue
    for(int i=1; i<=n/2; i++){
        st.push(q.front());
        q.pop();
    }
    // now push the element into the queue alternately one from stack and one from front of the queue
    while(st.size() > 0){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    //  now reverse the entire queue
    while(q.size() > 0){
        st.push(q.front());
        q.pop();
    }
    while(st.size() > 0){
        q.push(st.top());
        st.pop();
    }
}

int main(){
     queue<int> q;
   
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    display(q);
    reorder(q);
    display(q);

    return 0;
}