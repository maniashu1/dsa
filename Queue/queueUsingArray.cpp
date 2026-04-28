#include<iostream>
using namespace std;

class Queue{
    public:
    int f;
    int b;
    int arr[5];
    Queue(){
        f = 0;
        b = 0;
    }
    
    // push function of queue
    void push(int val){
        if(b == 5) {
            cout << "Queue is full !!" << endl;
            return ;
        }
        arr[b] = val;
        b++;
    }

    // pop function of queue
    void pop(){
        if((b-f) == 0){
            cout << "Queue is empty !!" << endl;
            return;
        }
        f++;
    }
    
    // front function of queue
    int front(){
        if((b-f) == 0){
            cout << "Queue is empty !! " << endl;
            return -1;
        }
        return arr[f];
    }

    // back function of queue
    int back(){
        if((b-f) == 0){
            cout << "Queue is empty !! " << endl;
            return -1;
        }
        return arr[b-1];
    }

    // size function of queue
    int size(){
        return b-f;
    }

    // empty function of queue
    bool empty(){
        if((b-f) == 0){
            return true;
        } else {
            return false;
        }
    }
    
    // display function
    void display(){
        for(int i=f; i<b; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main(){

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    
    q.display();

    q.pop();

    q.display();

    cout << q.front() << endl;

    q.pop();

    cout << q.front() << endl;

    q.display();

    cout << q.size() << endl;

    cout << q.back() << endl;

    q.display();



    return 0;
}