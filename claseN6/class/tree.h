#include "./treeNode/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=NULL;
      
        Node<T>* insert(Node<T>*, T);
        Node<T>* eliminate(Node<T>*,T);
        Node<T>* replace(Node<T>*);
    public:
        bool isEmpty();
        void insert(T);
        void eliminate(T);
        void print(int);
        void postOrden(Node<T>*);
        void inOrden(Node<T>*);
        void preOrden(Node<T>*);
        

};