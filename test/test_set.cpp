#include <iostream>
#include "../include/set.h"

int main()
{
    Set<int> s;

    std::cout << "=== INSERT TEST ===\n";
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(15);

    std::cout << "After inserts: ";
    s.print();

    std::cout << "\n=== DUPLICATE INSERT TEST ===\n";
    s.insert(10);
    s.insert(5);

    std::cout << "After duplicates: ";
    s.print();

    std::cout << "\n=== CONTAINS TEST ===\n";
    std::cout << "Contains 10: " << s.contains(10) << "\n";
    std::cout << "Contains 99: " << s.contains(99) << "\n";

    std::cout << "\n=== REMOVE TEST ===\n";
    s.remove(10);
    std::cout << "After removing 10: ";
    s.print();

    std::cout << "\n=== REMOVE ROOT TEST ===\n";
    s.remove(15);
    std::cout << "After removing 15: ";
    s.print();

    std::cout << "\n=== FINAL STATE ===\n";
    s.print();

    return 0;
}