#pragma once

template<typename T>
class VectorIterator{
private:
T* ptr;

public:
VectorIterator(T* p);

T& operator*();

VectorIterator& operator++();
VectorIterator operator++(int);
VectorIterator& operator--();
VectorIterator operator--(int);

bool operator!=(const VectorIterator& other)const;
bool operator==(const VectorIterator& other)const;
};

template<typename T>
VectorIterator<T>::VectorIterator(T* p)
{
    ptr = p;
}

template<typename T>
T& VectorIterator<T>::operator*()
{
    return*ptr;
}

template<typename T>
VectorIterator<T>& VectorIterator<T>::operator++()
{
    ++ptr;
    return *this;
}

template<typename T>
bool VectorIterator<T>::operator!=(const VectorIterator<T>& other) const
{
    return ptr!=other.ptr;
}

template<typename T>
bool VectorIterator<T>::operator==(const VectorIterator& other) const{
    return ptr==other.ptr;
}

template<typename T>
VectorIterator<T> VectorIterator<T>::operator++(int)
{
    VectorIterator<T> temp=*this;
    ++ptr;
    return temp;
}

template<typename T>
VectorIterator<T>& VectorIterator<T>::operator--()
{
    --ptr;
    return *this;
}

template<typename T>
VectorIterator<T> VectorIterator<T>::operator--(int)
{
    VectorIterator<T> temp=*this;
    --ptr;
    return temp;
}