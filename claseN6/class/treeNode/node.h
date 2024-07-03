template<class T>
class Node{
    private:
        T data;
        Node<T> *left=NULL;
        Node<T> *right=NULL;
    public:
        Node(T,Node<T>*,Node<T>*);
        ~Node();
        Node<T>* getChildren(int);
        void setData(T);
        T getData();
        void setChildren(Node<T>*,Node<T>*);
        void print();
};