#pragma once
# include <cstddef>
# include <stdexcept>
# include "iterator.h"

template<typename T>
class Vector
{
private:
 T* data;
 size_t sz;
 size_t cap;

public:
 Vector();
 ~Vector();

 size_t size() const;
 size_t capacity() const;
 bool empty() const;

 void reserve(size_t newcap);
 void clear();
 void resize(size_t newsz);

 void push_back(const T& value);
 void pop_back();

 T& front();
 const T& front() const;
 T& back();
 const T& back() const;

 VectorIterator<T> begin();
 VectorIterator<T> end();

 Vector(const Vector& other);
 Vector(Vector&& other) noexcept;

 T& operator[](size_t idx);
 const T& operator[](size_t idx) const;
 Vector& operator=(const Vector& other);
 Vector& operator=(Vector&& other) noexcept;
 bool operator==(const Vector& other)const;
 bool operator!=(const Vector& other)const;

 T& at(size_t idx);
const T& at(size_t idx) const;
};

template<typename T>
Vector<T>::Vector()
{
    data=nullptr;
    sz=0;
    cap=0;
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template<typename T>
size_t Vector<T>::size() const
{
return sz;
}

template<typename T>
size_t Vector<T>::capacity() const
{ 
return cap;
}

template<typename T>
bool Vector<T>::empty() const
{
    return (sz==0);
}

template<typename T>
void Vector<T>::reserve(size_t newcap)
{
if(newcap<=cap)
return;
T* newdata=new T[newcap];
for(size_t i=0;i<sz;i++)
{
    newdata[i]=data[i];
}
delete[] data;
data=newdata;
cap=newcap;
}

template<typename T>
void Vector<T>::clear()
{
    sz=0;
}

template<typename T>
void Vector<T>::push_back(const T& value)
{
    if(sz==cap)
    {
        if(cap==0)
        {
            reserve(1);
        }
        else
        {
            reserve(cap*2);
        }
    }
    data[sz]=value;
    sz++;
}

template <typename T>
const T& Vector<T>::operator[](size_t idx) const
{
    return data[idx];
}

template <typename T>
T& Vector<T>::operator[](size_t idx) 
{
    return data[idx];
}

template<typename T>
void Vector<T>::pop_back()
{
    if(sz>0){
    sz--;
    }
}

template<typename T>
const T& Vector<T>::front() const
{
    return data[0];
}

template<typename T>
T& Vector<T>::front()
{
    return data[0];
}

template<typename T>
const T& Vector<T>::back() const
{
    return data[sz-1];
}

template<typename T>
T& Vector<T>::back() 
{
    return data[sz-1];
}

template<typename T>
VectorIterator<T> Vector<T>::begin()
{
    return VectorIterator<T>(data);
}

template<typename T>
VectorIterator<T> Vector<T>::end()
{
    return VectorIterator<T>(data+sz);
}

template<typename T>
void Vector<T>::resize(size_t newsz)
{
    if(newsz>cap)
    {
        reserve(newsz);
    }
    if(newsz>sz)
    {
        for(size_t i=sz;i<newsz;i++)
        {
            data[i]=T();
        }
    }
    sz=newsz;
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
    sz=other.sz;
    cap=other.cap;

    data=new T[cap];

    for(size_t i=0;i<sz;i++)
    {
        data[i]=other.data[i];
    }
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
    if(this==&other)
    {
        return *this;
    }
    delete[] data;
    sz=other.sz;
    cap=other.cap;
    data=new T[cap];
    for(size_t i=0;i<sz;i++)
    {
        data[i]=other.data[i];
    }
    return *this;
}

template<typename T>
Vector<T>::Vector(Vector&& other) noexcept
{
    data=other.data;
    cap=other.cap;
    sz=other.sz;

    other.data=nullptr;
    other.sz=0;
    other.cap=0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept
{
if(this!=&other)
{
    delete[] data;
    data=other.data;
    sz=other.sz;
    cap=other.cap;

    other.data=nullptr;
    other.sz=0;
    other.cap=0;
}
return *this;
}

template<typename T>
bool Vector<T>::operator==(const Vector& other)const
{
if(sz!=other.sz)
return false;
for(size_t i=0;i<sz;i++)
{
    if(data[i]!=other.data[i])
    return false;
}
return true;
}

template<typename T>
bool Vector<T>::operator!=(const Vector& other)const
{
return !(*this==other);
}

template<typename T>
T& Vector<T>::at(size_t idx)
{
    if(sz<=idx)
    {
        throw std::out_of_range("Vector index out of range");
    }
    return data[idx];

}

template<typename T>
const T& Vector<T>::at(size_t idx) const
{
    if(idx>=sz)
    {
        throw std::out_of_range("Vector index out of range");
    }
    return data[idx];

}