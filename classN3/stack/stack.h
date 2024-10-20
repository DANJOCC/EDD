#include "../node/node.cpp"
template<class T>
class Stack{
    private:
        Node<T>* head = nullptr;
        int length = 0;
    public:
        ~Stack();
        Stack(T,Node<T>*);
        void push(T);
        T pop();
        bool isEmpty();
        int getLength();
        void print();
};