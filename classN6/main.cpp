#include<iostream>

#include "./tree/tree.cpp"
using namespace std;

int main(){

   
    Tree<char> tree;

    char x[11]={'A','B','C','D','E','F','G','H','I', 'j', 'K'};

  
   
    for (int i = 0; i <11; i++)
    {
        tree.insert(x[i]);
       
    }

    tree.print(3); //preorden

    

 
 

}