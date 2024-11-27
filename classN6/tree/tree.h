#include "../node/node.cpp"
template<class T>
class Tree{
    private:
        Node<T>* root=NULL;
      
        Node<T>* insert(Node<T>*, T, bool&);//funcion recursiva insert
        Node<T>* eliminate(Node<T>*,T, bool&);//funcion recursiva eliminate
        Node<T>* replace(Node<T>*);

        Node<T>* rotation_simple_izq(Node<T>*, Node<T>*);
        Node<T>* rotation_simple_der(Node<T>*, Node<T>*);
        Node<T>* rotation_double_izq(Node<T>*, Node<T>*);
        Node<T>* rotation_double_der(Node<T>*, Node<T>*);
        bool height_changed = false;
    public:
        bool isEmpty();
        bool isLeaf(Node<T>*);
        void insert(T);//entrada a funcion recursiva eliminate
        void eliminate(T);//entrada a funcion recursiva insert
        void insert_no_recursive(T);
        void eliminate_no_recursive(T);
        void print(int);
        void postOrden(Node<T>*);
        void inOrden(Node<T>*);
        void preOrden(Node<T>*);
        void indexed(Node<T>*,int);
     
        

};