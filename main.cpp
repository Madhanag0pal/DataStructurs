#include <iostream>
using namespace std;
// #include "SlList"

class Node{
  int data;
  Node* nextAddress;

public:
  Node(Node*n){
    data=0;
    nextAddress=n;
  }
  Node(int v = 0,Node*n = NULL){
    data=v;
    nextAddress=n;
  }

  //returns value fo the node
  int get(){
     return data;
  }

  //sets value of the node
  void set(int n){
    data = n;
  }

  //returns next node address
  Node* next(){
    return nextAddress;
  }

  //links with the given node
  void link(Node*n){
    nextAddress = n;
  }

  ~Node(){
    //cout << data << '\t';
  }
};

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
    int n = 0;
    if(i < l){
      Node* temp = head;
      while(--i > 0){
        temp = temp->next();
      }
      Node* x = temp->next();
      n = x->get();
      temp->link(x->next());
      delete x;
      l--;
    }
    else{
      cout << "Index out of bund\n";
    }
    return n;
  }
};

int main(){
  int arr[] = {1,2,3,4};
  List l(arr,3);
  l.display();
  l.pop();
  cout << l.len() << endl;
  l.display();
}
