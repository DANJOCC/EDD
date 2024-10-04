#include <iostream>
#include "./list/list.cpp"
using namespace std;

int main(){
    List<int> myList(nullptr);

    myList.insert(3);
    myList.insert(5);
    myList.insert(1);
    myList.insert(2);
    
    myList.print();

    cout<<endl<<endl;

    myList.remove(5);
    myList.remove(1);
    
    myList.print();
}