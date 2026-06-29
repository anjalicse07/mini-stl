#include <iostream>
#include "../include/vector.h"
#include "../include/algorithm.h"

using namespace std;

void printVector(Vector<int>& v)
{
    for(auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "===== FIND =====" << endl;

    auto it = mini_stl::find(v.begin(), v.end(), 30);

    if(it != v.end())
        cout << *it << endl;

    cout << "\n===== COUNT =====" << endl;

    cout << mini_stl::count(v.begin(), v.end(), 30)
         << endl;

    cout << "\n===== SWAP =====" << endl;

    int a = 10;
    int b = 20;

    mini_stl::swap(a, b);

    cout << a << " " << b << endl;

    cout << "\n===== REVERSE =====" << endl;

    printVector(v);

    mini_stl::reverse(v.begin(), v.end());

    printVector(v);

    cout << "\n===== MAX ELEMENT =====\n";

Vector<int> v4;

v4.push_back(10);
v4.push_back(40);
v4.push_back(20);
v4.push_back(70);
v4.push_back(30);

auto max_it = mini_stl::max_element(v4.begin(), v4.end());

if(max_it != v4.end())
{
    cout << "Max = " << *max_it << endl;
}

cout << "\n===== MIN ELEMENT =====\n";

auto min_it = mini_stl::min_element(v4.begin(), v4.end());

if(min_it != v4.end())
{
    cout << "Min = " << *min_it << endl;
}

    return 0;
}



