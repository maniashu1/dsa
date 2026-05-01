#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseKelement(queue<int>& q , int k){
    int n = q.size();
    stack<int> st;
    // pushing first k element to to stack
    for(int i=1; i<=k; i++){
        int x = q.front();
        st.push(x);
        q.pop();
    }
    // now pop element from the stack and push into the queue
    int m = st.size();
    for(int i=1; i<=m; i++){
        int y = st.top();
        q.push(y);
        st.pop();
    }
    
    for(int i=1; i<=n-k; i++){
        int z = q.front();
        q.push(z);
        q.pop();
        
    }
}

void display(queue<int>& q){
    for(int i=0; i<q.size(); i++){
       int x = q.front();
       cout << x << " ";
        q.pop();
        q.push(x);
    }
    cout << endl;
}

int main(){
   
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    int k;
    cout<< "Enter the value of k :" ;
    cin >> k;
    
    display(q);

    reverseKelement(q,k);

    display(q);

    return 0;
}