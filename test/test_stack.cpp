#include <iostream>
#include "../include/stack.h"

using namespace std;

int main()
{
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Top: " << s.top() << endl;

    s.pop();

    cout << "Empty: " << s.empty() << endl;

    try
    {
        s.pop();
    }
    catch(const out_of_range& e)
    {
        cout << e.what() << endl;
    }

    Stack<int> st;

for(int i=1;i<=5;i++)
    st.push(i);

while(!st.empty())
{
    cout << st.top() << " ";
    st.pop();
}

    return 0;
}