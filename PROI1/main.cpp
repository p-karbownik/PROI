#include <iostream>
#include "CircularBuffer.h"

using namespace std;
int main()
{
    int s = 0;

    while(true) {
        cout << "Podaj rozmiar pierwszego bufora: ";
        cin >> s;
        cin.clear();
        cin.sync();
        cin.ignore();

        cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
        int a;
        cin >> a;
        cin.clear();
        cin.sync();
        cin.ignore();
        if (a == 1)
            break;

    }
    CircularBuffer bufferA(s);
    while(true) {
        cout << "Podaj rozmiar drugiego bufora: ";
        cin >> s;
        cin.clear();
        cin.sync();
        cin.ignore();

        cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
        int a;
        cin >> a;
        cin.clear();
        cin.sync();
        cin.ignore();
        if (a == 1)
            break;

    }
    CircularBuffer bufferB(s);

    int option = 1;

    while(option != 0)
    {
        cout << endl << "0. Wyjscie" << endl;
        cout << "1. Dodaj element z nadpisaniem (bufor nr. 1)" << endl;
        cout << "2. Dodaj element bez nadpisania (bufor nr. 1)" << endl;
        cout << "3. Czy pełny (bufor nr. 1)?" << endl;
        cout << "4. Czy pusty (bufor nr. 1)?" << endl;
        cout << "5. Pobierz element z bufora (bufor nr. 1)" << endl;
        cout << "6. Liczba elementów w buforze (bufor nr. 1)" << endl;
        cout << "7. Drukuj bufor (operator <<) (bufor nr. 1)" << endl;
        cout << "8. Dodaj element z nadpisaniem (bufor nr. 2)" << endl;
        cout << "9. Dodaj element bez nadpisania (bufor nr. 2)" << endl;
        cout << "10. Czy pełny (bufor nr. 2)?" << endl;
        cout << "11. Czy pusty (bufor nr. 2)?" << endl;
        cout << "12. Pobierz element z bufora (bufor nr. 2)" << endl;
        cout << "13. Liczba elementów w buforze (bufor nr. 2)" << endl;
        cout << "14. Drukuj bufor (operator <<) (bufor nr. 2)" << endl;
        cout << "15. Dodaj bufor2 do bufora1 (operator +=)" << endl;
        cout << "16. Dodaj bufor 2 do bufora 1 i wydrukuj (operator + i <<)" << endl;
        cout << "17. Porównaj bufor 1 i bufor 2 (operator ==)" << endl;
        cout << "18. Porównaj bufor 1 i bufor 2 (operator !=)" << endl;

        cout << "Podaj nr. ";
        cin >> option;

        if(option == 1)
        {
            while(true) {
                cout << "Podaj wartosc: ";

                cin >> s;
                cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
                int a;
                cin >> a;
                cin.clear();
                cin.sync();
                cin.ignore();
                if (a == 1)
                {
                    bufferA.addElement(s);
                    break;
                }
            }
        }

        else if(option == 2)
        {
            while(true) {
                cout << "Podaj wartosc: ";

                cin >> s;
                cin.clear();
                cin.sync();
                cin.ignore();
                cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
                int a;
                cin >> a;
                cin.clear();
                cin.sync();
                cin.ignore();
                if (a == 1)
                {
                    if(bufferA.addElementIfPossible(s))
                        cout << "Bufor pelny" << endl;
                    break;
                }
            }
        }

        else if(option == 3)
        {
            if(bufferA.isFull())
                cout << "Pełny" << endl;
            else
                cout << "Niepełny" << endl;
        }

        else if(option == 4)
        {
            if(bufferA.isEmpty())
                cout << "pusty" << endl;
            else
                cout << "niepusty" << endl;
        }

        else if(option == 5)
        {
            if(!bufferA.isEmpty())
                cout << bufferA.getElement();
            else
                cout << "Bufor pusty" << endl;
        }

        else if(option == 6)
        {
            cout << bufferA.getNumberOfElements() << endl;
        }

        else if(option == 7)
        {
            cout << bufferA;
        }

        else if(option == 8)
        {
            while(true) {
                cout << "Podaj wartosc: ";

                cin >> s;
                cin.clear();
                cin.sync();
                cin.ignore();
                cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
                int a;
                cin >> a;
                cin.clear();
                cin.sync();
                cin.ignore();
                if (a == 1)
                {
                    bufferB.addElement(s);
                    break;
                }
            }
        }


        else if(option == 9)
        {
            while(true) {
                cout << "Podaj wartosc: ";

                cin >> s;
                cin.clear();
                cin.sync();
                cin.ignore();
                cout << "Podana wartosc: " << s << " Czy poprawna(TAK -> 1, NIE -> cokolwiek innego): ";
                int a;
                cin >> a;
                cin.clear();
                cin.sync();
                cin.ignore();
                if (a == 1)
                {
                    if(bufferB.addElementIfPossible(s))
                        cout << "Bufor pelny" << endl;
                    break;
                }
            }
        }

        else if(option == 10)
        {
            if(bufferB.isFull())
                cout << "Pelny" << endl;
            else
                cout << "Niepełny" << endl;
        }

        else if(option == 11)
        {
            if(bufferB.isEmpty())
                cout << "pusty" << endl;
            else
                cout << "niepusty" << endl;
        }

        else if(option == 12)
        {
            if(!bufferB.isEmpty())
                cout << bufferB.getElement() << endl;
            else
                cout << "Bufor pusty";
        }

        else if(option == 13)
        {
            cout << "Liczba elementow: " << bufferB.getNumberOfElements() << endl;
        }

        else if(option == 14)
        {
            cout << bufferB;
        }

        else if(option == 15)
        {
            bufferA += bufferB;
        }

        else if(option == 16)
        {
            CircularBuffer* bufferC;
            bufferC = bufferA + bufferB;
            cout << *bufferC;
            delete(bufferC);
        }

        else if(option == 17)
        {
            if (bufferA == bufferB)
                cout << "Takie same" << endl;
            else
                cout << "Różne" << endl;
        }

        else if(option == 18)
        {
            if (bufferA != bufferB)
                cout << "Różne" << endl;
            else
                cout << "Takie same" << endl;
        }

        else if(option != 0)
        {
            cout << "Niepoprawna opcja. Wybierz jeszcze raz" << endl << endl;
        }
    }

    return 0;
}