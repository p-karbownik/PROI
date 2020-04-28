
#ifndef PROJEKT2_DOUBLYLINKEDLIST_H
#define PROJEKT2_DOUBLYLINKEDLIST_H

#include <iostream>

template <class Type>
class DoublyLinkedList {
    private:
        struct Node {Node* previous; Node* next; Type item;};
        Node* head;
        Node* tail;
        int size;
        DoublyLinkedList<Type>(const DoublyLinkedList &p){};
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void push(Type item);
        void append(Type item);
        Type* getElement(int index) const;
        bool removeElement(int index);
        Type* getNextElement(int index) const;
        Type* getPreviousElement(int index) const;
        bool isEmpty() const;
        int getSize() const;
        bool operator==(DoublyLinkedList &dll);
        template<class T>
        friend std::ostream& operator<< (std::ostream&, const DoublyLinkedList<T> & );
};

template <class Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template <class Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
    if(head != nullptr)
    {
        Node *p;

        if(head->next == nullptr)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            do
            {
                p = head->next;
                delete head;

                if(p == nullptr)
                    head = nullptr;
                else
                {
                    p->previous = nullptr;
                    head = p;
                }
            }while(head != nullptr);

            tail = nullptr;
        }
    }
    head = nullptr;
    tail = nullptr;
}

template <class Type>
void DoublyLinkedList<Type>::push(Type item)
{
    if((head == nullptr) && (tail == nullptr))
    {
        head = new Node;
        head->item = item;
        head->previous = nullptr;
        head->next = nullptr;
        tail = head;
    }
    else
    {
        Node* p = new Node;
        p->next = head;
        p->previous = nullptr;
        p->item = item;
        head->previous = p;
        head = p;
    }
    size++;
}
template <class Type>
void DoublyLinkedList<Type>::append(Type item)
{
    if((head == nullptr) && (tail == nullptr))
    {
        head = new Node;
        head->previous = nullptr;
        head->next = nullptr;
        head->item = item;
        tail = head;
    }
    else
    {
        Node* p = new Node;
        p->previous = tail;
        p->next = nullptr;
        p->item = item;
        tail->next = p;
        tail = p;
    }
    size++;
}

template <class Type>
Type* DoublyLinkedList<Type>::getElement(int index) const
{
    if((index > size - 1) || index < 0)
    {
        return nullptr;
    }

    else
    {
        Node *p = head;
        for(int i = 0; i < index; i++)
        {
            p = p->next;
        }
        return &(p->item);
    }
}

template <class Type>
bool DoublyLinkedList<Type>::removeElement(int index)
{
    if(index >= size || index < 0)
        return true;

    else if (head == nullptr)
    {
        return true;
    }
    else
    {
        Node *p = head;
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }

        if(p == head)
        {
            if(head->next != nullptr)
            {
                p = head->next;
                p->previous = nullptr;
            }
            else
            {
                p = nullptr;
            }
            delete head;
            head = p;
            size--;
            return false;
        }

        else if(p == tail)
        {
            p = p->previous;
            p->next = nullptr;
            delete tail;
            tail = p;
            size--;
            return false;
        }

        else
        {
            p->previous->next = p->next;
            p->next->previous = p->previous;
            delete p;
            size--;
            return false;
        }

    }
}

template <class Type>
Type* DoublyLinkedList<Type>::getNextElement(int index) const
{
    if((index >= (size - 1)) || index < -1)
        return nullptr;
    else
    {
        if(index == -1)
            return &(head->item);

        else if(index == (size - 2))
            return &(tail->item);

        else
        {
            Node *p = head;
            for(int i = 0; i < index; i++)
            {
                p = p->next;
            }
            return &(p->next->item);
        }
    }
}

template <class Type>
Type* DoublyLinkedList<Type>::getPreviousElement(int index) const
{
    if((index > size) || (index < 1))
        return nullptr;
    else
    {
        if(index == 1)
            return &(head->item);
        else if(index == size)
            return &(tail->item);
        else
        {
            Node *p = head;
            for(int i = 0; i < index; i++)
            {
                p = p->next;
            }
            return &(p->previous->item);
        }
    }
}
template <class Type>
bool DoublyLinkedList<Type>::isEmpty() const
{
    if(size == 0)
        return true;
    else
        return false;
}
template <class Type>
int DoublyLinkedList<Type>::getSize() const
{
    return size;
}

template <class Type>
bool DoublyLinkedList<Type>::operator==(DoublyLinkedList &dll)
{
    if(dll.size != size)
        return false;
    Node *p, *s;
    p = head;
    s = dll.head;

    if(p == nullptr && s == nullptr)
        return true;

    for(int i = 0; i < size; i++)
    {
        if(p->item != s->item)
            return false;
        else
        {
            p = p->next;
            s = s->next;
        }
    }

    return true;
}
template <class Type>
std::ostream& operator<< (std::ostream &output, const DoublyLinkedList<Type> &bf)
{
    int i = 0;
    while (bf.getSize() != i)
    {
        output << *(bf.getElement(i)) << " ";
        i++;
    }
    return output;
}
#endif //PROJEKT2_DOUBLYLINKEDLIST_H
