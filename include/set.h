#pragma once
#include "bst.h"
#include <iostream>

template<typename T>
class Set
{
private:
    BST<T> tree;

public:
    void insert(const T& value)
    {
        if (!tree.contains(value))
            tree.insert(value);
    }

    void remove(const T& value)
    {
        tree.remove(value);
    }

    bool contains(const T& value) const
    {
        return tree.contains(value);
    }

    void print() const
    {
        tree.inorder();
        std::cout << "\n";
    }
};