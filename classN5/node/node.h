//enum child{RIGHT,LEFT};
template<class T>
class Node{
    private:
        T data;
        Node<T> *left=NULL;
        Node<T> *right=NULL;
    public:
        Node(T,Node<T>*,Node<T>*);
        ~Node();
        Node<T>* getChild(int);
        void setData(T);
        T getData();
        void setChildren(Node<T>*,Node<T>*);
        void setLeft(Node<T>*);
        void setRight(Node<T>*);
        void print();
};