#pragma once
#include<iostream>
using namespace std;

template<typename T1,typename T2>
struct Pair
{
    T1 first;
    T2 second;

    Pair():first(),second()
    {}
    Pair(const T1&f,const T2& s):first(f),second(s)
    {}
    Pair(const Pair& other):first(other.first),second(other.second)
    {}
    Pair& operator=(const Pair& other)
    {
        if(this!=&other)
        {
        first=other.first;
        second=other.second;
        }
        return *this;
    }

    bool operator==(const Pair& o)const
    {
        return (first==o.first && second==o.second);
    }

    bool operator!=(const Pair& o)const
    {
        return !(*this==o);
    }

    bool operator<(const Pair& p)const
    {
        if(first>p.first)
        return false;
        if(first<p.first)
        return true;
        return second<p.second;
    }

    bool operator>(const Pair& p)const
    {
        return (p<*this);
    }

    bool operator<=(const Pair& p) const
    {
        return !(*this>p);
    }

    bool operator>=(const Pair& p)const
    {
        return !(*this<p);
    }  
};

template<typename T1,typename T2>
ostream& operator<<(ostream& print,const Pair<T1,T2>& p)
{
    print<<"("<<p.first<<","<<p.second<<")";
    return print;
}

template<typename T1,typename T2>
Pair<T1,T2> make_Pair(const T1& f,const T2& s)
{
    return Pair<T1,T2>(f,s);
}