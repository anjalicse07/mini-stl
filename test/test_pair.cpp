#include <iostream>
#include <string>
#include "../include/pair.h"

int main()
{
    std::cout << "===== Constructors =====\n";

    Pair<int, std::string> p1;
    std::cout << p1.first << " " << p1.second << '\n';

    Pair<int, std::string> p2(10, "Alice");
    std::cout << p2.first << " " << p2.second << '\n';

    Pair<int, std::string> p3(p2);
    std::cout << p3.first << " " << p3.second << '\n';

    std::cout << "\n===== Assignment =====\n";

    Pair<int, std::string> p4;
    p4 = p2;
    std::cout << p4.first << " " << p4.second << '\n';

    std::cout << "\n===== Equality =====\n";

    std::cout << (p2 == p3) << '\n';
    std::cout << (p2 != p3) << '\n';

    Pair<int, std::string> p5(20, "Bob");

    std::cout << (p2 == p5) << '\n';
    std::cout << (p2 != p5) << '\n';

    std::cout << "\n===== Comparison =====\n";

    Pair<int, int> a(1, 100);
    Pair<int, int> b(2, 50);
    Pair<int, int> c(1, 200);

    std::cout << "a < b : " << (a < b) << '\n';
    std::cout << "b > a : " << (b > a) << '\n';

    std::cout << "a < c : " << (a < c) << '\n';
    std::cout << "c > a : " << (c > a) << '\n';

    std::cout << "a <= c : " << (a <= c) << '\n';
    std::cout << "c >= a : " << (c >= a) << '\n';

    std::cout << "a <= a : " << (a <= a) << '\n';
    std::cout << "a >= a : " << (a >= a) << '\n';

    auto p = make_Pair(5, std::string("Hello"));
    std::cout << p << '\n';

    return 0;
}