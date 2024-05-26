#include<iostream>
#include "./list.h"
template<class T>
bool List<T>::isEmpty(){
    return this->head==NULL;
}
template<class T>
void List<T>::insertFirst(Node<T> *node){
        Node <T> *temp = head;
        head=node;
        head->setNextNode(temp);
}

template<class T>
void List<T>::insert(T data){
    Node <T> *actual = head;
    Node<T> *last = NULL;
    Node<T> *newNode =new Node<T>(data,NULL);
   // Si la lista está vacía, insertar al principio:
   if(isEmpty()) {
        insertFirst(newNode);
   }
   else {
      // Buscar el nodo anterior al primer nodo con un dato mayor qur 'dat'
      while(actual!=NULL && actual->getData() < data) {
         last = actual;
         actual = actual->getNextNode();
      }
      // Si no hay anterior, insertar al principio,
      // nuestro valor es el menor de la lista:
      if(last==NULL){
         insertFirst(newNode);
      }
      else{ // Insertar:
        newNode->setNextNode(last->getNextNode());
        last->setNextNode(newNode);}
   }
}
template<class T>
void List<T>::print(){
     Node <T> *actual = head;
  
      while(actual!=NULL) {
        actual->print();
        actual = actual->getNextNode();
      }
}