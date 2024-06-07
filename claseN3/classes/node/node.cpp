#include<iostream>
#include "./node.h"
using namespace std;

template <class T>
Node<T>::Node(T data, Node<T>* next, Node<T>* back){
    this->data=data;
    if(next!=NULL && back!=NULL){
        this->next=next;
        this->back=back;
    }
    else if(next==NULL &&  back!=NULL){
        this->back=back;
    }else if(next!=NULL &&  back==NULL){
        this->next=next;
    }
}
template <class T>
Node<T>* Node<T>::getNextNode(){
    return this->next;
}

template <class T>
void Node<T>::setNextNode(Node<T>* next){
     if(next!=NULL){
        this->next=next;
    }
}

template <class T>
Node<T>* Node<T>::getBackNode(){
    return this->back;
}

template <class T>
void Node<T>::setBackNode(Node<T>* back){
     if(back!=NULL){
        this->back=back;
    }
}

template <class T>
void Node<T>::setData(T data){
    this->data=data;
}


template <class T>
T Node<T>::getData(){
   return this->data;
}


template<class T>
void Node<T>::print(){
    cout<<this->data<<endl; //solo para datos simples
}
template <class T>
Node<T>::~Node(){
    next=NULL;
    back=NULL;
}



