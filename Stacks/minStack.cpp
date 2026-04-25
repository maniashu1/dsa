
// Leetcocde -> 155 medium ( Min Stack)

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() { min = LLONG_MAX; }

    void push(long long val) {
        if (st.size() == 0) {
            st.push(val);
            min = val; // if only one element is present
        } else if (val >= min)
            st.push(val);
        else { // if val less than min
            st.push(2 * val - min);
            min = val;
        }
    }

    void pop() {
        if (st.top() >= min)
            st.pop();
        else { // st.top() < min : a fake value is present  // before poping
               // make sure to retrive the old min and update the oldd minm to
               // current min
            long long oldMin = 2 * min - st.top();
            min = oldMin;
            st.pop();
        }
    }

    long long top() {
        if (st.top() < min)
            return min;
         else return st.top();
    }

    long long getMin() { return min; }
};


int main(){


    return 0;
}
