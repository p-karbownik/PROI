
#include "Person.h"

Person::Person(std::string aName, std::string aSurname)
{
    name = aName;
    surname = aSurname;
}

void Person::setName(std::string aName)
{
    name = aName;
}

void Person::setSurname(std::string aSurname)
{
    surname = aSurname;
}

bool Person::operator==(const Person &aPerson) const
{
    if(this->name == aPerson.name && this->surname == aPerson.surname)
        return true;
    else
        return false;
}

bool Person::operator!=(const Person &aPerson) const
{
    if(this->operator==(aPerson))
        return false;
    else
        return true;
}
std::ostream& operator<<(std::ostream& output, const Person &aPerson)
{
    std::string blankSpace = " ";
    output << aPerson.name;
    output << blankSpace;
    output << aPerson.surname;
    return output;
}
