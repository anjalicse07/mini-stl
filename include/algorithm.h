#pragma once
#include<cstddef>

namespace mini_stl{
template<typename it,typename T>
it find(it first,it last,const T& value)
{
    while(first!=last)
    {
        if(*first==value)
        {
            return first;
        }
        ++first;
    }
    return last;
}

template<typename it,typename T>
size_t count(it first,it last,const T& value)
{
    size_t cnt=0;
    while(first!=last)
    {
        if(*first==value)
        cnt++;
        ++first;
    }
    return cnt;
}

template<typename T>
void swap(T& a,T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<typename it>
void reverse(it first,it last)
{
    if(first==last)
    return;
    while(first!=last)
    {
        --last;
        swap(*first,*last);
        if(first==last)
        break;
        ++first;
    }
}

template<typename it>
it max_element(it first,it last)
{
    if(first==last)
    return last;
    
    it maxi=first;
    ++first;
    while(first!=last)
    {
        if(*first>*maxi)
        {
            maxi=first;
        }
        ++first;
    }
    return maxi;
}

template<typename it>
it min_element(it first,it last)
{
    if(first==last)
    return last;

    it mini=first;
    ++first;
    while(first!=last)
    {
        if(*first<*mini)
        {
            mini=first;
        }
        ++first;
    }
    return mini;
}



}