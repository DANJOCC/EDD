#include "../node/node.cpp"
template<class T>
class List{
    private:
        Node<T> *head=NULL;
        Node<T> *tail=NULL;
        int length=0;
    public:
        void insert(T data);
        void insertFirst( Node<T> *node);
        void insertLast( Node<T> *node);
        bool deleteNode(T data);
        bool isEmpty();
        void print();
        bool update(int n, T data);

};