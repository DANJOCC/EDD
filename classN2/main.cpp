#include<iostream>
#include "./class/list/list.cpp"

using namespace std;

int main(){
    List<int> list;

    int x[6]={5,4,3,7,8,6};

  
   
    for (int i = 0; i <6; i++)
    {
        list.insert(x[i]);
    }

    list.print();

}