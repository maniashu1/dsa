#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};


class DLL{
    public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head = tail = NULL;
         size = 0;
    }

// insertion at tail
void insertionAttail(int val){
    Node* temp = new Node(val); // creating a new node
    if(size == 0) head = tail = temp;
    else {
        tail->next = temp;
        temp->prev = tail;  // extra work for doubly linked list
        tail = temp;
    }
    size++;
}

// insertion at head
void insertionAthead(int val){
    Node* temp = new Node(val);
    if(size == 0) head = tail = temp;
    else {
        temp->next = head;
        head->prev = temp; // extra work
        head = temp;
    }
    size++;
}

// insrertion at index
void insertionAtidx(int idx , int val){
    if(idx < 0 || idx > size){
        cout << "Invalid index..." ;
    } else if(idx == 0) insertionAthead(val);
    else if(idx == size) insertionAttail(val);
    else {
       Node* t = new Node(val);
       Node* temp = head;
       for(int i=1; i<=idx-1; i++){
           temp = temp->next;
       }
       t->next = temp->next;
       temp->next = t;
       t->prev = temp;
       t->next->prev = t;
       size++;
    }
}

};



// display function
void Display(Node* head){
    while(head != NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Diplay in reverse order
void DisplayRev(Node* tail){
    while(tail != NULL){
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main(){
   Node* a = new Node(10);
   Node* b = new Node(20);
   Node* c = new Node(30);
   Node* d = new Node(40);
   Node* e = new Node(50);
   a->next = b;
   b->next = c;
   c->next = d;
   d->next = e;
   e->prev = d;
   d->prev = c;
   c->prev = b;
   b->prev = a;

   Display(a);
   DisplayRev(e);
    return 0;
}