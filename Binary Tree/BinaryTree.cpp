#include<iostream>
using namespace std;

class node{
	int val;
	node *parent,*left,*right;
public:
	node(int v = 0){
		val = v;
		parent = left = right = 0;
	}
	void setParent(node *x){parent = x;}
	void setLeft(node *x){left = x;}
	void setRight(node *x){right = x;}
	int getVal(){ return val;}
	node* getLeft(){return (left != 0)?left:0;}
	node* getRight(){return (right != 0)?right:0;}		
	void show(){
		cout << "  " << val << endl
			 << " / \\\n";
	}
	~node(){
		cout << val << " is distructed\n";
	}
};
class binaryTree{
	private:
		node *head;
	public:
		binaryTree(){
			head = 0;
		}
		bool insert(int val){
			node *n = new node(val);
			bool res = false;
			if(n){
				res = true;
				if(head == 0){
					head = n;
				}
				else{
					node *temp = head;
					if(head->getVal() < val){
						temp->setLeft(n);
					}
					else{
						temp->setRight(n);
					}
				}
			}
			else{
				cout << "Not enough memory";
			}
			return res;
		}

};