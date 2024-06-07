template<class T>
class Node{
    private:
        T data;
        Node<T> *next=NULL;
    public:
        Node(T,Node<T>*);
        ~Node();
        Node<T>* getNextNode();
        void setData(T);
        T getData();
        void setNextNode(Node<T>*);
        void print();
};