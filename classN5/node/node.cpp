#include<iostream>
#include "./node.h"
using namespace std;

template <class T>
Node<T>::Node(T data, Node<T>* right, Node<T>* left){
    this->data=data;
    if(right!=NULL){
        this->right=right;
    }
     if(left!=NULL){
        this->left=left;
    }
}
template <class T>
Node<T>* Node<T>::getChild(int child){
    switch (child)
    {
    case 0:
        return this->left;
    case 1:
        return this->right;
    }
    return NULL;
}

template <class T>
void Node<T>::setChildren(Node<T>* right, Node<T>* left){

        this->right=right;
        this->left=left;
}

template <class T>
void Node<T>::setData(T data){
    this->data=data;
}


template <class T>
T Node<T>::getData(){
   return this->data;
}

template <class T>
void Node<T>::setLeft(Node<T>* left){
    this->left = left;
};

template <class T>
void Node<T>::setRight(Node<T>* right){
    this->right = right;
};

template<class T>
void Node<T>::print(){
    cout<<this->data<<" "; //solo para datos simples
}
template <class T>
Node<T>::~Node(){
    this->right=NULL;
    this->left=NULL;
}



