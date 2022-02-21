// stack_class.cpp
//
// Liliia Pavlishin

#include "stack_class.h"
#include <iostream>

using std::cout;
using std::endl;

STACK::STACK()
{
    top = nullptr;
}

// copy constructor (deep copy)
STACK::STACK(const STACK& st)
{
    top = nullptr;
    NODE* prv = st.top, *q = nullptr;

    while(prv)
    {
        if(!top)
        {
            top = new NODE;
            top->next = nullptr;
            top->n = prv->n;
            q = top;
            prv = prv->next;
        }
        else
        {
            q->next = new NODE;
            q->next->n = prv->n;
            q->next->next = nullptr;
            q = q->next;
            prv = prv->next;
        }
    }
}



// copy assignment
STACK& STACK::operator=(const STACK& rv)
{
    Init();
    top = nullptr;
    NODE* prv = rv.top, *q = nullptr;

    while(prv)
    {
        if(!top)
        {
            top = new NODE;
            top->next = nullptr;
            top->n = prv->n;
            q = top;
            prv = prv->next;
        }
        else
        {
            q->next = new NODE;
            q->next->n = prv->n;
            q->next->next = nullptr;
            q = q->next;
            prv = prv->next;
        }
    }

    return *this;
}


STACK::~STACK()
{
    Init();
}

bool STACK::StackEmpty()
{
    return(top == nullptr);
}

void STACK::Push(int n)
{
    NODE* new_el = new NODE;
    new_el->n = n;
    new_el->next = top;
    top = new_el;
    return;
}

int STACK::Pop()
{
    if(StackEmpty())
    {
        cout << "ERROR: Cannot pop empty stack!" << endl;
        return -1;
    }

    int n = top->n;
    top = top->next;
    return n;
}

int STACK::Peek()
{
    if(StackEmpty())
    {
        return -1;
    }
    return top->n;
}

void STACK::Init()
{
    NODE* q;

    while(top)
    {
        q = top;
        top = top->next;
        delete q;
    }
    return;
}
