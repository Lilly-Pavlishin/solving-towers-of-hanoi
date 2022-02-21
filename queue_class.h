// queue_class.h
//
// Liliia Pavlishin
//
// queue of positions

#include <iostream>
#include "list_class.h"
#include "stack_class.h"
#include "position_class.h"

#ifndef QUEUE_CLASS_H
#define QUEUE_CLASS_H

class QUEUE{
private:
    POSITION* head, *tail;
public:
    QUEUE();                        // default constructor
    ~QUEUE();                       // destructor
    void Enqueue(POSITION*);
    POSITION* Dequeue();
    bool QueueEmpty();
    POSITION* Peek();
    void Init();
};
#endif // QUEUE_CLASS_H
