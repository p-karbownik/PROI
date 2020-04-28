

#ifndef PROJEKT2_PERSON_H
#define PROJEKT2_PERSON_H

#include <string>

class Person {
    private:
        std::string name;
        std::string surname;
    public:
        Person(std::string aName = "", std::string aSurname = "");
        ~Person(){}
        void setName(std::string aName);
        void setSurname(std::string aSurname);
        bool operator==(const Person&) const;
        bool operator!=(const Person&) const;
        friend std::ostream& operator<< (std::ostream&, const Person & );
};


#endif //PROJEKT2_PERSON_H
