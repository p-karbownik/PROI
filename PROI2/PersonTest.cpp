

#include "PersonTest.h"

void PersonTest::isEmptyTest()
{
    DoublyLinkedList<Person> aList;
    std::cout << "isEmptyTest()\n";
    bool expected = 1;
    if(expected == aList.isEmpty())
        std::cout << "Dla pustej listy test pomyslny\n";
    else
        std::cout << "Dla pustej listy test niepomyslny\n";

    expected = 0;

    aList.push(Person("Agata", "Nijaka"));
    aList.push(Person("Marek", "Jak"));
    aList.push(Person("Anna", "Domino"));

    if(expected == aList.isEmpty())
        std::cout << "Dla listy niepustej test pomyslny\n";
    else
        std::cout << "Dla listy niepustej test niepomyslny\n";
}
void PersonTest::getSizeTest()
{
    DoublyLinkedList<Person> aList;
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
    aList.push(Person("Anna", "Domino"));
    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 1 test pomyslny\n";
    }
    else
    {
        std::cout << "Dla expected 1 test niepomyslny\n";
    }

    expected = 2;
    aList.push(Person("Gucio", "Guciowski"));

    if(expected == aList.getSize())
    {
        std::cout << "Dla expected 2 test pomyslny\n";
    }

    else {
        std::cout << "Dla expected 2 test niepomyslny\n";
    }

    expected = 3;
    aList.push(Person("Tabaluga", "Smok"));

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
void PersonTest::additionTest()
{
    DoublyLinkedList<Person> aList;
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

    Person expected = Person("Daenerys", "Targaryan");
    aList.push(Person("Jon", "Snow"));
    aList.push(Person("Daenerys", "Targaryan"));
    aList.push(Person("Jaimie", "Lannister"));

    if(*(aList.getElement(1)) == expected)
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Dla listy 10 elementowej\n";

    aList.append(Person("Jan", "Wielki"));
    aList.append(Person("Anna", "Domino"));
    aList.append(Person("Jan", "Kalosz"));
    aList.append(Person("Maurycy", "Konewka"));
    aList.append(Person("Agata", "Kruk"));
    aList.append(Person("Aurelia", "Nieswieta"));
    aList.append(Person("Zuuu", "Uuu"));
    expected = Person("Maurycy", "Konewka");

    if(*(aList.getElement(6)) == expected)
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";
}
void PersonTest::comparisonTest()
{
    DoublyLinkedList<Person> aList;
    std::cout << "comparisionTest\n";

    DoublyLinkedList<Person> secondList;

    std::cout << "Test dla obu pustych\n";

    bool expected = true;

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Jedna lista pusta, druga niepusta\n";

    expected = false;
    secondList.push(Person("Ala", "Spatz"));

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: obie listy mają 4 takie same elementy w tej samej kolejności\n";

    secondList.push(Person("Anna", "Domino"));
    secondList.push(Person("Albert", "Tully"));
    secondList.push(Person("Willy", "Smith"));

    aList.push(Person("Ala", "Spatz"));
    aList.push(Person("Anna", "Domino"));
    aList.push(Person("Albert", "Tully"));
    aList.push(Person("Willy", "Smith"));

    expected = true;

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Obie listy posiadają elementy z czego jedna z list ma ich 7, a druga 4\n";

    expected = false;

    secondList.push(Person("Amanda", "Francuska"));
    secondList.push(Person("Robert", "Gadulski"));
    secondList.push(Person("Esmeralda", "Godlewska"));

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";

    std::cout << "Test: Obie listy posiadają po 7 elementów, ale są to elementy różne\n";

    expected = false;

    aList.push(Person("Jagna", "Bagienna"));
    aList.push(Person("Baba", "Wodna"));
    aList.push(Person("Baron", "Krwawy"));

    if(expected == (secondList == aList))
        std::cout << "Test pomyslny\n";
    else
        std::cout << "Test niepomyslny\n";
}
void PersonTest::printTest()
{
    DoublyLinkedList<Person> aList;
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

    aList.push(Person("Ala", "Nijaka"));

    expected = "Ala Nijaka ";

    aStream << aList;
    aString = aStream.str();

    if(expected == aString)
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: Lista zawiera 4 elementy\n";

    aStream.str("");

    aList.append(Person("Anna", "Inna"));
    aList.append(Person("Ten", "Obcy"));
    aList.append(Person("Ten", "Znany"));
    expected = "Ala Nijaka Anna Inna Ten Obcy Ten Znany ";

    aStream << aList;
    aString = aStream.str();

    if(expected == aString)
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";
}
void PersonTest::getNextElementTest()
{
    DoublyLinkedList<Person> aList;
    std::cout << "getNextElementTest()\n";
    Person *expected = nullptr;
    using namespace std;

    cout << "Test: Pusta lista\n";

    if(expected == aList.getNextElement(1))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "W następnych testach: Lista składa się z 3 elementów\n";

    aList.push(Person("Anna", "Domino"));
    aList.push(Person("Helga", "Krupnik"));
    aList.push(Person("Hans", "KloppenWaffen"));

    cout << "Test: lista.getNextElement(-2)\n";

    if(expected == aList.getNextElement(-2))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(-1)\n";

    Person a = Person("Hans", "KloppenWaffen");

    expected = &a;


    if(*expected == *(aList.getNextElement(-1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(0)\n";

    expected = new Person("Helga", "Krupnik");

    if(*expected == *(aList.getNextElement(0)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getNextElement(1)\n";

    delete expected;
    expected = nullptr;

    expected = new Person("Anna", "Domino");

    if(*expected == *(aList.getNextElement(1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";


    cout << "Test: lista.getNextElement(2)\n";

    delete expected;

    expected = nullptr;

    if(expected == aList.getNextElement(2))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";
}
void PersonTest::getPreviousElementTest()
{
    DoublyLinkedList<Person> aList;
    std::cout << "getPreviousElementeTest()\n";
    Person *expected = nullptr;
    using namespace std;

    cout << "Test: Pusta lista\n";

    if(expected == aList.getPreviousElement(1))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "W następnych testach: Lista składa się z 3 elementów\n";

    aList.push(Person("Anna", "Domino"));
    aList.push(Person("Helga", "Krupnik"));
    aList.push(Person("Hans", "KloppenWaffen"));

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

    Person a = Person("Hans", "KloppenWaffen");

    expected = &a;


    if(*expected == *(aList.getPreviousElement(1)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    cout << "Test: lista.getPreviousElement(2)\n";

    expected = new Person("Helga", "Krupnik");

    if(*expected == *(aList.getPreviousElement(2)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

    delete expected;
    expected = nullptr;

    cout << "Test: lista.getPreviousElement(3)\n";

    expected = new Person("Anna", "Domino");

    if(*expected == *(aList.getPreviousElement(3)))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";


    cout << "Test: lista.getPreviousElement(4)\n";

    delete expected;
    expected = nullptr;

    if(expected == aList.getPreviousElement(4))
        cout << "Test pomyslny\n";
    else
        cout << "Test niepomyslny\n";

}
