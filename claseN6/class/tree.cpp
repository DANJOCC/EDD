#include "./tree.h"
template<class T>
 bool Tree<T>::isEmpty(){
    return root==NULL;
 }
template<class T>
void Tree<T>::insert( T data){
    root=insert(root,data);
};
template<class T>
Node<T>* Tree<T>::insert(Node<T> * node, T data){
    if(node==NULL){
        return new Node<T>(data,NULL,NULL);
    }else if(node->getData()>data){
        Node<T>* izq=insert(node->getChildren(0),data);
        node->setChildren(izq,NULL);
    }
    else if(node->getData()<data){
         Node<T>* der=insert(node->getChildren(1),data);
        node->setChildren(NULL,der);
    }
    return node;
};
template<class T>
void Tree<T>::print(int orden){
    switch (orden)
    {
    case 0:
        postOrden(root);
        break;
    case 1:
        inOrden(root);
        break;
    default:
        preOrden(root);
        break;
    }
};
template<class T>
void Tree<T>::postOrden(Node<T> *node){
    if(node==NULL) return;
   
    postOrden(node->getChildren(0));
    postOrden(node->getChildren(1));
    node->print();
}
template<class T>
void Tree<T>::inOrden(Node<T> *node){
    if(node==NULL) return;
    inOrden(node->getChildren(0));
    node->print();
    inOrden(node->getChildren(1));
    
}
template<class T>
void Tree<T>::preOrden(Node<T> *node){
    if(node==NULL) return;
    node->print();
    preOrden(node->getChildren(0));
    preOrden(node->getChildren(1));
}
