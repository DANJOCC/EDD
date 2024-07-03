#include<iostream>
#include "./stack.h"
template<class T>
bool stack<T>::isEmpty(){
    return this->head==NULL;
}
template<class T>
void stack<T>::push(T data){

        Node <T> *node = new Node<T>(data,head);
        head=node;
        this->length++;
   
}

template<class T>
T stack<T>::pop(){
         T data;
         if(isEmpty()) return data;
        Node <T> *node = head;
        head=head->getNextNode();
        data = node->getData();
        delete node;
        this->length--;
        return data;
}
template<class T>
void stack<T>::print(){

      while(!isEmpty()) {

       std::cout<<pop()<<endl;
      }
}
template<class T>
int stack<T>::getLength(){
    return this->length;
}