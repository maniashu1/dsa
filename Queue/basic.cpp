
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

// Display function to print the element of the queue
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

// reverse the queue using stack
void Reverse(queue<int>& q){
    int n = q.size();
    stack<int> st;
    for(int i=0; i<n; i++){
        int x = q.front();
        st.push(x);
        q.pop();
    }
    for(int i=0; i<n; i++){
        int y = st.top();
        q.push(y);
        st.pop();
    }
    cout << endl;
}


int main(){
    queue<int> q;
    // push , pop , size , back , front etc....
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << q.front() << endl;
    cout << q.size() << endl;

    display(q);

    Reverse(q);

    display(q);

    Reverse(q);

    display(q);

    return 0;
}