

#ifndef PROJEKT2_PERSONTEST_H
#define PROJEKT2_PERSONTEST_H


#include "DoublyLinkedList.h"
#include "Person.h"
#include <iostream>
#include <sstream>

class PersonTest
{
private:
public:
    PersonTest(){};
    void isEmptyTest();
    void getSizeTest();
    void additionTest();
    ~PersonTest(){};
    void comparisonTest();
    void printTest();
    void getNextElementTest();
    void getPreviousElementTest();
};

#endif //PROJEKT2_PERSONTEST_H
