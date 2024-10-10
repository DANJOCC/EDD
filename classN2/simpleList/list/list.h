#include "../node/node.cpp"

template<class T>
class List{
    private:
        Node<T>* head = nullptr;
        int length = 0;
    public:
        List(Node<T>*);
        void insert(T);
        void insertFirst(T);
        bool remove(T);
        bool isEmpty();
        void print();
        bool update(int, T);
};