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

// Doubly linked list class
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

// Delete at head
void deleteAthead(){
    if(size == 0){
        cout <<"List is empty..";
        return;
    } else {
        head = head->next;
        if(head) head->prev = NULL; // Checking if head != null then only head->prev should be maked null
        if(head==NULL) tail = NULL;
        size--;
     }
}

// Delete at Tail
void deleteAttail(){
    if(size == 0){
        cout << "List is empty..";
        return;
    } else {
        Node* temp = tail->prev;
        temp->next = NULL;
        tail = temp;
        size--;
    }
}

// Delet at any index
void deleteAtidx(int idx ){
    if(size == 0){
        cout << "List is empty..";
        return;
    } else if(idx<0 || idx > size) {
        cout << "Invalalid index...";
        return;
    } else if(idx == 0){
       return  deleteAthead();
    } else if(idx == size-1){
       return  deleteAttail();
    } else {
        Node* temp = head;
       for(int i=1; i<=idx-1; i++){
          temp = temp->next;
       }
       temp->next = temp->next->next;
       temp->next->prev = temp;
       size--;
    }
}

// Get at index
int getAtidx(int idx){
   if(size == 0){
    cout << "List is empty..";
    return -1;
   }
   else if(idx < 0 || idx > size){
    cout << "Invalid index...";
    return -1;
   }
   else if(idx == 0){
    return head->val;
   } else if(idx == size-1){
    return tail->val;
   }else {
    Node* temp = head;
    for(int i=0; i<=idx-1; i++){
        temp = temp->next;
    }
     return temp->val;
   }
}

// display function
void Display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

};



// Diplay in reverse order
void DisplayRev(Node* tail){
    while(tail != NULL){
        cout << tail->val << " ";
        tail = tail->prev;
    }
    cout << endl;
}

int main(){

 DLL list ;
 
 list.insertionAttail(10);
 list.insertionAttail(20);
 list.insertionAttail(30);
 list.insertionAttail(40);
 list.Display();
 list.insertionAttail(50);
 list.Display(); 
 list.insertionAthead(60);
 list.Display();
 list.insertionAtidx(3,80);
 list.Display();
 list.deleteAthead();
 list.Display();
 list.deleteAttail();
 list.Display();
 list.deleteAtidx(3);
 list.Display();
 int res = list.getAtidx(2);
 cout << res << endl;
 list.Display();
    return 0;
}