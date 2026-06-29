#pragma once
#include<cstddef>


template<typename T>
class LinkedList{
    private:
    struct Node
{
    T data;
    Node* next;

    Node(T value):data(value),next(nullptr)
    {}
};

    Node* head;
    size_t sz;

    public:
    LinkedList();
    ~LinkedList();
    
    size_t size()const;
    bool empty()const;

    void push_front(const T& value);
};

template<typename T>
LinkedList<T>::LinkedList()
{
    head=nullptr;
    sz=0;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Node* temp=head;
    while(temp!=nullptr)
    {
        Node* c=temp->next;
        delete temp;
        temp=c;
    }
    head=nullptr;
    sz=0;
}

template<typename T>
void LinkedList<T>::push_front(const T& value)
{
    Node* temp=new Node(value);

    temp->next=head;
    head=temp;
    sz++;
}

template<typename T>
size_t LinkedList<T>::size()const{
    return sz;
}

template<typename T>
bool LinkedList<T>::empty()const{
    return sz==0;
}


