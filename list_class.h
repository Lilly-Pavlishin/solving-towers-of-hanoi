// list_class.h
//
// Liliia Pavlishin
// LLIST for list of moves

#ifndef LIST_CLASS_H
#define LIST_CLASS_H

#include <iostream>
using std::ostream;

class LIST{
private:
    struct NODE
    {
        NODE* next;
        int n;
        char to, from;
    };

    NODE* head, *tail; //ptrs to access the head and
    //of a liked list
    void print(ostream& output);
public:

    ~LIST();

    LIST();
    LIST(const LIST& );
    LIST& operator = (const LIST& rv);
    int getTailNum();
    //LIST(LIST&& );
    //LIST& operator = (LIST&& rv);
    void add(int, char, char);
    friend ostream& operator << (ostream&, LIST&);
};



#endif // LIST_CLASS_H