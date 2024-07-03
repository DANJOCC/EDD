#include "./priorityQueue.h"

template<class T>
priorityQueue<T>::priorityQueue(int n){
    if(n>0){
        this->levels=n;
        this->array= new Queue<T>[n];
        return;
    }
    this->levels=0;
    this->array=new Queue<T>;

}
template<class T>
void priorityQueue<T>::push(T data,int level){
    if(levels==0){
        array->push(data);
    }else{
        array[level].push(data);
    }
}
template<class T>
T priorityQueue<T>::pop(int level){
    T data;
     if(levels==0){
        data=array->pop(data);
    }else{
        data=array[level].pop(data);
    }
    return data;
}
template<class T>
void priorityQueue<T>:: print(int level){
    if(levels==0){
        array->print();
    }else{
        array[level].print();
    }
}
