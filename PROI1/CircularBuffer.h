#ifndef PROI1_CIRCULARBUFFER_H
#define PROI1_CIRCULARBUFFER_H
#include <iostream>


class CircularBuffer {
private:
    int size = 0;
    int numberOfElements = 0;
    int head;
    int tail;
    int* array;
public:
    bool isEmpty() const;
    bool isFull() const;
    int getNumberOfElements() const;
    int getElement();
    void addElement(int i);
    bool addElementIfPossible(int i);
    void operator<< (CircularBuffer cb);
    friend std::ostream& operator<< (std::ostream&, CircularBuffer &);
    bool operator== (CircularBuffer &bf1) const;
    bool operator!= (CircularBuffer &bf1) const;
    void operator+= (CircularBuffer &bf1);
    friend CircularBuffer* operator+ (CircularBuffer &bf1, CircularBuffer &bf2);
    explicit CircularBuffer(int s);
    CircularBuffer(const CircularBuffer &b);
    ~CircularBuffer();
};


#endif //PROI1_CIRCULARBUFFER_H
