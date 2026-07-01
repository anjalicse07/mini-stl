#include <iostream>
#include "../include/bst.h"


void testBSTIterator()
{
    std::cout << "\n==============================\n";
    std::cout << "     BST ITERATOR TEST\n";
    std::cout << "==============================\n\n";

    BST<int> tree;

    int values[] = {40,20,60,10,30,50,70};

    for(int x : values)
        tree.insert(x);


    std::cout << "Forward Traversal:\n";

    for(auto it = tree.begin(); it != tree.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n\n";


    std::cout << "Prefix ++ Test:\n";

    auto it = tree.begin();

    std::cout << *it << "\n";

    ++it;
    std::cout << *it << "\n";

    ++it;
    std::cout << *it << "\n";

    ++it;
    std::cout << *it << "\n\n";


    std::cout << "Postfix ++ Test:\n";

    it = tree.begin();

    std::cout << *(it++) << " ";
    std::cout << *(it++) << " ";
    std::cout << *(it++) << " ";

    std::cout << "\nCurrent : " << *it << "\n\n";


    std::cout << "Prefix -- Test:\n";

    it = tree.find(60);

    std::cout << *it << "\n";

    --it;
    std::cout << *it << "\n";

    --it;
    std::cout << *it << "\n\n";


    std::cout << "Postfix -- Test:\n";

    it = tree.find(50);

    std::cout << *(it--) << " ";
    std::cout << *(it--) << " ";

    std::cout << "\nCurrent : " << *it << "\n\n";


    std::cout << "Find Test:\n";

    auto f = tree.find(30);

    if(f != tree.end())
        std::cout << "30 Found\n";
    else
        std::cout << "30 Not Found\n";


    f = tree.find(100);

    if(f == tree.end())
        std::cout << "100 Not Found\n";


    std::cout << "\nIterator Comparison Test:\n";

    auto a = tree.begin();
    auto b = tree.begin();

    if(a == b)
        std::cout << "a == b\n";

    ++b;

    if(a != b)
        std::cout << "a != b\n";


    std::cout << "\nSingle Node Test:\n";

    BST<int> single;

    single.insert(100);

    auto s = single.begin();

    std::cout << *s << "\n";

    ++s;

    if(s == single.end())
        std::cout << "Reached end successfully\n";


    std::cout << "\nEmpty Tree Test:\n";

    BST<int> empty;

    if(empty.begin() == empty.end())
        std::cout << "Empty tree iterator works\n";


    std::cout << "\n==============================\n";
    std::cout << " ALL ITERATOR TESTS COMPLETE\n";
    std::cout << "==============================\n";
}


int main()
{
    testBSTIterator();

    return 0;
}