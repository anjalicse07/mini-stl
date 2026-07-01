#include <iostream>
#include "../include/linked_list.h"

int main()
{
    LinkedList<int> list;

    std::cout << "Initially\n";
    std::cout << "Empty: " << list.empty() << '\n';
    std::cout << "Size : " << list.size() << "\n\n";

    list.push_front(20);
    list.push_front(10);

    list.push_back(30);
    list.push_back(40);

    std::cout << "After push operations\n";
    std::cout << "Front : " << list.front() << '\n';
    std::cout << "Back  : " << list.back() << '\n';
    std::cout << "Size  : " << list.size() << "\n\n";

    list.insert(2,25);

    std::cout << "After insert\n";

    while(!list.empty())
    {
        std::cout << list.front() << " ";
        list.pop_front();
    }

    std::cout << "\n\n";

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.erase(2);

    std::cout << "After erase\n";

    while(!list.empty())
    {
        std::cout << list.front() << " ";
        list.pop_front();
    }

    std::cout << "\n\n";

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    list.reverse();

    std::cout << "After reverse\n";

    while(!list.empty())
    {
        std::cout << list.front() << " ";
        list.pop_front();
    }

    std::cout << '\n';

    return 0;
}