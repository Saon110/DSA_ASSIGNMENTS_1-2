#include <iostream>
#include"Arr.h"
//#include "LL.h"
using namespace std;

int main()
{

    int K, X;
    cin >> K >> X;
    list l;
    l.init(K, X);
    l.showList();

    // functions
    cout << "Functions: " << endl;
    cout << "0.Exit" << endl;
    cout << "1.Insert" << endl;
    cout << "2.Remove" << endl;
    cout << "3.Move to start" << endl;
    cout << "4.Move to end" << endl;
    cout << "5.Prev" << endl;
    cout << "6.Next" << endl;
    cout << "7.Length" << endl;
    cout << "8.Current position" << endl;
    cout << "9.Move to pos" << endl;
    cout << "10.Get value" << endl;

    while (1)
    {
        int Q, P;
        cin >> Q >> P;

        if (Q == 0)
            return 0;
        else
        {
            // insert
            if (Q == 1)
            {
                l.insert(P);
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // remove
            else if (Q == 2)
            {
                int r = l.remove();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << r << endl;
            }

            // moveToStart
            else if (Q == 3)
            {
                l.moveToStart();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // moveToEnd
            else if (Q == 4)
            {
                l.moveToEnd();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // prev
            else if (Q == 5)
            {
                l.prev();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // next
            else if (Q == 6)
            {
                l.next();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // length
            else if (Q == 7)
            {
                int L = l.length();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << L << endl;
            }

            // currpos
            else if (Q == 8)
            {
                int c = l.currpos();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << c << endl;
            }

            // moveToPos
            else if (Q == 9)
            {
                l.moveToPos(P);
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << -1 << endl;
            }

            // getvalue
            else if (Q == 10)
            {
                int val = l.getvalue();
                cout << "After modification: ";
                l.showList();
                cout << "Return value:" << val << endl;
            }
        }
    }
    return 0;
}