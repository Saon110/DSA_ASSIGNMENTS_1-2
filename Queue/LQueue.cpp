#include <iostream>
#include "LL.h"
using namespace std;

template <class E>
class Queue
{

    list<E> l;

public:
    Queue()
    {

        l.init();
    }

    void enqueue(E it)
    {

        l.moveToEnd();
        // next();
        l.insert(it);
    }

    E dequeue()
    {

        l.moveToStart();
        E it = l.remove();
        return it;
    }

    int length()
    {
        return l.length();
    }

    E front()
    {

        l.moveToStart();
        return l.getvalue();
    }

    E back()
    {

        l.moveToBack();
        return l.getvalue();
    }

    bool isEmpty()
    {

        if (l.length() == 0)
            return true;
        return false;
    }

    void clear()
    {

        l.init();
    }

    void print()
    {

        l.print();
    }

    ~Queue()
    {
        l.moveToStart();
        
        while (l.length())
        {
            l.remove();
            
        }
    }
};

// int main()
// {

//     Queue<int> Q;
//     Q.enqueue(1);
//     Q.print();
//     cout << Q.dequeue() << endl;
//     Q.enqueue(1);
//     Q.enqueue(2);
//     Q.print();
//     cout << "L=" << Q.length() << endl;
//     cout << "front= " << Q.front() << endl;
//     cout << "back= " << Q.back() << endl;
//     Q.enqueue(3);
//     Q.print();
//     cout << "back= " << Q.back() << endl;
//     Q.clear();
//     cout << "CL" << endl;
//     Q.print();
//     cout << "EAR"<<endl;
//     Q.enqueue(4);
//     Q.print();
//     Q.~Queue();
// }