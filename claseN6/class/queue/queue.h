#include "../queueNode/node.cpp"
template<class T>
class Queue{
    private:
        Node<T> *head=NULL;
        Node<T> *tail=NULL;
        int length=0;
    public:
        int getLength();
        void push(T);
        T pop();
        bool isEmpty();
        void print();
};