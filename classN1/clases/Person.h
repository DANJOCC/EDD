#include<iostream>
using namespace std;
class Person
{
private:
    int ci;
    int edad;
    string name;
    string nation;

public:
    string gender;
    Person(int , int , string , string , string );
    void speak();
    void write(int , string );
    void write(int , int);
    
};