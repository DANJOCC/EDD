#include<iostream>
#include "./stack/stack.cpp"

using namespace std;

int main(){
    stack<int> list;

    int x[6]={5,4,3,7,8,6};

  
   
    for (int i = 0; i <6; i++)
    {
        list.push(x[i]);
    }
    cout<<list.getLength()<<endl;
 
    list.print();
    cout<<list.getLength()<<endl;
 

}