#include "../node/node.cpp"

template<class T>
class List{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        int length = 0;
    public:
        List(Node<T>*);
        void insert(T);
        void insertFirst(T);
        void insertLast(T);
        bool remove(T);
        bool isEmpty();
        void print();
        void printReverse();
        bool update(int, T);
};