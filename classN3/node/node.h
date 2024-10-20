template<class T>
class Node{
    private:
        T data;
        Node<T>* next = nullptr;
    public:
        Node(T, Node<T>*);
        ~Node();
        T getData();
        void setData(T);
        Node<T>* getNext();
        void setNext(Node<T>*);
        void print();
};