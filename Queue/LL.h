#include <iostream>
#include <limits.h>
using namespace std;

template <class E>
class node
{

public:
    E val;
    node<E> *Next;

    node()
    {
        Next = NULL;
    }

    node(E n)
    {

        val = n;
        Next = NULL;
    }

    node(E n, node *Next)
    {
        val = n;
        this->Next = new node<E>;
        this->Next = Next;
    }

    void print()
    {

        cout << "Val:" << val << " "
             << "Next:" << Next << endl;
    }
};

template <class E>
class list
{
    
    public:

    node<E>* curr;
    node<E> *head;
    //node<E> *curr;
    node<E> *tail;
    node<E>* back;
    int size;

    // constructors

    list()
    {

        head = curr = tail =back= new node<E>;
        size = 0;
    }

    void init(){
        head = curr = tail = new node<E>;
        back=new node<E>;
        back=head;
        back->Next=tail;
        size = 0;
    }

    void init(int k, int x)
    {
        for (int i = 0; i < k; i++)
        {
            E n;
            cin >> n;
            insert(n);
        }
    }

    void insert(E n)
    {

        curr->Next = new node<E>(n, curr->Next);
        if (tail == curr)
        {
            back=curr;
            tail = curr->Next;
        } // New tail

        size++;
    }

    E remove()
    {

        E it = curr->Next->val;
        node<E> *temp = curr->Next;
        if (curr->Next == tail)
            tail = curr;
        curr->Next = curr->Next->Next;
        delete temp;
        size--;
        return it;
    }

    void moveToStart()
    {

        curr = head;
    }

    void moveToEnd()
    {

        curr = tail;
        //prev();
    }

    void moveToBack(){

        curr=back;
    }

    void prev()
    {

        node<E> *temp = head;
        while (temp->Next != curr)
        {

            temp = temp->Next;
        }
        curr = temp;
    }

    void next()
    {

        if (curr == tail)
        {
            return;
        }
        else
        {

            curr = curr->Next;
        }
    }

    int length()
    {

        // showlist();
        return size;
    }

    int currpos(){
    int count=0;
    node<E>* temp=head;
    while(curr!=temp){
        count++;
        temp=temp->Next;
    }
    //current_pos=count;
    //showlist();
    //delete temp;
    return count;
}

//moveToPos

void moveToPos(int pos){

    curr=head;
    for(int i=0;i<pos;i++)curr=curr->Next;
    //showlist();

}

//getvalue

E getvalue(){

    //showlist();
    //if(curr->Next==NULL)return LLONG_MIN;
    return curr->Next->val;
}


    void print()
    {

        node<E> *temp = head->Next;
        cout<<"< ";
        while (temp != tail->Next)
        {
            cout << temp->val << " ";
            temp = temp->Next;
        }
        cout<<" >";
        cout << endl;
    }
};

// int main()
// {

//     node<string> n("BUET CSE");
//     node<string> *n2;
//     n2 = &n;
//     n.print();
//     n2->print();
//     list<int> l;
//     l.insert(1);
//     l.print();
//     l.insert(2);
//     l.print();
//     l.insert(3);
//     l.print();
//     l.insert(4);
//     l.print();
//     l.remove();
//     l.print();
//     l.insert(4);
//     l.insert(5);
//     l.insert(6);
//     l.print();
//     cout<<l.currpos()<<endl;
//     cout<<l.getvalue()<<endl;
//     l.moveToPos(4);
//     l.print();
//     cout<<l.remove()<<endl;
//     l.print();
//     l.moveToEnd();
//     l.remove();
//     l.print();
//     cout<<l.currpos()<<endl;
//     cout<<l.getvalue()<<endl;

// }