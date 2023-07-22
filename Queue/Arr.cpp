#include <iostream>
#include<stdlib.h>
using namespace std;

template <class E> class list
{

    int front;
    int back;
    int curr;
    E *arr;
    int size, maxsize;

public:
    list()
    {
        front = 1 ;
        back = 0 ;
        curr = 1 ;
        size = 0 ;
        maxsize = 16 ;
        arr = new E[maxsize+1] ;
    }

    void init()
    {

        front = 1;
        back = 0;
        curr = 1;
        size = 0;
        maxsize=16;
        arr = new E[maxsize+1];
    }

    // void init(int K, int X)
    // {

    //     maxsize = X;
    //     curr = 0;
    //     size = 0;
    //     int p = curr;
    //     // arr=(int*)malloc(sizeof(int)*X);
    //     arr = new E[maxsize];
    //     for (int i = 0; i < K; i++)
    //     {
    //         E n;
    //         cin >> n;
    //         insert(n);
    //         moveToPos(length());
    //     }
    //     moveToPos(p);
    // }

    void insert(E n)
    {

        int m=maxsize;

        if (size == maxsize)
        {
            maxsize *= 2;
            E* temp = new E[maxsize+1];
            int k= front;
            for(int i=1;i<=size;i++){

                temp[i]=arr[k%(m+1)];
                k++;

            }
            //arr = ( *)realloc(arr, sizeof(int) * maxsize);
            E* t=arr;
            arr=temp;
            delete [] t;
            front=1;
            back=size;
            if(curr==0)curr=1;
        }
        back=(back+1)%(m+1);
        for (int i = curr+size; i > curr; i--)
        {
            arr[i%(m)] = arr[(i - 1)%(m)];
        }
        arr[curr%(maxsize+1)] = n;
        size++;
    }

    E remove()
    {
        int m=maxsize;
        int r = arr[curr];
        //front=(front+1)%(m+1);
        //if(curr==front)front=(front+1)%(m+1);
        for (int i = curr; i < back+m+1; i++)
        {
            arr[i%(m+1)] = arr[(i + 1)%(m+1)];
        }
        size--;
        return r;
    }

    void moveToStart()
    {
        curr = front%(maxsize+1);
    }

    void moveToEnd()
    {

        curr = back%(maxsize+1);
    }

    void prev()
    {

        if (curr != front){
            
            curr=curr+maxsize+1;
            curr--;
            curr=curr%(maxsize+1);
        }
    }

    void next()
    {

        if (curr+2 != front)
        {
           curr=curr+maxsize+1;
           curr++;
           curr=curr%(maxsize +1);
        }
    }

    int length()
    {
        return size;
    }

    int currpos()
    {

        int p = curr+maxsize+1;
        p=p-front;;
        p=p%(maxsize+1);
        return p;
    }

    void moveToPos(int p)
    {
        curr = (front+p)%(maxsize+1);

    }

    E getValue()
    {
        return arr[curr];
    }

    void print()
    {

        if(size==0)cout<<"<>"<<endl;
        else{
        cout<<"<"<<" ";
        int k=front%(maxsize+1);
        for(int i=0;i<size;i++){
            if(i==currpos())cout<<"|"<<" ";
            cout<<arr[k]<<" ";
            k++;
            k=k%(maxsize+1);
        }
        if(currpos()==size)cout<<"|"<<" ";
        cout<<">"<<" ";
        cout<<endl;
        }
    }

    ~list(){

        delete [] arr;
    }
};


// template<class E>class Queue{

//     int front,back;
//     list* l;

//     public:

//     // Queue(){
//     //     front=1;
//     //     back=0;
//     //     l=new
//     // }

// };

int main(){

    list<int> l;
    l.insert(1);
    l.print();
    l.insert(2);
    l.print();
    l.insert(3);
    l.print();
    l.insert(4);
    l.print();
    l.insert(5);
    l.print();
    int i=10;
    while(i--){
        l.insert(i);
        l.print();
    }
    cout<<l.remove()<<endl;
    l.print();
    l.insert(400);
    l.print();
    l.moveToEnd();
    l.print();
    l.prev();
    l.print();
    l.next();
    l.print();
    l.insert(499);
    l.print();
    l.insert(1234);
    l.insert(1254);
    l.print();
}