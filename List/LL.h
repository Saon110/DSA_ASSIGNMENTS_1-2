#include <iostream>
using namespace std;

class listnode
{

public:
    int val;
    listnode *Next; // pointer to next node

    // three constructors
    listnode()
    {
        val = 0;
        Next = NULL;
    }

    listnode(int n)
    {

        val = n;
        Next = NULL;
    }
    listnode(int n, listnode *addr)
    {
        val = n;
        Next = addr;
    }
};

class list
{

    listnode *head;
    listnode *curr;
    listnode *tail;
    int size;

public:
    list(); // constructor
    void showList();
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
};

// constructor

list::list()
{
    size = 0;
}

// showlist

void list::showList()
{

    if (size == 0)
        cout << "<>" << endl;
    else
    {
        listnode *temp = new listnode;
        temp = head;
        int i = 0;
        cout << "< ";
        while (temp->Next != NULL)
        {

            if (i == currpos())
            {
                cout << "|"
                     << " ";
            }
            cout << temp->Next->val << " ";
            i++;
            temp = temp->Next;
        }

        if (currpos() == length())
            cout << "| ";
        cout << "> " << endl;
    }
}

// init
void list::init(int K, int X)
{

    curr = tail = head = new listnode;
    size = 0;
    for (int i = 0; i < K; i++)
    {

        int n;
        cin >> n;
        insert(n);
        moveToPos(length());
    }
    moveToPos(0);
}

// insert
void list::insert(int n)
{

    curr->Next = new listnode(n, curr->Next);
    if (curr == tail)
        tail = curr->Next;
    size++;
}

// remove

int list::remove()
{

    if (curr->Next == NULL)
    {
        cout << "Already empty!" << endl;
        return -1;
    }
    else
    {
        int n = curr->Next->val;
        listnode *temp = curr->Next;
        if (curr->Next == tail)
            tail = curr;
        curr->Next = curr->Next->Next;
        size--;
        delete temp;
        return n;
    }
}

// moveToStart

void list::moveToStart()
{

    curr = head;
}

// mooveToEnd

void list::moveToEnd()
{
    curr = tail;
    prev();
}

// prev

void list::prev()
{

    if (curr == head)
    {
        cout << "Already at the head!" << endl;
        return;
    }
    listnode *temp = head;
    while (temp->Next != curr)
    {
        temp = temp->Next;
    }
    curr = temp;
}

// next

void list::next()
{

    if (curr->Next == tail)
    {
        cout << "Already at the end!" << endl;
        return;
    }
    curr = curr->Next;
}

// length

int list::length()
{

    return size;
}

int list::currpos()
{
    int count = 0;
    listnode *temp = head;
    while (curr != temp)
    {
        count++;
        temp = temp->Next;
    }

    return count;
}

// moveToPos

void list::moveToPos(int pos)
{

    if (pos < 0 || pos > size)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    curr = head;
    for (int i = 0; i < pos; i++)
        curr = curr->Next;
}

// getvalue

int list::getvalue()
{

    if (size == 0)
    {
        cout << "Empty list!" << endl;
        return curr->Next->val;
    }
    if (curr == tail)
    {
        cout << "Current position is after the last element of the list containing a garbage." << endl;
        return curr->Next->val;
    }
    return curr->Next->val;
}
