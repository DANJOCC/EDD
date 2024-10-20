#include "../node/node.cpp"
template<class T>
class Queue{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;
    public:
        ~Queue();
        Queue(T,Node<T>*);
        void push(T);
        T pop();
        bool isEmpty();
        int getLength();
        void print();
};