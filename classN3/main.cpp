#include <iostream>
#include "./queue/queue.cpp"
using namespace std;

int main(){
    Queue<char> miCola('A',nullptr);

    
    miCola.push('D');
    miCola.push('B');
    miCola.push('A');

    cout<<"Pila original"<<endl;

    
   miCola.print();

    cout<<endl<<endl;
    miCola.push('X');
    cout<<"Valor sacado: "<<miCola.pop()<<endl;
    miCola.push('Y');
    miCola.push('Z');

    cout<<"e"<<miCola.pop()<<endl;
    miCola.print();

    
}