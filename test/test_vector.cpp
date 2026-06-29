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
    cout << "========== FIND ==========\n";

    Vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    auto it1 = mini_stl::find(v.begin(), v.end(), 30);

    if(it1 != v.end())
        cout << "Found: " << *it1 << endl;
    else
        cout << "Not Found\n";

    auto it2 = mini_stl::find(v.begin(), v.end(), 100);

    if(it2 != v.end())
        cout << "Found: " << *it2 << endl;
    else
        cout << "Not Found\n";


    cout << "\n========== COUNT ==========\n";

    Vector<int> v2;

    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(10);
    v2.push_back(30);
    v2.push_back(10);

    cout << "Count(10): "
         << mini_stl::count(v2.begin(), v2.end(), 10)
         << endl;

    cout << "Count(20): "
         << mini_stl::count(v2.begin(), v2.end(), 20)
         << endl;

    cout << "Count(100): "
         << mini_stl::count(v2.begin(), v2.end(), 100)
         << endl;


    cout << "\n========== SWAP ==========\n";

    int a = 10;
    int b = 20;

    cout << "Before: " << a << " " << b << endl;

    mini_stl::swap(a, b);

    cout << "After : " << a << " " << b << endl;


    cout << "\n========== REVERSE ==========\n";

    Vector<int> v3;

    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    v3.push_back(40);
    v3.push_back(50);

    cout << "Before: ";
    printVector(v3);

    mini_stl::reverse(v3.begin(), v3.end());

    cout << "After : ";
    printVector(v3);


    cout << "\n========== MAX ELEMENT ==========\n";

    Vector<int> v4;

    v4.push_back(10);
    v4.push_back(40);
    v4.push_back(20);
    v4.push_back(70);
    v4.push_back(30);

    auto max_it =
        mini_stl::max_element(v4.begin(), v4.end());

    if(max_it != v4.end())
    {
        cout << "Max = " << *max_it << endl;
    }


    cout << "\n========== MIN ELEMENT ==========\n";

    auto min_it =
        mini_stl::min_element(v4.begin(), v4.end());

    if(min_it != v4.end())
    {
        cout << "Min = " << *min_it << endl;
    }


    cout << "\n========== EMPTY VECTOR TEST ==========\n";

    Vector<int> empty;

    auto max_empty =
        mini_stl::max_element(empty.begin(), empty.end());

    auto min_empty =
        mini_stl::min_element(empty.begin(), empty.end());

    cout << "max_element returns end(): "<< (max_empty == empty.end())<< endl;
    cout << "min_element returns end(): "<< (min_empty == empty.end())<< endl;
    
    cout << "\n========== SINGLE ELEMENT TEST ==========\n";

    Vector<int> one;

    one.push_back(99);

    auto max_one =
        mini_stl::max_element(one.begin(), one.end());

    auto min_one =
        mini_stl::min_element(one.begin(), one.end());

    cout << "Max = " << *max_one << endl;
    cout << "Min = " << *min_one << endl;

    return 0;
}