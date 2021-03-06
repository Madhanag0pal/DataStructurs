/* Summary
Data member
int data;
Node *pre,*next;

Constructors
  Node *n = new Node();->pre=NULL,data=0,next=NULL
  Node *n = new Node(10);->pre=NULL,data=10,next=NULL
  Node *n1 = new Node(10,&n2);->pre=NULL,data=10,next=n2
  Node *n2 = new Node(&n1,10);->pre=n1,data=10,next=NULL
  Node *n2 = new Node(&n1,10,&n3);->pre=n1,data=10,next=n3

Member function
  int get() //returns value fo the node
  void set(int n) //sets value to the node
  Node* nextAddress() //returns next node address
  Node* preAddress() //returns previous node address
  void linkNext(Node*n) //links next node with the given node
  void linkPre(Node*n) //links pre node with the given node  
*/

#include<iostream>
using namespace std;

class Node{
  int data;
  Node *pre,*next;

public:
  Node(int d,Node* n=NULL){
    pre = NULL;
    data=d;
    next=n;
  }
  Node(Node*p,Node*n){
    pre = p;
    data=0;
    next=n;
  }
  Node(Node *p=NULL,int d=0,Node *n=NULL){
    pre = p;
    data= d;
    next= n;
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
  Node* nextAddress(){
    return next;
  }

  //returns previous node address
  Node* preAddress(){
    return pre;
  }

  //links with the given node
  void linkNext(Node*n){
    next = n;
  }

  void linkPre(Node*n){
    pre = n;
  }

  ~Node(){
    // cout << data << "\t";
  }
};