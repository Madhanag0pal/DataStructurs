#include <iostream>
// #include <bits/stdc++.h>
#include <vector>

using namespace std;

template <typename T>
class list{
  vector<T> V;
  vector<T>::itrator be;
  int size;
public:
  list(T *arr=NULL, int s=0){
    size = 0;
    append(arr,s);
  }
  void append(T arr[],int s){
    int i=size;
    size += s;
    for(; i<size; i++){
      V.push_back();
    }
  }

  &ostream operator << (list l,&std::ostream print){
    return 
  }
  ~list(){
    cout << "list deleted\n"; 
  }
};

int main(){
  int arr[] = {1,2,3,4,5};
  list <int>l(arr,5);
  cout << "Hi\n";
  
}