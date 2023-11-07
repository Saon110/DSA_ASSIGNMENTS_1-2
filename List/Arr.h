#include <iostream>
using namespace std;

class list
{

private:
    int curr;
    int maxsize;
    int listsize;
    int *arr;

public:
    list();              // constructor
    void init(int, int); // initializing
    void insert(int);    // insert in current position
    int remove();        // remove from current position
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currpos();
    void moveToPos(int);
    int getvalue();
    void showList();
};

// default constructor
list::list()
{

    listsize = 0;
    maxsize = 0;
}

void list::showList()
{

    if (listsize == 0)
        cout << "<>" << endl;
    else
    {
        cout << "<"
             << " ";
        for (int i = 0; i < listsize; i++)
        {
            if (i == curr)
                cout << "|"
                     << " ";
            cout << arr[i] << " ";
        }
        if (curr == listsize)
            cout << "|"
                 << " ";
        cout << ">"
             << " ";
        cout << endl;
    }
}

// init

void list::init(int K, int X)
{

    maxsize = X;
    curr = 0;
    listsize = 0;
    int p = curr;

    arr = new int[maxsize];
    for (int i = 0; i < K; i++)
    {
        int n;
        cin >> n;
        insert(n);
        moveToPos(length());
    }
    moveToPos(p);
}

// insert

void list::insert(int n)
{

    if (listsize == maxsize)
    {
        maxsize *= 2;
        int *temp = new int[maxsize];
        for (int i = 0; i < listsize; i++)
        {
            temp[i] = arr[i];
        }
        swap(arr, temp);
        delete[] temp;
    }
    for (int i = listsize; i > curr; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[curr] = n;
    listsize++;
}

// remove

int list::remove()
{

    int r = arr[curr];
    for (int i = curr; i < listsize; i++)
    {
        arr[i] = arr[i + 1];
    }
    listsize--;

    return r;
}

// moveToStart

void list::moveToStart()
{

    curr = 0;
}

// moveToEnd

void list::moveToEnd()
{
    curr = listsize - 1;
}

// prev

void list::prev()
{

    if (curr == 0)
    {
        cout << "Already at the head!" << endl;
        return;
    }
    curr--;
}

// next

void list::next()
{

    if (curr == listsize - 1)
    {
        cout << "Already at the end!" << endl;
        return;
    }
    curr++;
}

// length

int list::length()
{

    return listsize;
}

// currpos

int list::currpos()
{

    return curr;
}

// moveToPos

void list::moveToPos(int pos)
{

    if (pos < 0 || pos > listsize)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    curr = pos;
}

// getValue

int list::getvalue()
{

    if (listsize == 0)
    {
        cout << "List is empty!" << endl;
        return arr[curr];
    }
    if (curr == listsize)
    {
        cout << "Current position is after the last element of the list containing a garbage." << endl;
        return arr[curr];
    }
    return arr[curr];
}
