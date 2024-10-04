#include<iostream>
using namespace std;



class person{
    private:
        string name;
    public:
        void setName(string name){
            this->name = name;
        }
        void saludo(){
            cout<<"Hola, me llamo "<<name<<endl;
        }
};

template <typename T>
class box{
    private:
        T object;
    public:
        void setObject(T object){
            this->object=object;
        }
        T getObject(){
            return this->object;
        }
};

int main(){
    box<int> a;

    a.setObject(3);
    cout<<a.getObject()<<endl;

    person p;

    p.setName("daniel");

    box<person> b;

    b.setObject(p);

    b.getObject().saludo();
}