#include<iostream>
#include "./class/list/list.cpp"

using namespace std;


int main(){
    List<int> list;
    try{
    list.insert(3);
     list.deleteNode(3);
    list.insert(2);

    list.insert(4);
    list.insert(5);
   

    list.print();
    cout<<endl; 
    
    list.deleteNode(3);
    
    list.print(); 
    
    cout<<endl; 
     list.insert(8);
     list.print();
      }catch(...){
       cout<<"fallo";//utilicen un throw para identificar donde esta ubicado el error o usen el debugger
    }
    
}