/*Summary
Data Members
  Node *head
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
#include "SlNode.cpp"
using namespace std;

class List{
  Node *head;
  int l;

public:
  List(){
    head = NULL;
    l = 0;
  }
  List(int arr[],int s){
    head = new Node(arr[0]);
    l = s;
    Node *curr = head;
    for(int i=1;i<s;i++){

      curr->link(new Node(arr[i]));
      curr = curr->next();
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
    temp = temp->next();
    while(temp != NULL){
      cout << ", " << temp->get();
      temp = temp->next();
    }
    cout <<"]\n";
  }

  //returns last element of the list
  int pop(){
    return pop(l);
  }

  int pop(int i){
    if(i < l){
      Node* temp = head;
      int n = 0;
      while(--i > 0){
        temp = temp->next();
      }
      Node* x = temp->next();
      n = x->get();
      temp->link(x->next());
      delete x;
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
      Node *temp = head->next();
      delete head;
      head = temp;
    }
  }

  template<size_t s>
  void operator () (const int (&arr)[s]){
    head = new Node(arr[0]);
    l = s;
    Node *curr = head;
    for(int i=1;i<s;i++){
      curr->link(new Node(arr[i]));
      curr = curr->next();
    }
  }

  friend ostream& operator << (ostream &print,List &l){
    l.display();
    return print;
  }
  //clear memory
  ~List(){
    clear();
  }
};