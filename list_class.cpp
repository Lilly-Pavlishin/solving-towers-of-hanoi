// list_class.cpp
//
// Liliia Pavlishin


#include "list_class.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

// default constructor
LIST::LIST(){
    tail = head = nullptr;
}


// Copy constructor
LIST::LIST(const LIST& rv){
    if(rv.head == nullptr)
    {
        head = tail = nullptr;
    }
    else
    {

        head = new NODE;//head->digit = 0;
        head->next = nullptr;
        tail = head;
        NODE* prv = rv.head, *plv = head;
        while(prv)
        {
            if(!plv){       // create new nodes
                plv = new NODE;
                tail->next = plv;
                tail = plv;
                plv->next = nullptr;
            }
            plv->n = prv->n;
            plv->from = prv->from;
            plv->to = prv->to;
            plv = plv->next;
            prv = prv->next;
        }
    }
}

LIST::~LIST(){
    NODE* p = head, *q = nullptr;
    while(p){
        q = p;
        p = p->next;
        delete q;
    }
    head = tail = nullptr;
}


// Copy assignment
LIST &LIST::operator=(const LIST& rv){
    NODE* p = nullptr, *q = nullptr, *prv = rv.head;
    if(&rv == this)
    {
        return *this;
    }
    p = head;
    while(p)
    {
        q = p;
        p = p->next;
        delete q;
    }
    head = tail = nullptr;
    while(prv)
    {
        if(!head)
        {
            head = new NODE;
            tail = head;
        }
        else
        {
            tail->next = new NODE;
            tail = tail->next;
        }
        tail->next = nullptr;
        tail->n = prv->n;
        tail->to = prv->to;
        tail->from = prv->from;
        prv = prv->next;

    }
    return *this;
}







// not able to recurse on << so have to have a wrapper
ostream& operator << (ostream& output, LIST& obj){
    obj.print(output);
    return output;
}

void LIST::print(ostream& output){

    NODE* p = head;
    while(p)
    {
        output << "Moving disk " << p->n
               << " from peg " << p->from << " to peg " << p->to << endl;
        p = p->next;
    }
    return;
}

void LIST::add(int n, char from , char to)
{
    if(!head)
    {
        head = new NODE;
        tail = head;
    }
    else
    {
        tail->next = new NODE;
        tail = tail->next;
    }
    tail->next = nullptr;
    tail->n = n;
    tail->to = to;
    tail->from = from;
}

int LIST::getTailNum()
{
    if(tail)
    {
        return tail->n;
    }
    return -1;
}