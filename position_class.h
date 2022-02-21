// 3/1/19
//
// position_class.h
//
// Liliia Pavlishin
//
// position is an element for the queue

#ifndef POSITION_CLASS_H
#define POSITION_CLASS_H
#include "list_class.h"
#include "stack_class.h"

class POSITION
{
private:
    LIST list_of_moves;
    STACK _stacks[3];
public:
    POSITION* next;

    POSITION();
    POSITION(POSITION&);
    POSITION& operator = (const POSITION&);
    void InitPos(int);
    ~POSITION();
    void Move(char, char);
    bool IsLegal(char, char);
    bool IsSolved();
    friend ostream& operator << (ostream&, POSITION&);
};
#endif // POSITION_CLASS_H
