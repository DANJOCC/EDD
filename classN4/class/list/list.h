#include "../node/node.cpp"
template<class T>
class List{
    private:
        Node<T> *head=NULL;
        int length=0;
    public:
        void insert(T data);
        void insertFirst( Node<T> *node);
        bool deleteNode(T data);
        bool isEmpty();
        void print();
        int getLength();
        bool update(int n, T data);

};