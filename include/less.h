#pragma once

template<typename T>
struct Less
{
    bool operator()(const T&a,const T&b)const
    {
        return a<b;
    }
};