#include "./tree.h"
enum ramas{IZQ,DER};
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
         
        Node<T>* izq=insert(node->getChildren(IZQ),data);
       
        node->setChildren(NULL,izq);
       
    }
    else if(node->getData()<data){
         
         Node<T>* der=insert(node->getChildren(DER),data);
        
        node->setChildren(der,NULL);

     
    }
    return node;
};
template<class T>
void Tree<T>::eliminate( T data){
    root=eliminate(root,data);
};
template<class T>
Node<T>* Tree<T>::eliminate(Node<T>* node, T data){
   if(node==NULL){
    return NULL;
   }
    if(node->getData()>data){
        Node<T>* izq=eliminate(node->getChildren(IZQ),data);
        node->setChildren(NULL,izq);
    }
    else if(node->getData()<data){
         Node<T>* der=eliminate(node->getChildren(DER),data);
        node->setChildren(der,NULL);
    }
    else{ //nodo encontrado
        Node<T>* eliminateNode=node;
        if(eliminateNode->getChildren(IZQ)==NULL){
            node=eliminateNode->getChildren(DER);
        }
        else if (eliminateNode->getChildren(DER)==NULL){
            node=eliminateNode->getChildren(IZQ);
        }else{
            eliminateNode=replace(eliminateNode);
        }
        eliminateNode=NULL;
    }
    return node;
};
template<class T>
Node<T>* Tree<T>::replace(Node<T>* node){
        Node<T>* nodeA=node;
        Node<T>* nodeB=node->getChildren(IZQ);
        
        while (nodeB->getChildren(DER)!=NULL)
        {
            nodeA=nodeB;
            nodeB=nodeB->getChildren(DER);
        }
        node->setData(nodeB->getData());

        if(nodeA==node){
            nodeA->setChildren(NULL,nodeB->getChildren(IZQ));
        }else{
            nodeA->setChildren(nodeB->getChildren(IZQ),NULL);
        }
        return nodeB;
        
}
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
