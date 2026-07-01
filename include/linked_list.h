#pragma once
#include<cstddef>
#include<stdexcept>


template<typename T>
class LinkedList{
    private:
    struct Node
{
    T data;
    Node* next;

    Node(const T& value):data(value),next(nullptr)
    {}
};

    Node* head;
    size_t sz;

    public:
    LinkedList();
    ~LinkedList();
    
    size_t size()const;
    bool empty()const;

    T& front();
    const T& front() const;

    T& back();
    const T& back() const;

    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    void insert(size_t index, const T& value);
    void erase(size_t index);
    void reverse();

    LinkedList(const LinkedList& other);
    LinkedList& operator=(const LinkedList& other);

    LinkedList(LinkedList&& other);
    LinkedList& operator=(LinkedList&& other);
};

template<typename T>
LinkedList<T>::LinkedList():head(nullptr),sz(0)
{
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

template<typename T>
T& LinkedList<T>::front()
{
    if(empty())
{
    throw std::out_of_range("List is empty");
}
    return head->data;
}

template<typename T>
const T& LinkedList<T>::front()const
{
    if(empty())
{
    throw std::out_of_range("List is empty");
}
    return head->data;
}

template<typename T>
T& LinkedList<T>::back()
{
    if(empty())
{
    throw std::out_of_range("List is empty");
}
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp->data;
}

template<typename T>
const T& LinkedList<T>::back()const
{
    if(empty())
{
    throw std::out_of_range("List is empty");
}
    Node* temp=head;
    while(temp->next!=nullptr)
    {
        temp=temp->next;
    }
    return temp->data;
}

template<typename T>
void LinkedList<T>::push_back(const T& value)
{
    Node* temp=new Node(value);
    if(head==nullptr)
    {
        head=temp;
    }
    else
    {
    Node* curr=head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=temp;
    }
    sz++;
}

template<typename T>
void LinkedList<T>::pop_front()
{
   if(head==nullptr)
   {
    return;
   }
   Node* temp=head;
   head=head->next;
   delete(temp);
   sz--;

}

template<typename T>
void LinkedList<T>::pop_back()
{
    if(head==nullptr)
    {
        return;
    }
    else if(head->next==nullptr)
    {
        Node* temp=head;
        head=nullptr;
        delete temp;
        sz--;
    }
    else
    {
        Node* temp=head;
        Node* prev=head;
        while(temp->next!=nullptr)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=nullptr;
        delete temp;
        sz--;
    }
}

template<typename T>
void LinkedList<T>::insert(size_t index,const T& value)
{
    if(index>sz)
    {
        throw std::out_of_range("Index out of range");
    }
    if(index==0)
    {
        push_front(value);
        return;
    }
    else if(index==sz)
    {
        push_back(value);
        return;
    }
    else
    {
        Node* temp=new Node(value);
        Node* prev=head;
        for(size_t i=0;i<index-1;i++)
        {
          prev=prev->next;
        }
        temp->next=prev->next;
        prev->next=temp;
        sz++;
    }
}

template<typename T>
void LinkedList<T>::erase(size_t index)
{
    if(index>=sz)
    {
        throw std::out_of_range("Index out of range");
    }
    if(index==0)
    {
        pop_front();
        return;
    }
    if(index==sz-1)
    {
        pop_back();
        return;
    }
    Node* temp=head;
    for(size_t i=0;i<index-1;i++)
    {
        temp=temp->next;
    }
    Node* curr=temp->next;
    temp->next=curr->next;
    delete curr;
    sz--;
}

template<typename T>
void LinkedList<T>::reverse()
{
  if(head==nullptr || head->next==nullptr)
  return;

  Node* prev=nullptr;
  Node* temp=nullptr;
  Node* curr=head;
  while(curr!=nullptr)
  {
    temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
  }
  head=prev;

}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    head = nullptr;
    sz = 0;

    Node* curr = other.head;

    while(curr != nullptr)
    {
        push_back(curr->data);
        curr = curr->next;
    }
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    if(this == &other)
    {
        return *this;
    }

    while(head != nullptr)
    {
        pop_front();
    }

    Node* curr = other.head;

    while(curr != nullptr)
    {
        push_back(curr->data);
        curr = curr->next;
    }

    return *this;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList&& other)
{
    head = other.head;
    sz = other.sz;

    other.head = nullptr;
    other.sz = 0;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& other)
{
    if(this == &other)
    {
        return *this;
    }

    while(head != nullptr)
    {
        pop_front();
    }

    head = other.head;
    sz = other.sz;

    other.head = nullptr;
    other.sz = 0;

    return *this;
}