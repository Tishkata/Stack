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
    Node(TYPE data, Node<TYPE>* previous = nullptr) : m_data(data), m_previous(previous){}
};

template <class TYPE>
class Stack
{
// the public constructors and operators.
public:
    Stack();
    Stack(const Stack& other);
    Stack<TYPE>& operator =(const Stack &other);
    ~Stack();

// the public methods
public:
    bool IsEmpty() const;
    void Push(const TYPE& data);
    void Pop();
    TYPE& Top() const;
    size_t Size() const;
    void Print() const;

// the private methods
private:
    void Destroy();
    void Copy(const Stack& other);

// the private members
private:
    Node<TYPE>* m_top;
    size_t m_size;

};

template <class TYPE>
void Stack<TYPE>::Destroy()
{
    while(!IsEmpty())
    {
        this->Pop();
    }
}

template <class TYPE>
void Stack<TYPE>::Copy(const Stack& other)
{
    m_size = other.m_size;
    Node<TYPE> *ours, *theirs;
    m_top = new Node<TYPE>(other.m_top->m_data);
    ours = m_top;
    theirs = other.m_top->m_previous;
    while(theirs)
    {
        ours->m_previous = new Node<TYPE>(theirs->m_data);
        ours = ours->m_previous;
        theirs = theirs->m_previous;
    }
}

template <class TYPE>
Stack<TYPE>::Stack() : m_top(nullptr), m_size(0)
{

}

template <class TYPE>
Stack<TYPE>::Stack(const Stack& other)
{
    if(this != &other)
    {
        Copy(other);
    }
}

template <class TYPE>
Stack<TYPE>& Stack<TYPE>::operator =(const Stack& other)
{
    if(this != &other)
    {
        Copy(other);
    }
    return* this;
}

template <class TYPE>
Stack<TYPE>::~Stack()
{
    Destroy();
}

template <class TYPE>
bool Stack<TYPE>::IsEmpty() const
{
    return this->m_size == 0;
}

template <class TYPE>
void Stack<TYPE>::Push(const TYPE& data)
{
    Node<TYPE>* temp = new Node<TYPE>(data);
    temp->m_previous = this->m_top;
    this->m_top = temp;
    this->m_size++;
}

template <class TYPE>
void Stack<TYPE>::Pop()
{
    if(IsEmpty())
    {
        return;
    }
    Node<TYPE>* temp;
    temp = this->m_top;
    this->m_top = this->m_top->m_previous;
    delete[] temp;
    this->m_size--;
}

template <class TYPE>
TYPE& Stack<TYPE>::Top() const
{
    return this->m_top->m_data;
}

template <class TYPE>
size_t Stack<TYPE>::Size() const
{
    return this->m_size;
}

template <class TYPE>
void Stack<TYPE>::Print() const
{
    Node<TYPE>* temp = m_top;
    while(temp)
    {
        cout << temp->m_data << " ";
        temp = temp->m_previous;
    }
}

#endif // STACK_H
