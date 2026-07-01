#include <iostream>
#include "../include/queue.h"

int main()
{
    Queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Front: " << q.front() << '\n';
    std::cout << "Size : " << q.size() << '\n';

    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
    }

    std::cout << '\n';
}