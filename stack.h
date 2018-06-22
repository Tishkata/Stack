#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

template <class TYPE>
struct Node
{
    TYPE m_data;
    Node<TYPE>* m_previous;
    Node(TYPE data, Node<TYPE>* previous = nullptr) : m_data(data), m_previous(previous) {}
};

template <class TYPE>
class Stack
{

// the public constructors and operators.
public:
    Stack(); // default constructor
    Stack(const Stack& other); // copy constructor
    Stack<TYPE>& operator =(const Stack& other); // assignment operator
    bool operator ==(const Stack& other); // returns true if two stacks are equal
    bool operator !=(const Stack& other); // returns true if two stacks are different
    bool operator <(const Stack& other); // returns true if first stack is smaller than second stack
    bool operator >(const Stack& other); // returns true if first stack is bigger than second stack
    bool operator <=(const Stack& other); // returns true if first stackis smaller than or equal to second stack
    bool operator >=(const Stack& other); // returns true if first stack is bigger than or equal to second stack
    ~Stack(); // destructor

// the public methods
public:
    void push(const TYPE& data); // adds element of stack
    void pop(); // removes element of stack
    void swap(Stack& other); // swaps two stacks

    bool empty() const; // returns true if stack is empty
    TYPE& top() const; // returns top data of stack
    size_t size() const; // returns size of stack
    void print() const; // prints stack

// the private methods
private:
    void destroy(); // destroys stack
    void copy(const Stack& other); // copies one stack to another

// the private members
private:
    Node<TYPE>* m_top; // top of stack
    size_t m_size; // size of stack
};

template <class TYPE>
Stack<TYPE>::Stack() : m_top(nullptr), m_size(0)
{

}

template <class TYPE>
Stack<TYPE>::Stack(const Stack& other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <class TYPE>
Stack<TYPE>& Stack<TYPE>::operator =(const Stack& other)
{
    if(this != &other)
    {
        copy(other);
    }

    return* this;
}

template <class TYPE>
bool Stack<TYPE>::operator ==(const Stack& other)
{
    if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_top;
        Node<TYPE>* theirs = other.m_top;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data == theirs->m_data)
            {
                ours = ours->m_previous;
                theirs = theirs->m_previous;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool Stack<TYPE>::operator !=(const Stack& other)
{
    return !(operator ==(other));
}

template <class TYPE>
bool Stack<TYPE>::operator <(const Stack& other)
{
    if(m_size < other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_top;
        Node<TYPE>* theirs = other.m_top;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data < theirs->m_data)
            {
                ours = ours->m_previous;
                theirs = theirs->m_previous;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool Stack<TYPE>::operator >(const Stack& other)
{
    if(m_size > other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_top;
        Node<TYPE>* theirs = other.m_top;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data > theirs->m_data)
            {
                ours = ours->m_previous;
                theirs = theirs->m_previous;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool Stack<TYPE>::operator <=(const Stack& other)
{
    return !(operator >(other));
}

template <class TYPE>
bool Stack<TYPE>::operator >=(const Stack& other)
{
    return !(operator <(other));
}

template <class TYPE>
Stack<TYPE>::~Stack()
{
    destroy();
}

template <class TYPE>
void Stack<TYPE>::push(const TYPE& data)
{
    Node<TYPE>* temp = new Node<TYPE>(data);
    temp->m_previous = m_top;
    m_top = temp;
    m_size++;
}

template <class TYPE>
void Stack<TYPE>::pop()
{
    if(empty() == false)
    {
        Node<TYPE>* temp;
        temp = m_top;
        m_top = m_top->m_previous;
        delete temp;
        m_size--;
    }
}

template <class TYPE>
void Stack<TYPE>::swap(Stack& other)
{
    Node<TYPE>* ours = m_top;
    size_t temp = m_size;
    if(this != &other)
    {
        copy(other);
    }
    other.m_top = ours;
    other.m_size = temp;
}

template <class TYPE>
bool Stack<TYPE>::empty() const
{
    return m_size == 0;
}

template <class TYPE>
TYPE& Stack<TYPE>::top() const
{
    return m_top->m_data;
}

template <class TYPE>
size_t Stack<TYPE>::size() const
{
    return m_size;
}

template <class TYPE>
void Stack<TYPE>::print() const
{
    Node<TYPE>* temp = m_top;
    while(temp != nullptr)
    {
        cout << temp->m_data << " ";
        temp = temp->m_previous;
    }
}

template <class TYPE>
void Stack<TYPE>::destroy()
{
    while(empty() == false)
    {
        pop();
    }
}

template <class TYPE>
void Stack<TYPE>::copy(const Stack& other)
{
    m_size = other.m_size;
    Node<TYPE> *ours, *theirs;
    m_top = new Node<TYPE>(other.m_top->m_data);
    ours = m_top;
    theirs = other.m_top->m_previous;
    while(theirs != nullptr)
    {
        ours->m_previous = new Node<TYPE>(theirs->m_data);
        ours = ours->m_previous;
        theirs = theirs->m_previous;
    }
}

#endif // STACK_H
