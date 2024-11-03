#include <iostream>
#include "./class/priorityQueue/priorityQueue.cpp"
using namespace std;

int main(){
    priorityQueue<int> miCola(3); //Cola de prioridad con tres niveles de prioridad

    
    miCola.push(2, 0);
    miCola.push(1, 0);
    miCola.push(7, 0);


    miCola.push(2, 1);
    miCola.push(7, 1);
    miCola.push(4, 1);

    miCola.pop(1);

    miCola.push(2, 2);

    cout<<"Valores de prioridad 0"<<endl;

    
    miCola.print(0);

    cout<<endl<<endl;

     cout<<"Valores de prioridad 1"<<endl;
   
    miCola.print(1);

     cout<<endl<<endl;

     cout<<"Valores de prioridad 2"<<endl;

    
    miCola.print(2);

    cout<<endl<<endl;


    priorityQueue<int> miCola2(0); //Cola de prioridad con un solo nivel de prioridad

    //No importa que par de valores especifiquemos siempre se almacenan los datos en un solo nivel de prioridad
    
    miCola2.push(2, 0);
    miCola2.push(1, 0);
    miCola2.push(7, 0);


    miCola2.push(2, 1);
    miCola2.push(7, 1);
    miCola2.push(4, 1);

    miCola2.pop(1);

    miCola2.push(2, 2);

    cout<<"Valores"<<endl;

    
    miCola2.print(55);
    
}