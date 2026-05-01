// Leetcode 622 ( Design circular queue)

#include<iostream>
#include<vector>
using namespace std;

class MyCircularQueue {
public:
    int f = 0;
    int b = 0;
    int s = 0;
    int c = 0; // capacity
    vector<int> arr;
    MyCircularQueue(int k) {
        f = 0;
        b = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }
    
    bool enQueue(int value) {
        if(s == c){
            return false;
        } else {
            arr[b] = value;
            b++;
            if(b == c){
                b = 0;
            }
            s++;
        }
        return true;
    }
    
    bool deQueue() {
        if(s == 0) return false;
        f++;
        if(f==c) f = 0;
        s--;
        return true;
    }
    
    int Front() {
        if(s==0) return -1;
        return arr[f];
    }
    
    int Rear() {
        if(s==0) return -1;
        if(b==0) return arr[c-1];
        return arr[b-1];
    }
    
    bool isEmpty() {
        if(s==0) return true;
        else return false;
    }
    
    bool isFull() {
        if(s==c) return true;
        else return false;
    }
};


int main(){

    return 0;
}