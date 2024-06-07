#include<iostream>
#include "./list.h"
template<class T>
bool List<T>::isEmpty(){
    return this->head==NULL;
}
template<class T>
int List<T>::getLength(){
    return this->length;
}
template<class T>
void List<T>::insertFirst(Node<T> *node){

         //Ubicar el puntero de last al final de la lista circular

         Node<T> *actual = head->getNextNode();
         Node<T> *last = NULL;
      while(actual!=head) {
         last = actual;
         actual = actual->getNextNode();
      }

      //cambiar nodo apuntado por head por el nuevo
      //si el ultimo se mantuvo NULL, es porque solo existe el nodo apuntado por head
      if(last==NULL){
         head->setNextNode(node);
       
      }else{
         last->setNextNode(node);
       
        
      }

      node->setNextNode(head);
      head=node;
}

template<class T>
void List<T>::insert(T data){
    
    Node<T> *newNode =new Node<T>(data,NULL);
   // Si la lista está vacía, insertar al principio:
   if(isEmpty()) {
      
      // head sera el primero y el ultimo de la lista
       head=newNode;
       head->setNextNode(head);
    
   }
   else {

      //insertar primero si el valor del nodo apuntado por head es mayor
      if(head->getData()>=data){
         insertFirst(newNode);
         return;
      }

      Node<T> *actual = head->getNextNode();
      Node<T> *last = head;

      // Buscar el nodo anterior al primer nodo con un dato mayor qur 'data', se salta el nodo inicial
      //porque ya se evaluo

      while(actual!=head && actual->getData() < data) {
         last = actual;
         actual = actual->getNextNode();
      }

         //Si actual y last son iguales al primero nodo apuntado por head entonces solo existe un nodo en la lista
         //si no es el caso anterior, entonces es que se dio una vuelta en la lista
         //si tampoco es el caso, entonces el nodo se inserta en su posicion dentro de la lista circular
       if(actual==head  && last==head){
         head->setNextNode(newNode);
         newNode->setNextNode(head);
       }
       else if(actual==head){
         last->setNextNode(newNode);
         newNode->setNextNode(actual);
       }else{
        newNode->setNextNode(last->getNextNode());
        last->setNextNode(newNode);
       }
   }
   this->length++;
}

template<class T>
bool List<T>::deleteNode(T data){

   if(isEmpty()){
      return false; 
   }
   
   //si solo hay un nodo apuntados head a NUll y el siguiete tambien
   if(length==1){
      head->setNextNode(NULL);
      
       head=NULL;
       return true;
   }
      Node<T>* last=head; // last apunta al nodo apuntado por head


      Node<T>* NodeToDelete=head->getNextNode(); // NodeToDelete apunta al nodo siguiente al apuntado por head

   while (head!=NodeToDelete && NodeToDelete->getData()!=data) //recorremos la lista hasta encontrar el nodo a eliminar
   {
      last=NodeToDelete;
      NodeToDelete=NodeToDelete->getNextNode();
   }

   /*
      Si el nodo aborrar es igual al apuntado a head, lo mismo para su dato. entonces apuntamos head al siguiente
      al que se va a borrar. En caso de que se halla dado una vuelta sin encontrar el valor a borrar, no se borra nada.

   */
   if(NodeToDelete==head && NodeToDelete->getData()==data){
      
         head=NodeToDelete->getNextNode();
         
   }
   else if(NodeToDelete==head){
         return false;
   }
     
   //si el primer caso se cumple o no, el siguiente al ultimo sera el siguiente del que se va a borrar
   last->setNextNode(NodeToDelete->getNextNode());

      delete NodeToDelete;
      this->length--;
      return true;
   
   
   return false;
}
template<class T>
bool List<T>::update(int n, T data){
   if(isEmpty() || n > this->length){
      return false;
   }
   Node<T> *nodeToUpdate = head;
   Node<T> *last = NULL;
    Node<T> *next = NULL;

   for (int i = 0; i < n; i++)
   {
      last=nodeToUpdate;
      nodeToUpdate=nodeToUpdate->getNextNode();
   }


   T oldData= nodeToUpdate->getData();
   next=nodeToUpdate->getNextNode();
   T nextData;
   T lastData;
   if(next==NULL){
      
      lastData=last->getData();
      if(lastData>data){
         deleteNode(oldData);
         insert(data);
         
      }else{
         nodeToUpdate->setData(data);
      }
      return true;
   }

   if(last==NULL){
      nextData=next->getData();
      if(nextData<data){
         deleteNode(oldData);
         insert(data);
         
      }else{
               nodeToUpdate->setData(data);
      }

      return true;
   }

   lastData=last->getData();
   nextData=next->getData();

   if(lastData<=data && data<=nextData){
      nodeToUpdate->setData(data);
    
     
   }else{
   
      deleteNode(oldData);
      insert(data);
   
   }
  
   return true;
}
template<class T>
void List<T>::print(){
    
      head->print();
   Node <T> *actual = head->getNextNode();
      while(actual!=head) {
        actual->print();
        actual = actual->getNextNode();
      }
}