template<class T>
class Node{
    private:
        T data;
        int heigth = 0;
        int fe=0;
        Node<T> *left=NULL;
        Node<T> *right=NULL;
        int autoHeight();
    public:
        Node(T,Node<T>*,Node<T>*);
        ~Node();
        Node<T>* getChildren(int);
        void setData(T);
        T getData();
        void setChildren(Node<T>*,Node<T>*);
        void print();
        void setFe();
        void setFe(int);
        int getFe();
        void setHeigth(int);
        int calculate_Heigth(Node<T>*);
        int getHeigth();
        bool isLeaf();
        void setRight(Node<T>*);
        void setLeft(Node<T>*);
};