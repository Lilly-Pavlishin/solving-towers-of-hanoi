// stack_class.h
//
// Liliia Pavlishin
//
// each stack is a peg

#ifndef STACK_CLASS_H
#define STACK_CLASS_H

struct NODE
{
    int n;
    NODE *next;
};
class STACK
{
private:
    NODE* top;
public:

    STACK();                // default
    STACK(const STACK&);
    STACK& operator = (const STACK& rv);
    ~STACK();               // destructor
    void Push(int);
    int Pop();
    int Peek();
    bool StackEmpty();
    void Init();
};
#endif  // STACK_CLASS_H