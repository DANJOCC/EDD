#include<iostream>
using namespace std;
template<class T>
T sum(T a, T b){
    return a+b;
}
template<class T>
T sum(T a, T b, T c){
    return a+b+c;
}

// Plantilla con dos clases

template<class T, class P>
void sum(T a, P c){
    for(int i=0; i<10; i++){
        c+=c;
    }
     for(int i=0; i<10; i++){
        a+=a;
    }
   cout<<a<<endl<<c;
}