/*Summary
Data Members
  Node *head,*tail
  int len

Costructures
  List() -> head =NULL,len=0
  List(int[],int) -> creats an list and sets the length

Member Function
  int <- len()  // returns length of the list
  void <- display() //prints the list
  void <- append(int n) // inserts n at end of the list
  int <- pop(int i)  //returns the element at index i of the list
  int <- pop()  //returns last element of the list
  void <- clear() //deletes all nodes in the list
Disructor
  ~List() //clear all Node in the 
  --------------------------------------------
  
*/

#include<iostream>
#include "DlNode.cpp"
using namespace std;

class DlList{
  Node *head,*tail;
  int l;

public:
  DlList(){
    head = NULL;
    l = 0;
  }
  DlList(int arr[],int s){
    head = new Node(arr[0]);
    l = s;
    Node *curr = head;
    for(int i=1;i<s;i++){
      tail = new Node(curr,arr[i]);
      if(tail != NULL){
        curr->linkNext(tail);
        curr = curr->nextAddress();
      }
      else{
        cout << "Error! Memory is full";
        exit(0);
      }
    }
  }

  // returns length of the list
  int len(){
    return l;
  }

  //prints the list
  void display(){
    Node* temp = head;
    cout <<"[" << temp->get();
    temp = temp->nextAddress();
    while(temp != NULL){
      cout << ", " << temp->get();
      temp = temp->nextAddress();
    }
    cout <<"]\n";
  }

  //returns last element of the list
  int pop(){
    return pop(l-1);
  }

  //returns last element at ith element
 int pop(int x){
    if(0 <= x && x < l){
      Node* temp = head;
      int n = 0;
      while(--x){
        temp = temp->nextAddress();
      }
      //p to be poped, temp = previous node
      Node* p = temp->nextAddress();
      n = p->get();
      temp->linkNext(p->nextAddress());
      p->nextAddress()->linkPre(temp);
      delete p;
      l--;
      return n;
    }
    else{
      cout << "Index out of bund\n";
      exit(0);
    }
  }
  
  //deletes all nodes in the list
  void clear(){
    while(head != NULL){
      Node *temp = head->nextAddress();
      delete head;
      head = temp;
    }
  }
  int operator [] (int i){
    if(0<=i && i<l){
      Node *temp = head;
      while(i--){
        temp = temp->nextAddress();
      }
      return temp->get();
    }
    else{
      cout << "Error Index out of bund\n";
      exit(0);
    }
  }
  template<size_t s>
  void operator () (int (&arr)[s]){
    if(s>0){
      head = new Node(arr[0]);
      l = s;
      Node *curr = head;
      for(int i=1;i<s;i++){
        tail = new Node(curr,arr[i]);
        if(tail != NULL){
          curr->linkNext(tail);
          curr = curr->nextAddress();
        }
        else{
          cout << "Error! Memory is full";
          exit(0);
        }
      }
    }
  }

  DlList operator () (int b,int e){
    
  } 

  friend ostream& operator << (ostream &print,DlList &l){
    l.display();
    return print;
  }
  //clear memory
  ~DlList(){
    clear();
  }
};