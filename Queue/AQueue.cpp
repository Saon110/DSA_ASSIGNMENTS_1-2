#include<iostream>
#include"Arr.h"
using namespace std;

template<class E> class Aqueue{

    int Front,Back,maxsize,size;
    list<E> l;

    public:

    Aqueue(){

        Front=1;
        Back=0;
        size=0;
        maxsize=1;
        l.init();
        
    }

    void enqueue(E it){

        // if((back+2)%maxsize==front){

        // }
        Back++;
        Back=Back%maxsize;
        //cout<<"Back: "<<Back<<endl;
        //l.moveToPos(Back);
        //cout<<"currpos: "<<l.currpos()<<endl;
        l.next();
        l.insert(it);
        size++;
    }

    E dequeue(){

        l.moveToPos(Front);
        E it = l.getValue();
        Front = (Front+1) % maxsize; // Circular increment
        size--;
        return it;
    }

    int length(){
        return size;
    }

    E front(){
        l.moveToPos(Front);
        return l.getValue();
    }

    E back(){

        l.moveToPos(Back);
        return l.getValue();
    }

    bool isEmpty(){

        if(size==0)return true;
        return false;

    }

    void clear(){

        Front=1;
        Back=0;
        size=0;
    }

    ~Aqueue(){

        l.~list();
    }

    void print(){

        // cout<<"< ";
        // int k=Front;
        // for(int i=0;i<size;i++){


        //     l.moveToPos(k%maxsize);
        //     E a=l.getValue();
        //     cout<<a<<" ";
        //     k++;
        // }
        //cout<<">"<<endl;
        l.print();
    }
};

// int main(){

//     Aqueue<int> Q;
//     Q.enqueue(1);
//     //Q.print();
//     Q.enqueue(2);
//     Q.enqueue(3);
//     Q.enqueue(4);
//     Q.print();
//     Q.dequeue();
//     Q.print();
//     Q.dequeue();
//     Q.print();
//     cout<<Q.back()<<"|"<<Q.front();
// }