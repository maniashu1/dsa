#include<iostream>
using namespace std;

class Node{
  public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = next;
    }
};

class Stack{
    public:
    Node* head;
    int size;
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int val){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        size++;
    }

    void pop(){
        if(head == NULL){
            cout << "Stack is empty..";
            return ;
        }
        head = head->next;
        size--;
    }
     
    int top(){
         if(head == NULL){
            cout << "Stack is empty..";
            return  -1;
        }
         return head->val;
    }

    void display(){
        Node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){

    Stack st;
    cout << st.top() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    cout << st.size << endl;
    cout << st.top() << endl;
    st.display();


    return 0;
}