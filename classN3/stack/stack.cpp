#include<iostream>
#include "./stack.h"

using namespace std;

//Comprobar si esta vacia

template<class T>
bool Stack<T>::isEmpty(){
    return this->head==NULL;
}

//Crea pila con nodo inicial, si se la pasa null la pila se crea inicializa vacia

template<class T>
Stack<T>::Stack(T data,Node<T>* node){

        Node <T> *newNode = new Node<T>(data,node);
        head=newNode;
        this->length++;
   
}

//Destructor, asegura que head quede sin apuntar a nada

template<class T>
Stack<T>::~Stack(){

        this->head = nullptr;
   
}

//Insertar nodo en tope
// 1. Crear nodo
// 2. Apuntar el nodo a head.
// 3. Apuntar head al nuevo nodo.
// 4. Aumentar el contador de la pila
template<class T>
void Stack<T>::push(T data){

        Node <T> *node = new Node<T>(data,head);
        head=node;
        this->length++;
   
}

//sacar nodo del tope de la cola (la acción elimina el nodo y recupera el dato)
// 1. Si la pila esta vacia se devuelve el valor por defecto del tipo de dato.
// 2. Creamos un nodo temporal a head.
// 3. Apuntamos head a su nodo siguiente.
// 4. Recuperamos el dato del nodo temporal (El que se va a sacar de la cola).
// 5. Liberamos memoria (delete node)
// 6. Reducimos tamaño de la cola
// 7. retornamos dato del nodo.

template<class T>
T Stack<T>::pop(){
         T data;
         if(isEmpty()) return data;
        Node <T> *node = head;
        head=head->getNext();
        data = node->getData();
        delete node;
        this->length--;
        return data;
}
template<class T>
void Stack<T>::print(){

      while(!isEmpty()) {

       std::cout<<pop()<<endl;
      }
}
template<class T>
int Stack<T>::getLength(){
    return this->length;
}