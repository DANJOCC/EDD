#include "./tree.h"
enum ramas{IZQ,DER};
template<class T>
 bool Tree<T>::isEmpty(){
    return root==NULL;
 }

template<class T>
void Tree<T>::insert( T data){
    root=insert(root,data, this->height_changed);
};
template<class T>
Node<T>* Tree<T>::insert(Node<T> * node, T data, bool& height_changed){
    
    Node<T>* child = NULL;

    if(node==NULL){
        height_changed = true;
        return new Node<T>(data,NULL,NULL);
        
    }else if(node->getData()>data){
         
        Node<T>* izq=insert(node->getChildren(IZQ),data, height_changed);
       
        node->setChildren(NULL,izq);

        if(height_changed){
            switch (node->getFe())
            {
            case 1:
                node->setFe(0);
                height_changed = false;
                break;
            case 0:
                node->setFe(-1);
                break;
            case -1:
                child = node->getChildren(IZQ);
                if (child->getFe() == -1)
                {
                    //rotacion simple izquierda
                    
                    node=rotation_simple_izq(node,child);
                }
                else{
                    //rotacion doble derecha
                    
                    node=rotation_double_der(node,child);
                }
                break;
            }
        }
       
    }
    else if(node->getData()<data){
         
         Node<T>* der=insert(node->getChildren(DER),data,height_changed);
        
        node->setChildren(der,NULL);

        if(height_changed){
            switch (node->getFe())
            {
            case 1:
                child = node->getChildren(DER);
                if (child->getFe() == 1)
                {
                    //rotacion simple derecha
                   
                    node=rotation_simple_der(node,child);
                }
                else{
                    //rotacion doble izquierda
                    
                    node=rotation_double_izq(node,child);
                }
                break;
            case 0:
                node->setFe(1);
                break;
            case -1:
                node->setFe(0);
                height_changed = false;
                break;
            }
        }
     
    }
    return node;
};

template<class T>
void Tree<T>::eliminate( T data){
    root=eliminate(root,data, this->height_changed);
};

