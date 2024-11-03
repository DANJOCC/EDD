#include "../queue/queue.cpp"
template<class T>
class priorityQueue
{
private:
    int priorities=0;
    Queue<T>* levels=NULL;
public:
    void push(T,int);
    T pop(int);
    void print(int);
    priorityQueue(int);

};


