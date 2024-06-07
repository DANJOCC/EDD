template<class T>
class Node{
    private:
        T data;
        Node<T> *back=NULL;
        Node<T> *next=NULL;
    public:
        Node(T,Node<T>*,Node<T>*);
        ~Node();
        Node<T>* getNextNode();
        Node<T>* getBackNode();
        void setData(T);
        T getData();
        void setNextNode(Node<T>*);
        void setBackNode(Node<T>*);
        void print();
};