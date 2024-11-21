#include "./tree.h"
enum ramas{IZQ,DER};
template<class T>
 bool Tree<T>::isEmpty(){
    return root==NULL;
 }

 template<class T>
 bool Tree<T>::isLeaf(Node<T>* Node){
    return Node->getChild(IZQ) == NULL && Node->getChild(DER) == NULL;
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
         
        Node<T>* izq=insert(node->getChild(IZQ), data);
       
        node->setLeft(izq);
       
    }
    else if(node->getData()<data){
         
         Node<T>* der=insert(node->getChild(DER),data);
        
        node->setRight(der);

     
    }
    return node;
};

template<class T>
void Tree<T>::insert_no_recursive(T data){
    
    if(root==NULL){

        root=new Node<T>(data,NULL,NULL);

    }
    else{
        Node<T>* actual = root;
        Node<T>* father = NULL;

        while(actual != NULL && data != actual->data){
            father = actual;
            if(actual->getData() > data){
                actual = actual->getChild(IZQ);
            }
            else{
                actual = actual->getChild(DER);
            }
        }

        if(actual != NULL) return;
        
        if(father->getData()> data){
            father->setLeft = new Node(data, NULL, NULL);
        }
        else{
            father->setRight = new Node(data, NULL, NULL);
        }
    }
}

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

        Node<T>* izq=eliminate(node->getChild(IZQ),data);

        node->setLeft(izq);
    }

    else if(node->getData()<data){

         Node<T>* der=eliminate(node->getChild(DER),data);
        
        node->setRight(der);
    }
    else{ //nodo encontrado

        Node<T>* eliminateNode=node;
        
        if(eliminateNode->getChild(IZQ)==NULL){
            node=eliminateNode->getChild(DER);
        }

        else if (eliminateNode->getChild(DER)==NULL){

            node=eliminateNode->getChild(IZQ);
        }
        else{
            
            eliminateNode=replace(eliminateNode);
        }

        eliminateNode=NULL;
    }
    return node;
};

template<class T>
void Tree<T>::eliminate_no_recursive(T data){
    
    if(isEmpty()){
        return;
    }
    else{
        Node<T>* actual = root;
        Node<T>* father = NULL;
        Node<T>* temp = NULL;
        T aux;
        while(actual != NULL){
            if(actual->getData() == data){
                if(isLeaf(actual)){
                    if(father != NULL){
                        if(father->getChild(IZQ) == actual) father->setLeft(NULL);
                        else if(father->getChild(DER) == actual) father->setRight(NULL);
                    }
                    delete actual;
                    return;
                }
                else{
                    father = actual;
                    if(actual->getChild(DER)!=NULL){

                        temp = actual->getChild(DER);

                        while (temp->getChild(IZQ) != NULL)
                        {
                            father = temp;
                            temp = temp->getChild(IZQ);
                        }
                        
                    }
                    else{
                        temp = actual->getChild(IZQ);

                        while (temp->getChild(DER) != NULL)
                        {
                            father = temp;
                            temp = temp->getChild(DER);
                        }
                    }
                    aux = actual->getData();
                    actual->setData(temp->getData());
                    temp->setData(aux);
                    actual = temp;

                }
            }
            else{
                father = actual;
                if(actual->getData() > data){
                    actual = actual->getChild(IZQ);
                }
                else{
                    actual = actual->getChild(DER);
                }
            }
            
        }

    }
}

template<class T>
Node<T>* Tree<T>::replace(Node<T>* node){
        Node<T>* nodeA=node;
        Node<T>* nodeB=node->getChild(IZQ);
        
        while (nodeB->getChild(DER)!=NULL)
        {
            nodeA=nodeB;
            nodeB=nodeB->getChild(DER);
        }

        node->setData(nodeB->getData());

        if(nodeA==node){
            nodeA->setLeft(nodeB->getChild(IZQ));
        }else{
            nodeA->setRight(nodeB->getChild(IZQ));
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
   
    postOrden(node->getChild(0));
    postOrden(node->getChild(1));
    node->print();
}
template<class T>
void Tree<T>::inOrden(Node<T> *node){
    if(node==NULL) return;
    inOrden(node->getChild(0));
    node->print();
    inOrden(node->getChild(1));
    
}
template<class T>
void Tree<T>::preOrden(Node<T> *node){
    if(node==NULL) return;
    node->print();
    preOrden(node->getChild(0));
    preOrden(node->getChild(1));
}
