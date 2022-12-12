#ifndef PERSON_CPP
#define PERSON_CPP

#include <iostream>

class Person
{
    public: 
        Person(std::string Name, int Age);
        Person& operator = (Person &movie); //copy assignment operator
        std::string getName();
        int getAge();

        ~Person() = default;

    private:
        std::string name;
        int age;
};

Person::Person(std::string Name, int Age):
    name(Name),
    age(Age)
{}

Person& Person::operator=(Person &person)
{
    if( this == &person)
    {
        std::cout << "Same objects!" << std::endl << std::endl;
        return *this;
    }//ITEM 11

    this->name = person.name;
    this->age = person.age;//ITEM 12

    return *this; //ITEM 10
}

std::string Person::getName()
{
    return this->name;
}

int Person::getAge()
{
    return this->age;
}
#endif