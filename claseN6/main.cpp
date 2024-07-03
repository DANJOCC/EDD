#include<iostream>

#include "./class/tree.cpp"
using namespace std;
enum colorLevels{NEGRO, ROJO, AMARILLO,VERDE};
int main(){

    /*priorityQueue<int> list(4);

    int x[12]={5,4,3,7,8,6,4,3,6,12,5123,342};

  
   
    for (int i = 0; i <12; i++)
    {
        if(x[i]%2==0){
            list.push(x[i],NEGRO);
        }else if(x[i]%3==0){
            list.push(x[i],ROJO);
        }else if(x[i]%4==0){
            list.push(x[i],AMARILLO);
        }else{
            list.push(x[i],VERDE);
        }
        
    }
    
    cout<<"elementos grado Negro"<<endl;
    list.print(NEGRO);
    cout<<"elementos grado ROJO"<<endl;
    list.print(ROJO);
    cout<<"elementos grado AMARILLO"<<endl;
    list.print(AMARILLO);
    cout<<"elementos grado VERDE"<<endl;
    list.print(VERDE);*/
    Tree<char> tree;

    char x[13]={'J','D','P','M','S','Q','T','K','N','O','B','E','A'};

  
   
    for (int i = 0; i <13; i++)
    {
        tree.insert(x[i]);
    }
    cout<<"postOrden"<<endl;
    tree.print(0);
    cout<<endl<<"inOrden"<<endl;
    tree.print(1);
    cout<<endl<<"preOrden"<<endl;
    tree.print(2);
 
 

}