#pragma once
#include "linked_list.h"

template<typename T>
class Queue
{
private:
    LinkedList<T> list;

public:
    Queue();

    bool empty() const;
    size_t size() const;

    T& front();
    const T& front() const;

    void push(const T& value);
    void pop();
};

template<typename T>
Queue<T>::Queue()
{
}

template<typename T>
bool Queue<T>::empty() const
{
    return list.empty();
}

template<typename T>
size_t Queue<T>::size() const
{
    return list.size();
}

template<typename T>
T& Queue<T>::front()
{
    return list.front();
}

template<typename T>
const T& Queue<T>::front() const
{
    return list.front();
}

template<typename T>
void Queue<T>::push(const T& value)
{
    list.push_back(value);
}

template<typename T>
void Queue<T>::pop()
{
    list.pop_front();
}