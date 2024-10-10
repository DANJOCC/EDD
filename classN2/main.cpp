#include <iostream>
#include "./doubleLinkList/list/list.cpp"
using namespace std;

int main(){
    List<int> myList(nullptr);

    myList.insert(3);
    myList.insert(5);
    myList.insert(1);
    myList.insert(2);

    cout<<"Lista original"<<endl;

    myList.print();

    cout<<endl<<endl;

    myList.remove(5);
    myList.remove(1);
    cout<<"lista en orden despues de quitar 5 y 1"<<endl;
    myList.print();
    cout<<"lista en reversa despues de quitar 5 y 1"<<endl;
    myList.printReverse();
}