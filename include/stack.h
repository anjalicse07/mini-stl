#ifndef STACK_H
#define STACK_H

#include"Vector.h"
#include<stdexcept>

template <typename T>
class Stack
{
    private:
    Vector<T> data;

    public:
    Stack()=default;

    void push(const T& value);
    void pop();

    size_t size()const;
    bool empty()const;
    T& top();
    const T& top()const;


};

template<typename T>
void Stack<T>::push(const T& value)
{
    data.push_back(value);
}

template<typename T>
size_t Stack<T>::size() const
{
    return data.size();
}

template<typename T>
bool Stack<T>::empty()const
{
    return data.empty();
}

template<typename T>
T& Stack<T>::top()
{
    if(empty())
    {
        throw std::out_of_range("stack is empty");
    }
    return data.back();
}

template<typename T>
const T& Stack<T>::top()const
{
    if(empty())
    {
        throw std::out_of_range("stack is empty");
    }
    return data.back();
}

template<typename T>
void Stack<T>::pop()
{
    if(empty())
    {
        throw std::out_of_range("stack is empty");
    }
    data.pop_back();
}


#endif