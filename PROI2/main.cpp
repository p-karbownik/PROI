#include <iostream>
#include "IntTest.h"
#include "PersonTest.h"

using namespace std;

int main()
{

    cout << "Testowanie class DoublyLinkedList dla int\n\n";

    IntTest testI;
    testI.isEmptyTest();
    cout << endl;
    testI.getSizeTest();
    cout << endl;
    testI.additionTest();
    cout << endl;
    testI.comparisonTest();
    cout << endl;
    testI.printTest();
    cout << endl;
    testI.getNextElementTest();
    cout << endl;
    testI.getPreviousElementTest();
    cout << endl;

    cout << "Testowanie class DoublyLinkedList dla class Person\n\n";

    PersonTest testP;
    testP.isEmptyTest();
    cout << endl;
    testP.getSizeTest();
    cout << endl;
    testP.additionTest();
    cout << endl;
    testP.comparisonTest();
    cout << endl;
    testP.printTest();
    cout << endl;
    testP.getNextElementTest();
    cout << endl;
    testP.getPreviousElementTest();
    cout << endl;
    return 0;
}