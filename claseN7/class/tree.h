#include "./treeNode/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=NULL;
    
        Node<T>* insert(Node<T>*, T,bool&);
        Node<T>* eliminate(Node<T>*,T, bool&);
        Node<T>* replace(Node<T>*);
        Node<T>* rotation_simple_izq(Node<T>*, Node<T>*);
        Node<T>* rotation_simple_der(Node<T>*, Node<T>*);
        Node<T>* rotation_double_izq(Node<T>*, Node<T>*);
        Node<T>* rotation_double_der(Node<T>*, Node<T>*);
        bool height_changed = false;
        
    public:
        bool isEmpty();
        void insert(T);
        void eliminate(T);
        void eliminate_no_recursive(T);
        void insert_no_recursive(T);
        void print(int);
        void postOrden(Node<T>*);
        void inOrden(Node<T>*);
        void preOrden(Node<T>*);
        void calcHeight(Node<T>*);
        void balance(Node<T>*,Node<T>*,int, bool);


        
        // void RDD(Node<T>*);
        // void RSD(Node<T>*);
        // void RDI(Node<T>*);
        // void RSI(Node<T>*);

};