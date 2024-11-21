#include<iostream>
#include "./tree/tree.cpp"
using namespace std;

int main(){

    Tree<char> tree;

    char x[13]={'J','D','P','M','S','Q','T','K','N','O','B','E','A'};

  
   
    for (int i = 0; i <13; i++)
    {
        tree.insert(x[i]);
    }
    /*cout<<"postOrden"<<endl;
    tree.print(0);
    cout<<endl<<"inOrden"<<endl;
    tree.print(1);
    cout<<endl<<"preOrden"<<endl;
    tree.print(2);
    tree.eliminate('P');
    cout<<endl<<"inOrden"<<endl;
    tree.print(1);*/
 
    tree.print(1);
    tree.eliminate('M');
    cout<<endl;
    tree.eliminate_no_recursive('N');
    tree.print(1);

}