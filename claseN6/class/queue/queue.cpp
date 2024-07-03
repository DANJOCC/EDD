#include<iostream>
#include "./Queue.h"
template<class T>
bool Queue<T>::isEmpty(){
    return this->head==NULL;
}
template<class T>
void Queue<T>::push(T data){
       
        Node <T> *node = new Node<T>(data,NULL);
         if(isEmpty()){
            head=node;
            tail=node;
            this->length++;
            return;
        }
        tail->setNextNode(node);
        tail=node;
        this->length++;
   
}

template<class T>
T Queue<T>::pop(){
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
void Queue<T>::print(){

      while(!isEmpty()) {

       std::cout<<pop()<<endl;
      }
}
template<class T>
int Queue<T>::getLength(){
    return this->length;
}