// 3/1/19
//
// position_class.cpp
//
// Liliia Pavlishin

#include "position_class.h"
#include <iostream>
using std::cout;

// default constructor
POSITION::POSITION()
{
    next = nullptr;
}

// copy constructor
POSITION::POSITION(POSITION& rv)
{
    list_of_moves = rv.list_of_moves;
    _stacks[0] = rv._stacks[0];
    _stacks[1] = rv._stacks[1];
    _stacks[2] = rv._stacks[2];
    next = nullptr;
}

POSITION::~POSITION()
{
    next = nullptr;
}

void POSITION::InitPos(int n)
{

    if(n < 0)
    {
        n *= -1;
    }
    while(n != 0)
    {
        _stacks[0].Push(n);
        n--;
    }
    return;
}

void POSITION::Move(char from, char to)
{
    int n = _stacks[from - 'A'].Pop();
    _stacks[to - 'A'].Push(n);
    list_of_moves.add(n, from, to);


    return;
}

bool POSITION::IsLegal(char from, char to)
{
    // DONT PUT EVEN ON EVEN
    if((_stacks[from - 'A'].Peek()%2 == 0) && (_stacks[to - 'A'].Peek()%2 == 0))
    {
        return false;
    }
    // DONT PUT EVEN ON EVEN
    if((_stacks[from - 'A'].Peek()%2 == 1) && (_stacks[to - 'A'].Peek()%2 == 1))
    {
        return false;
    }
    // THIS WORKS ONLY UP TO 7 DISKS
    // "to" has to be larger or -1 (empty)
    if(_stacks[from - 'A'].StackEmpty())
    {
        return false;
    }
    // 1 only can go on even disk
    if((_stacks[from - 'A'].Peek() == 1) && (_stacks[to - 'A'].Peek()%2 == 1))
    {
        return false;
    }
    if((_stacks[to - 'A'].StackEmpty()) && ((_stacks[from - 'A'].Peek()) != (list_of_moves.getTailNum())))
    {
        return true;
    }
    // if to < from and does not move the same disk as last time
    if(((_stacks[to - 'A'].Peek()) > (_stacks[from - 'A'].Peek())) && ((_stacks[from - 'A'].Peek()) != (list_of_moves.getTailNum())))
    {
        return true;
    }
    return false;


}

bool POSITION::IsSolved()
{
    if(_stacks[0].StackEmpty() && _stacks[2].StackEmpty())
        return true;
    else
        return false;
}

POSITION& POSITION::operator=(const POSITION& pos)
{

    // FOR SOME REASON -STACK DOES NOT LET ME ASSIGN DIRECTLY
    //POSITION* _pos = pos;
    //std::cout << "in deep copy assn" << std::endl;
    list_of_moves = pos.list_of_moves;
    _stacks[0] = pos._stacks[0];
    _stacks[1] = pos._stacks[1];
    _stacks[2] = pos._stacks[2];
    next = nullptr;
    return *this;
}

ostream& operator << (ostream& output, POSITION& pos)
{
    output << pos.list_of_moves;
    return output;
}