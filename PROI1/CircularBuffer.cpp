
#include "CircularBuffer.h"

int CircularBuffer::getNumberOfElements() const
{
    return numberOfElements;
}

CircularBuffer::CircularBuffer(int s)
{
    size = s;
    array = new int[s];
    numberOfElements = 0;
    head = 0;
    tail = 0;
}
int CircularBuffer::getElement()
{
    if(numberOfElements > 0)
    {
        numberOfElements--;
        return array[head++];
    }
    return 0;
}

void CircularBuffer::addElement(int i)
{
    array[tail] = i;

    tail++;
    if (tail == size)
        tail = 0;

    if(numberOfElements != size)
        numberOfElements++;

}

bool CircularBuffer::isFull() const
{
    if(numberOfElements == size)
        return true;
    else
        return false;
}

bool CircularBuffer::isEmpty() const
{
    if(numberOfElements == 0)
        return true;
    else
        return false;
}

bool CircularBuffer::addElementIfPossible(int i)
{
    if(numberOfElements != size)
    {
        this->addElement(i);
        return 0;
    }
    else
    {
        return 1;
    }
}

void CircularBuffer::operator+=(CircularBuffer &bf1)
{
    int newSize = bf1.size + size;

    int* nArray = new int[newSize];

    int i = 0;

    while (!(this->isEmpty()))
    {
        nArray[i] = this->getElement();

        i++;
    }

    int head1 = bf1.head;
    int nOE = bf1.numberOfElements;
    while (nOE)
    {
        nArray[i] = bf1.array[head1];

        i++;
        head1++;
        nOE--;

        if(head1 == size)
            head1 = 0;
    }

    delete[](array);
    head = 0;
    tail = i;
    array = nArray;
    numberOfElements = i;
    size = newSize;
}

bool CircularBuffer::operator== (CircularBuffer &bf1) const
{
    if(this->isEmpty() != bf1.isEmpty())
        return 0;
    if(this->isEmpty() == 1 && bf1.isEmpty() == 1)
        return 1;

    int tail0 = tail; //ogon obiektu, w ktorym siedzimy
    int tail1 = bf1.tail; // ogon obiektu, z ktorym porownujemy

    int head0 = head;
    int head1 = bf1.head;

    int size0 = size;
    int size1 = bf1.size;

    do
    {
        if(array[head0] != bf1.array[head1])
            return 0;

        head0++;
        head1++;

        if(head0 == size0 && head0 != tail0)
            head0 = 0;

        if (head1 == size1 && head1 != tail1)
            head1 = 0;

    }while ( (head0 != tail0) && (head1 != tail1));

    if(head0 == tail0 && head1 == tail1)
        return 1;
    else
        return 0;
}

bool CircularBuffer::operator!= (CircularBuffer &bf1) const
{
    if(this->isEmpty() != bf1.isEmpty())
        return 1;

    if(this->isEmpty() == 1 && bf1.isEmpty() == 1)
        return 0;

    int tail0 = tail; //ogon obiektu, w ktorym siedzimy
    int tail1 = bf1.tail; // ogon obiektu, z ktorym porownujemy

    int head0 = head;
    int head1 = bf1.head;

    int size0 = size;
    int size1 = bf1.size;

    do
    {
        if(array[head0] != bf1.array[head1])
            return 1;

        head0++;
        head1++;

        if(tail0 == size0)
            head0 = 0;

        if (tail1 == size1)
            head1 = 0;

    }while ( (head0 != tail0) && (head1 != tail1));

    if(head0 == tail0 && head1 == tail1)
        return 0;
    else
        return 1;
}

CircularBuffer* operator+ (CircularBuffer &bf1, CircularBuffer &bf2)
{
    CircularBuffer newBf(bf1.size + bf2.size);

    int head0 = bf1.head;
    int tail0 = bf1.tail;
    int size0 = bf1.size;
    int size1 = bf2.size;
    int h = 0;
    if(bf1.numberOfElements != 0)
        do
        {
            newBf.array[h] = bf1.array[head0];
            h++;
            head0++;
            if(head0 == size0 && head0 != tail0)
                head0 = 0;

        }while (head0 != tail0);

    int head1 = bf2.head;
    int tail1 = bf2.tail;
    if(bf2.numberOfElements != 0)
        do
        {
            newBf.array[h] = bf2.array[head1];
            h++;
            head1++;
            if(head1 == size1 && head1 != tail1)
                head1 = 0;

        }while (head1 != tail1);
    newBf.tail = h;
    newBf.head = 0;
    newBf.numberOfElements = bf1.numberOfElements + bf2.numberOfElements;

    return new CircularBuffer(newBf);
}

std::ostream& operator<< (std::ostream &output, CircularBuffer &bf)
{
    while (bf.numberOfElements != 0)
    {
        output << bf.getElement() << " ";
    }
    return output;
}

CircularBuffer::CircularBuffer(const CircularBuffer &b)
{
    size = b.size;
    numberOfElements = b.numberOfElements;
    head = b.head;
    tail = b.tail;
    array = new int[b.size];
    int h = head;
    while(h != tail)
    {
        array[h] = b.array[h];
        h++;
        if (h == size && h != tail)
            h = 0;
    }
}

CircularBuffer::~CircularBuffer()
{
    delete[](array);
}
