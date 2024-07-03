#include "../queue/queue.cpp"
template<class T>
class priorityQueue
{
private:
    int levels=0;
    Queue<T>* array=NULL;
public:
    void push(T,int);
    T pop(int);
    void print(int);
    priorityQueue(int);

};


