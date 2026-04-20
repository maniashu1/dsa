#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }   
};

class LinkedList{
    public:
    Node* head;
    Node* tail;
    int size;
    LinkedList(){
        head = tail = NULL;
         size = 0;
    }

    // insertion at end 

    void insertAtEnd(int val){
        Node * temp = new Node(val);
        if(size == 0) head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // insertion at starting

    void insertAtBegining(int val){
        Node * temp = new Node(val);
        if(size == 0) head = tail = temp;
        else {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    
    // insertion at any index

    void insertionAtidx(int idx , int val){
        if(idx == 0) {
            insertAtBegining(val);
        } else if(idx == size){
            insertAtEnd(val);
        } else if(idx < 0 || idx > size){
            cout << "Invalid index ... enter a valid index" << endl;
        }
        Node* t = new Node(val);
        Node* temp = head;
        for(int i=0; i< idx - 1 ; i++){
            temp = temp->next;
        } 
        t->next = temp->next;
        temp->next = t;
        size++;
    }

    // Fetching element at any index

    int getEleAtidx(int idx){
        if(idx<0 || idx > size){
            cout << "Invalid index.." << endl;
            return -1;
        } else if(idx == 0){
             return head->val;
        } else if(idx == size){
            return tail->val;
        }
        Node* temp = head;
        for(int i=1; i<=idx; i++){
            temp = temp->next;
        }
        return temp->val;
    }

    // Display fubnction

    void Display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
     }
        cout << endl;
    }
};

int main(){

  LinkedList ll;

  ll.insertAtEnd(10);
  ll.Display();
  cout << ll.size << endl;

  ll.insertAtEnd(20);
  ll.Display();
  cout << ll.size << endl;

  ll.insertAtEnd(30);
  ll.Display();
  cout << ll.size << endl;

  ll.insertAtEnd(40);
  ll.Display();
  cout << ll.size << endl;

  ll.insertAtEnd(50);
  ll.Display();
  cout << ll.size << endl;

  ll.insertAtBegining(5);
  ll.Display();
  cout << ll.size << endl;

  ll.insertionAtidx(4,8);
  ll.Display();
  cout << ll.size << endl;

  int res = ll.getEleAtidx(4);
  cout << res << endl;

    return 0;
}