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
 cout<<"Antes de borrar nodo con valor 7"<<endl;
 list.print();
    list.deleteNode(7);
cout<<"despues de borrar nodo con valor 7"<<endl;
  list.print();
 cout<<"Antes de borrar nodo con valor 5"<<endl;
 list.print();
list.deleteNode(5);
cout<<"despues de borrar nodo con valor 5"<<endl;
     list.print();

    list.update(2,2);
   cout<<"despues de actualizar nodo en posicion 2"<<endl;
    list.print();
    list.update(0,3);
   cout<<"despues de actualizar nodo en posicion 0"<<endl;
    list.print();

}