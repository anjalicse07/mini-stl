#include <iostream>
#include "../include/map.h"

int main()
{
    Map<int, std::string> m;

    std::cout << "=== INSERT TEST ===\n";
    m.insert(5, "five");
    m.insert(10, "ten");
    m.insert(15, "fifteen");
    m.insert(20, "twenty");

    m.print();

    std::cout << "\n=== CONTAINS TEST ===\n";
    std::cout << "Contains 10: " << m.contains(10) << "\n";
    std::cout << "Contains 99: " << m.contains(99) << "\n";

    std::cout << "\n=== GET TEST ===\n";
    std::cout << "Get 20: " << m.get(20) << "\n";

    std::cout << "\n=== OPERATOR[] TEST (UPDATE) ===\n";
    m[10] = "TEN_UPDATED";

    m.print();

    std::cout << "Get 10: " << m.get(10) << "\n";

    std::cout << "\n=== OPERATOR[] TEST (INSERT NEW KEY) ===\n";
    m[99] = "ninety-nine";

    m.print();

    std::cout << "\n=== SET TEST ===\n";
    m.set(15, "FIFTEEN_UPDATED");
    std::cout << "Get 15: " << m.get(15) << "\n";

    std::cout << "\n=== REMOVE TEST ===\n";
    m.remove(5);
    m.print();

    std::cout << "\n=== REMOVE NON-EXISTING (EXPECT EXCEPTION) ===\n";
    try
    {
        m.remove(100);
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n=== GET AFTER REMOVE ===\n";
    try
    {
        std::cout << m.get(5) << "\n";
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}