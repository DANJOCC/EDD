#include<iostream>

#include "./class/tree.cpp"
using namespace std;
enum colorLevels{NEGRO, ROJO, AMARILLO,VERDE};
int main(){

   
    Tree<char> tree;

    char x[5]={'A','B','C','D','E'};

  
   
    for (int i = 0; i <5; i++)
    {
        tree.insert(x[i]);
       
    }

    cout<<endl;
    tree.eliminate('B');
    
   
    
    tree.print(0);

    cout<<endl;
    tree.eliminate('D');
 
   
    
    tree.print(0);

 
 

}