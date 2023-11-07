// This file contains the implementation of clear(), append(), and Search() functions for the list class.

#include <iostream>
//#include "Arr.h"   // for array-based list. Comment out for linked-list implementation
#include"LL.h"       // for linked-list-based list. Comment out for array implementation
using namespace std;

class newlist : public list
{

public:
    void clear();
    void append(int);
    int Search(int);
};

void newlist::clear()
{

    moveToStart();

    while (length())
    {
        remove();
    }
}

// append

void newlist::append(int n)
{

    int c = currpos();
    moveToPos(length());
    insert(n);
    moveToPos(c);
}

// Search

int newlist::Search(int n)
{

    int c = currpos();
    moveToStart();
    int size = length();
    for (int i = 0; i < size; i++)
    {
        if (n == getvalue())
        {
            moveToPos(c);
            return 1;
        }
        next();
    }
    moveToPos(c);
    return -1;
}
