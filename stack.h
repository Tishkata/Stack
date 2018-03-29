#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T>* previous;
    Node(T _data, Node<T>* _previous = nullptr):data(_data), previous(_previous){}
};

template <typename T>
class Stack
{
// the public constructors and operators.
public:
    Stack();
    Stack(const Stack& other);
    Stack<T>& operator =(const Stack &other);
    ~Stack();

// the public methods
public:
    bool isEmpty() const;
    void push(const T& data);
    void pop();
    T& top() const;
    size_t size() const;
    void print() const;

// the private methods
private:
    void destroy();
    void copy(const Stack& other);

// the private members
private:
    Node<T>* m_top;
    size_t m_size;

};

template <typename T>
void Stack<T>::destroy()
{
    while(!isEmpty())
    {
        this->pop();
    }
}

template <typename T>
void Stack<T>::copy(const Stack& other)
{
    m_size = other.m_size;
    Node<T> *ours, *theirs;
    m_top = new Node<T>(other.m_top->data);
    ours = m_top;
    theirs = other.m_top->previous;
    while(theirs)
    {
        ours->previous = new Node<T>(theirs->data);
        ours = ours->previous;
        theirs = theirs->previous;
    }
}

template <typename T>
Stack<T>::Stack():m_top(nullptr), m_size(0)
{

}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <typename T>
Stack<T>& Stack<T>::operator =(const Stack& other)
{
    if(this != &other)
    {
        copy(other);
    }
    return* this;
}

template <typename T>
Stack<T>::~Stack()
{
    destroy();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return this->m_size == 0;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    Node<T>* temp = new Node<T>(data);
    temp->previous = this->m_top;
    this->m_top = temp;
    this->m_size++;
}

template <typename T>
void Stack<T>::pop()
{
    if(isEmpty())
    {
        return;
    }
    Node<T>* temp;
    temp = this->m_top;
    this->m_top = this->m_top->previous;
    delete[] temp;
    this->m_size--;
}

template <typename T>
T& Stack<T>::top() const
{
    return this->m_top->data;
}

template <typename T>
size_t Stack<T>::size() const
{
    return this->m_size;
}

template <typename T>
void Stack<T>::print() const
{
    Node<T>* temp = m_top;
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->previous;
    }
}

#endif // STACK_H
