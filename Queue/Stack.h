#include<iostream>
#include"LQueue.cpp"
using namespace std;

template<class E> class Stack{

    Queue<E> q1,q2;
    int size;


    public:

    Stack(){

        size=0;
    }
    

    void push(E it){

         q2.enqueue(it);

        while (!q1.isEmpty()) {
            q2.enqueue(q1.front());
            q1.dequeue();
        }
 
        Queue<E> q = q1;
        q1 = q2;
        q2 = q;

    }

    E pop(){

        return q1.dequeue();
        size--;

    }

    void clear(){

        q1.clear();
        q2.clear();
    }

    int length(){

        return size;
    }

    E topValue(){

        return q1.front();

    }

    bool isEmpty(){

        if(size==0)return true;
        return false;
    }
     void print(){

        q1.print();
     }

};

