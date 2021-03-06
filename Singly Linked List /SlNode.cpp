/*Summary
Data member
  int data
  Node *nextAddress

Costructures
  Node() -> data=0,nextAddress=NULL
  Node(int v) -> data=v,nextAddress=NULL
  Node(Node* n) -> data=0,nextAddress=n
  Node(int v,Node* n) -> data=v,nextAddress=n

Member Function
  int <- get() //returns value fo the node 
  void <- set(int n) //sets value of the node
  Node* <- next() //returns next node address
  void <- link(Node*n) //links with the given node
*/

#include <iostream>

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