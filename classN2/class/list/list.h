#include "../node/node.cpp"
template<class T>
class List{
    private:
        Node<T> *head=NULL;
    public:
        void insert(T data);
        void insertFirst( Node<T> *node);
        bool deleteOne(T data);
        bool isEmpty();
        void print();
        void update(int n, T data);
};