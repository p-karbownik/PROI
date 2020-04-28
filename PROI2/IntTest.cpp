
#include "IntTest.h"

void IntTest::isEmptyTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "isEmptyTest()\n";
    bool expected = 1;
    if(expected == aList.isEmpty())
        std::cout << "Dla pustej listy test pomyslny\n";
    else
        std::cout << "Dla pustej listy test niepomyslny\n";

    expected = 0;

    aList.push(10);
    aList.push(200);
    aList.push(23);

    if(expected == aList.isEmpty())
        std::cout << "Dla listy niepustej test pomyslny\n";
    else
        std::cout << "Dla listy niepustej test niepomyslny\n";
}
void IntTest::getSizeTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "getSizeTest()\n";
    int expected = 0;
    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 0 test pomyslny\n";
    }
    else
    {
        std::cout << "Dla expected 0 test niepomyslny\n";
    }

    expected = 1;
    aList.push(10);
     if(expected == aList.getSize())
     {
         std::cout << "Dla expected 1 test pomyslny\n";
     }
     else
     {
         std::cout << "Dla expected 1 test niepomyslny\n";
     }

    expected = 2;
    aList.push(200);

    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 2 test pomyslny\n";
    }

    else {
        std::cout << "Dla expected 2 test niepomyslny\n";
    }

    expected = 3;
    aList.push(12);

    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 3 test pomyslny\n";
    }

    else
    {
        std::cout << "Dla expected 3 test niepomyslny\n";
    }

    std::cout << "Testowanie getSize(), po usunięciu po jednym elemencie\n";
    expected = 2;
    aList.removeElement(0);

    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 2 test pomyslny\n";
    }
    else
    {
        std::cout << "Dla expected 2 test niepomyslny\n";
    }

    expected = 1;
    aList.removeElement(0);
    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 1 test pomyslny\n";
    }
    else
    {
        std::cout << "Dla expected 1 test niepomyslny\n";
    }

    expected = 0;
    aList.removeElement(0);
    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 0 test pomyslny\n";
    }
    else
    {
        std::cout << "Dla expected 0 test niepomyslny\n";
    }
}
void IntTest::additionTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "additionTest()\n";
    std::cout << "Dla listy pustej\n";

    if(aList.getElement(0) == nullptr)
    {
        std::cout << "Test pomyslny\n";
    }
    else
    {
        std::cout << "Test niepomyslny\n";
    }

    std::cout << "Dla listy puste - index 156\n";

    if(aList.getElement(156) == nullptr)
    {
        std::cout << "Test pomyslny\n";
    }
    else
    {
        std::cout << "Test niepomyslny\n";
    }

    std::cout << "Dla listy 3 elementowej\n";

    int expected = 12;
    aList.push(11);
    aList.push(12);
    aList.push(13);

    if(*(aList.getElement(1)) == expected)
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Dla listy 10 elementowej\n";

    for(int i = 0; i < 7; i++)
        aList.append(i + 14);

    expected = 17;

    if(*(aList.getElement(6)) == expected)
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";
}
void IntTest::comparisonTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "comparisionTest\n";

    DoublyLinkedList<int> secondList;

    std::cout << "Test dla obu pustych\n";

    bool expected = true;

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Jedna lista pusta, druga niepusta\n";

    expected = false;
    secondList.push(11);

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: obie listy mają 4 takie same elementy w tej samej kolejności\n";

    secondList.push(12);
    secondList.push(13);
    secondList.push(14);

    aList.push(11);
    aList.push(12);
    aList.push(13);
    aList.push(14);

    expected = true;

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Obie listy posiadają elementy z czego jedna z list ma ich 7, a druga 4\n";

    expected = false;

    secondList.push(22);
    secondList.push(42);
    secondList.push(31);

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Obie listy posiadają po 7 elementów, ale są to elementy różne\n";

    expected = false;

    aList.push(111);
    aList.push(213);
    aList.push(12312);

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";
}
void IntTest::printTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "printTest\n";
    using namespace std;

    cout << "Test: Lista pusta\n";

    stringstream aStream;
    string aString;
    string expected = "";
    aStream << aList;
    aString = aStream.str();

    if(expected == aString)
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: Lista zawiera 1 element\n";

    aStream.str("");

    aList.push(11);

    expected = "11 ";

    aStream << aList;
    aString = aStream.str();

    if(expected == aString)
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: Lista zawiera 4 elementy\n";

    aStream.str("");

    aList.append(12);
    aList.append(13);
    aList.append(14);
    expected = "11 12 13 14 ";

    aStream << aList;
    aString = aStream.str();

    if(expected == aString)
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";
}
void IntTest::getNextElementTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "getNextElementTest()\n";
    int *expected = nullptr;
    using namespace std;

    cout << "Test: Pusta lista\n";

    if(expected == aList.getNextElement(1))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "W następnych testach: Lista składa się z 3 elementów\n";

    aList.push(1);
    aList.push(2);
    aList.push(3);

    cout << "Test: lista.getNextElement(-2)\n";

    if(expected == aList.getNextElement(-2))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(-1)\n";

    int a = 3;

    expected = &a;


    if(*expected == *(aList.getNextElement(-1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(0)\n";

    *expected = 2;

    if(*expected == *(aList.getNextElement(0)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(1)\n";

    *expected = 1;

    if(*expected == *(aList.getNextElement(1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";


    cout << "Test: lista.getNextElement(2)\n";

    expected = nullptr;

    if(expected == aList.getNextElement(2))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";
}
void IntTest::getPreviousElementTest()
{
    DoublyLinkedList<int> aList;
    std::cout << "getPreviousElementeTest()\n";
    int *expected = nullptr;
    using namespace std;

    cout << "Test: Pusta lista\n";

    if(expected == aList.getPreviousElement(1))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "W następnych testach: Lista składa się z 3 elementów\n";

    aList.push(1);
    aList.push(2);
    aList.push(3);

    cout << "Test: lista.getPreviousElement(-1)\n";

    if(expected == aList.getPreviousElement(-1))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getPreviousElement(0)\n";

    if(expected == aList.getPreviousElement(0))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getPreviousElement(1)\n";

    int a = 3;

    expected = &a;


    if(*expected == *(aList.getPreviousElement(1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getPreviousElement(2)\n";

    *expected = 2;

    if(*expected == *(aList.getPreviousElement(2)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getPreviousElement(3)\n";

    *expected = 1;

    if(*expected == *(aList.getPreviousElement(3)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";


    cout << "Test: lista.getPreviousElement(4)\n";

    expected = nullptr;

    if(expected == aList.getPreviousElement(4))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

}
