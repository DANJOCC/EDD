#include "./priorityQueue.h"

//Establece los niveles de prioridad
template<class T>
priorityQueue<T>::priorityQueue(int n){ 
    if(n>0){
        this->priorities=n;
        this->levels= new Queue<T>[n];
        return;
    }
    this->priorities=0;
    this->levels=new Queue<T>;

}

//inserta segun el nivel de prioridad
//se puede modificar para datos estructurados donde la prioridad se encuentre de manera interna en
//el dato estructurado.

template<class T>
void priorityQueue<T>::push(T data,int level){
    if(priorities==0){
        levels->push(data);
    }else{
        levels[level].push(data);
    }
}

//obtener/eliminar segun el nivel de prioridad solicitado


template<class T>
T priorityQueue<T>::pop(int level){
    T data;
     if(priorities==0){
        data=levels->pop();
    }else{
        data=levels[level].pop();
    }
    return data;
}

//Imprimir segun el nivel de prioridad solicitado

template<class T>
void priorityQueue<T>:: print(int level){
    if(priorities==0){
        levels->print();
    }else{
        levels[level].print();
    }
}
