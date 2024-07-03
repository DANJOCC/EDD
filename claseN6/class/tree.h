#include "./node/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=NULL;
        int higth = 0;
        Node<T>* insert(Node<T>*, T);
    public:
        bool isEmpty();
        void insert(T);
        void print(int);
        void postOrden(Node<T>*);
        void inOrden(Node<T>*);
        void preOrden(Node<T>*);
        

};