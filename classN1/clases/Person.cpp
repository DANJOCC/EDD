#include "./Person.h"

Person::Person(int ci, int edad, string name, string nation, string gender)
    {
        this->ci = ci;
        this->edad = edad;
        this->name = name;
        this->nation = nation;
        this->gender = gender;
    }

void Person::speak()
    {
        cout << "yo soy " << name << ", tengo " << edad << " de edad, y" << "soy de "
             << nation << "y me identifico como " << gender << endl;
    }

 void Person::write(int num, string foo)
    {
        switch (num)
        {
        case 1:
            name = foo;
            break;
        case 2:
            nation = foo;
        case 3:
            gender = foo;
        default:
            break;
        }
    }

 void Person::write(int num, int foo)  {
        switch (num)
        {
        case 1:
           ci = foo;
            break;
        case 2:
           edad = foo;
        default:
            break;
        }
    }   