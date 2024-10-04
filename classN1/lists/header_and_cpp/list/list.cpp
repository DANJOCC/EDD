#include "list.h"
#include <iostream>
using namespace std;
template<class T>
List<T>::List(Node<T>* node){
    this->head=node;
}

template<class T>
bool List<T>::isEmpty(){
    return this->head == nullptr;
}

template<class T>
void List<T>::insertFirst(T data){
    if(isEmpty()){
        this->head = new Node<T>(data,nullptr);
        return;
    }
    Node<T>* temp = this->head;
    this->head = new Node<T>(data,temp);
    temp = nullptr;
}

template<class T>
void List<T>::insert(T data){
    if(isEmpty() || data<head->getData()){
       insertFirst(data);
       return;
    }

    Node<T> *newNode =new Node<T>(data,nullptr);
    Node<T> *actual = head;
    Node<T> *prev = nullptr;
      
    while(actual!=nullptr && actual->getData() < data) {
         prev = actual;
         actual = actual->getNext();
    }
      
    newNode->setNext(prev->getNext());
    prev->setNext(newNode);
}

template<class T>
bool List<T>::remove(T data){

   if(isEmpty()){
      return false;
   }

   Node<T>* NodeToDelete=head;

   Node<T>* prev=nullptr;

   
   while (NodeToDelete!=nullptr && NodeToDelete->getData()!=data)
   {
      prev=NodeToDelete;
      NodeToDelete=NodeToDelete->getNext();
   }

   if(NodeToDelete!=nullptr){
      if(prev==nullptr){
         head=NodeToDelete->getNext();
      }
      else{
         prev->setNext(NodeToDelete->getNext());
      }


      delete NodeToDelete;
      return true;
   }
   
   return false;
}

template<class T>
void List<T>::print(){
    Node<T>* actual = head;
    cout<<head<<endl;
    while (actual != nullptr)
    {
       actual->print();
       actual = actual->getNext();
    }
    
}


