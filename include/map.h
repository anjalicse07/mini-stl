#pragma once
#include "bst.h"
#include "pair.h"
#include <stdexcept>

template<typename K, typename V>
class Map
{
private:
    BST<Pair<K, V>> tree;

    Pair<K, V> makeDummy(const K& key) const
    {
        return Pair<K, V>(key, V());
    }

public:
    void insert(const K& key, const V& value)
    {
        Pair<K, V> dummy = makeDummy(key);

        if (tree.contains(dummy))
            tree.remove(dummy);

        tree.insert(Pair<K, V>(key, value));
    }

    void remove(const K& key)
    {
        Pair<K, V> dummy = makeDummy(key);

        if (!tree.contains(dummy))
            throw std::runtime_error("Key not found");

        tree.remove(dummy);
    }

    bool contains(const K& key)
    {
        return tree.contains(makeDummy(key));
    }

    V get(const K& key)
    {
        Pair<K, V> dummy = makeDummy(key);

        Pair<K, V>* node = tree.find(dummy);

        if (!node)
            throw std::runtime_error("Key not found");

        return node->getsecond();
    }

    void set(const K& key, const V& value)
    {
        Pair<K, V> dummy = makeDummy(key);

        Pair<K, V>* node = tree.find(dummy);

        if (!node)
            throw std::runtime_error("Key not found");

        node->setsecond(value);
    }

    V& operator[](const K& key)
   {
    Pair<K, V> dummy = makeDummy(key);

    Pair<K, V>* node = tree.find(dummy);

    if (!node)
    {
        tree.insert(Pair<K, V>(key, V()));
        node = tree.find(dummy);   // now guaranteed
    }

    return node->getsecond();
  }

    void print()
    {
        tree.inorder();
    }
};