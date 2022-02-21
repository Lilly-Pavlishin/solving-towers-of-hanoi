// queue_class.cpp
//
// Liliia Pavlishin

#include "queue_class.h"
#include <iostream>

using namespace std;
using std::cout;
using std::endl;

// default constructor
QUEUE::QUEUE()
{
    head = tail = nullptr;
}

// destructor
QUEUE::~QUEUE()
{
    Init();
}

// Is queue empty
bool QUEUE::QueueEmpty()
{
    return (!head);
}

// Enqueue
void QUEUE::Enqueue(POSITION* e)
{
    if(QueueEmpty())
    {
        head = tail = e;
        head->next = nullptr;      // probably don't need this because of constructors
    }
    else
    {
        tail->next = e;
        tail = e;
        tail->next = nullptr;
    }
}

// Dequeue
POSITION* QUEUE::Dequeue()
{
    if(QueueEmpty())
    {
        return NULL;
    }
    POSITION* ptr;
    ptr = head;
    head = head->next;
    ptr->next = nullptr;
    return ptr;
}

// Peek
POSITION* QUEUE::Peek()
{
    return head;
}

void QUEUE::Init()
{
    POSITION* q;
    while(head)
    {
        q = head;
        head = head->next;
        delete q;
    }
}