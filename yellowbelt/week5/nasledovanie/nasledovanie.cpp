/******************************************
**
**      File: nasledovanie.cpp
**      Project: workspace
**      Created By VERMIN
**      Date: 25/02/2021
**      Description: 
** Определите до конца тела классов, соблюдая следующие требования:
**
** Класс Dog должен являться наследником класса Animal.
** Конструктор класса Dog должен принимать параметр типа string и инициализировать им поле Name в классе Animal.
******************************************/


// Includes
#include <iostream>

using namespace std;

// Classes and function
class Animal {
public:
    Animal(const string& n = "animal") : Name(n) {
        
    }

    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& n) : Animal(n) {

    }

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

// Main Code
int main(int argc, char const *argv[])
{
    Dog d("Volf");
    d.Bark();
    return 0;
}
