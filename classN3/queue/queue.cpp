#include<iostream>
#include "./queue.h"

using namespace std;

//Comprobar si esta vacia

template<class T>
bool Queue<T>::isEmpty(){
    return this->head==NULL;
}

//Crea cola con nodo inicial, si se la pasa null la cola se crea inicializa vacia

template<class T>
Queue<T>::Queue(T data,Node<T>* node){

        Node <T> *newNode = new Node<T>(data,node);
        head=newNode;
        tail=head;
        this->length++;
   
}

//Destructor, asegura que head y tail queden sin apuntar a nada

template<class T>
Queue<T>::~Queue(){

        this->head = nullptr;
        this->tail = nullptr;
}

//Insertar nodo en tope
// 1. Crear nodo
//      1.1. Si la cola esta vacia, head y tail apuntan al mismo nodo
//        (el error de la clase estaba que se me olvido colocar el
//          return para que no siguiera con el resto del codigo)
// 2. Apuntar el siguiente de tail al nuevo nodo
// 3. Apuntar tail al nuevo nodo.
// 4. Aumentar el contador de la cola
template<class T>
void Queue<T>::push(T data){

        Node <T> *node = new Node<T>(data,nullptr);
        if(isEmpty()){
                head = node;
                tail = node;
                return;
        }
        this->tail->setNext(node);
        this->tail=node;
        this->length++;
}

//sacar nodo del inicio de la cola (la acción elimina el nodo y recupera el dato)
// 1. Si la cola esta vacia se devuelve el valor por defecto del tipo de dato.
// 2. Creamos un nodo temporal a head.
// 3. Apuntamos head a su nodo siguiente.
// 4. Recuperamos el dato del nodo temporal (El que se va a sacar de la cola).
// 5. Liberamos memoria (delete node)
// 6. Reducimos tamaño de la cola
// 7. retornamos dato del nodo.

template<class T>
T Queue<T>::pop(){
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
void Queue<T>::print(){

      while(!isEmpty()) {

       std::cout<<pop()<<endl;
      }
}

template<class T>
int Queue<T>::getLength(){
    return this->length;
}