template<class T>
Node<T>* Tree<T>::eliminate(Node<T>* node, T data, bool& height_changed){
    Node<T>* child = NULL;
   if(node==NULL){
    return NULL;
   }
   
    if(node->getData()>data){
        Node<T>* izq=eliminate(node->getChildren(IZQ),data, height_changed);
       
        node->setLeft(izq);
        
         if(height_changed){
            switch (node->getFe())
            {
            case 1:
               child = node->getChildren(DER);

               cout<<child->getData()<<endl;
                if (child->getFe() == -1)
                {
                    //rotacion doble izquierda
                 
                    node=rotation_double_izq(node,child);
                   
                    
                }
                else{
                     //rotacion simple derecha
                   
                    node=rotation_simple_der(node,child);
                }
                
                break;
            case 0:
                node->setFe(1);
                break;
            case -1:
                node->setFe(0);
                height_changed = false;
                break;
            }
        }
    }
    else if(node->getData()<data){
         Node<T>* der=eliminate(node->getChildren(DER),data, height_changed);
        node->setRight(der);
        
        if(height_changed){
            switch (node->getFe())
            {
            case 1:
                node->setFe(0);
                height_changed = false;
            case 0:
                node->setFe(-1);
                break;
            case -1:
                child = node->getChildren(IZQ);
                if (child->getFe() == 1)
                {
                     //rotacion doble derecha
                   
                    node=rotation_double_der(node,child);
                   
                }
                else{
                    //rotacion simple derecha
                   
                    node=rotation_simple_izq(node,child);
                }
                break;
            }
        }

    }
    else{ //node encontrado
        height_changed = true;
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
void Tree<T>::insert_no_recursive(T data){
   Node<T>* father = NULL; 
   Node<T>* actual = root;  

    if(isEmpty()){
        root = new Node<T>(data, NULL, NULL);
        return;
    }

   while(actual!=NULL && data != actual->getData()) {  /* (3) */
      father = actual;
      if(data < actual->getData()) actual = actual->getChildren(IZQ);  /* (3-a) */
      else if(data > actual->getData()) actual = actual->getChildren(DER); /* (3-b) */
   }

   if(actual!=NULL) return;  //El data esta repetido
  
    actual = new Node<T>(data, NULL, NULL);

   if(data < father->getData()) { 
     
      father->setChildren(NULL,actual);
   }
   else{
    
      father->setChildren(actual,NULL);
  }
   calcHeight(root);
}

template<class T>
void Tree<T>::calcHeight(Node<T>* node){
    if(node == NULL){
        return;
    }
    node->setHeigth(
            max(node->calculate_Heigth(node->getChildren(IZQ)),
            node->calculate_Heigth(node->getChildren(DER))));
    calcHeight(node->getChildren(IZQ));
    calcHeight(node->getChildren(DER));
}

template<class T>
void Tree<T>::eliminate_no_recursive(T data){
   Node<T>* father = NULL; /* (1) */
   Node<T>* actual;
   Node<T>* node;
   T aux;

    if(isEmpty()) return;

   actual = root;
   while(actual != NULL) { /* Búsqueda (2) else implícito */
      if(data == actual->getData()) { /* (3) */
  
        if(actual->isLeaf()) { /* (3-a) */
            
            if(father != NULL){
               
               if(father->getChildren(DER) == actual) {
                
                father->setRight(NULL);  /* (3-a-ii) */
               
               }else if(father->getChildren(IZQ) == actual) { 
                
                father->setLeft(NULL); /* (3-a-iii) */
               }
               delete actual;
            }
            actual = NULL;
             calcHeight(root);
            return;
        }
        else { /* (3-b) */
            /* Buscar node */
            father = actual; /* (3-b-i) */
            if(actual->getChildren(DER) != NULL) {
               node = actual->getChildren(DER);
               while(node->getChildren(IZQ) != NULL) {
                  father = node;
                  node = node->getChildren(IZQ);
               }
            }
            else {
               node = actual->getChildren(IZQ);
               while(node->getChildren(DER) != NULL) {
                  father = node;
                  node = node->getChildren(DER);
               }
            }
            /* Intercambio */
            aux = node->getData(); /* (3-b-ii) */
            node->setData(actual->getData());
            actual->setData(aux); 
            actual = node;
        }
      }
      else {
         father = actual;
         if(data> actual->getData()) actual = actual->getChildren(DER); /* (4) */
         else if(data< actual->getData()) actual = actual->getChildren(IZQ); /* (5) */
      }
   }
  
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

template<class T>
Node<T>* Tree<T>::rotation_simple_izq(Node<T> *node, Node<T> *child ){

    node->setLeft(child->getChildren(DER));
    child->setRight(node);

    if(child->getFe() == -1){
        node->setFe(0);
        child->setFe(0);
    }
    else{
        node->setFe(-1);
        child->setFe(1);
    }
    return child;
}
template<class T>
Node<T>* Tree<T>::rotation_simple_der(Node<T> *node, Node<T> *child ){

    node->setRight(child->getChildren(IZQ));
    child->setLeft(node);

    if(child->getFe() == 1){
        node->setFe(0);
        child->setFe(0);
    }
    else{
        node->setFe(1);
        child->setFe(-1);
    }
    return child;
}

template<class T>
Node<T>* Tree<T>::rotation_double_izq(Node<T> *node, Node<T> *child ){


    Node<T>* grandChild = NULL;

    grandChild = child->getChildren(IZQ);
    node->setRight(grandChild->getChildren(IZQ));
    grandChild->setLeft(node);
  
    child->setLeft(grandChild->getChildren(DER));
      cout<<child->getChildren(DER)->getData()<<endl;
    grandChild->setRight(child);

    if(grandChild->getFe() == 1){
        node->setFe(-1);
       
    }
    else{
         node->setFe(0);
    }

    if(grandChild->getFe() == -1){
        child->setFe(1);
       
    }
    else{
         child->setFe(0);
    }
    grandChild->setFe(0);
    return grandChild;
}
template<class T>
Node<T>* Tree<T>::rotation_double_der(Node<T> *node, Node<T> *child ){


    Node<T>* grandChild = NULL;

    grandChild = child->getChildren(DER);
    node->setLeft(grandChild->getChildren(DER));
    grandChild->setRight(node);
    child->setRight(grandChild->getChildren(IZQ));
    grandChild->setLeft(child);
    

    if(grandChild->getFe() == 1){
        child->setFe(-1);
       
    }
    else{
         child->setFe(0);
    }

    if(grandChild->getFe() == -1){
       node->setFe(1);
       
    }
    else{
        node->setFe(0);
    }
    grandChild->setFe(0);
    return grandChild;
}