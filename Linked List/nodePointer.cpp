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

// display function 

void Display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


// display using recursion

void Displayrec(Node* head){
    if(head == NULL) return;
    cout << head->val << " ";
    Displayrec(head->next);
}

// size function 

int size(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    return n;
}

// insert at end

void insertAtEnd(Node* head , int val){
    Node* t = new Node(val);
    while(head != NULL) head = head->next;
    head->next = t;
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30); 
    Node* d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;
    
    // Node* temp = a;
    // while(temp != NULL){
    //     cout << temp->val << " ";
    //     temp = temp->next;
    // }

    Display(a);
    cout << endl;
    Displayrec(a);
    cout << size(a);

    insertAtEnd(a,80);

    Display(a);
    
    return 0;
}