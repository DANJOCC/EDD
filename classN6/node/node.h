//enum child{RIGHT,LEFT};
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
        
        Node<T>* getChild(int);
        void setChildren(Node<T>*,Node<T>*);
        void setLeft(Node<T>*);
        void setRight(Node<T>*);

        void setData(T);
        T getData();
       
        void setFe();
        void setFe(int);
        int getFe();

         
        void setHeigth(int);
        int getHeigth();
        int calculate_Heigth(Node<T>*);
        
        bool isLeaf();

        void print();

       
     
};