#include <iostream>
#include "../include/vector.h"

int main()
{
    Vector<int> v;

    std::cout << "Initially\n";
    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';
    std::cout << "Empty: " << v.empty() << "\n\n";

    // push_back
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "After push_back(10,20,30)\n";
    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';

    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";

    // front and back
    std::cout << "Front: " << v.front() << '\n';
    std::cout << "Back: " << v.back() << "\n\n";

    // operator[]
    v[1] = 99;

    std::cout << "After v[1] = 99\n";
    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";

    // pop_back
    v.pop_back();

    std::cout << "After pop_back()\n";
    std::cout << "Size: " << v.size() << '\n';

    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";

    // resize bigger
    v.resize(5);

    std::cout << "After resize(5)\n";
    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';

    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";

    // resize smaller
    v.resize(2);

    std::cout << "After resize(2)\n";
    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';

    for(size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "\n\n";

    // begin/end
    std::cout << "Using begin() and end()\n";

    for(int* it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }

    std::cout << "\n\n";

    // clear
    v.clear();

    std::cout << "After clear()\n";
    std::cout << "Size: " << v.size() << '\n';
    std::cout << "Capacity: " << v.capacity() << '\n';
    std::cout << "Empty: " << v.empty() << '\n';

    return 0;
}
