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

int main(){
	// binaryTree b;
	// int i = 1; 
	// while(i != 0){
	// 	cin >> i;
	// 	b.insert(i);  
	// }
	node *n = new node(7),*l = new node(5),*r = new node(9);
	cout << sizeof(n)<<endl;
	n->setRight(r);
	n->show();
	delete n;
	delete l;
	delete r;
}