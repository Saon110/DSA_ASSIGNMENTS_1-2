#include<iostream>
#include<string>

//#include<assert.h>
using namespace std;

template <class E>class Stack{

    int top;
    //int size;
    int maxsize;
    E *arr;

    public:

    Stack();
    Stack(int,int);
    void clear();
    void push(E it);
    E pop();
    int length();
    E topValue();
    bool isEmpty();
    ~Stack();
    void showStack();

};

//default constructor

template<class E>Stack<E>::Stack(){

    ///size=0;
    maxsize=1;
    top=0;
    arr=new E[1];
}

//parameterized constructor

template<class E>Stack<E>::Stack(int X,int K){

    //size=K;
    maxsize=X;
    top=0;
    arr=new E[maxsize];
    // for(int i=0;i<K;i++){
    //     E n;
    //     cin>>n;
    //     //arr[i]
    //     push(n);
    // }

}

//destructor

template<class E>Stack<E>::~Stack(){

    // size=0;
    maxsize=0;
    top=0;
    delete [] arr;

}

//push

template<class E> void Stack<E>::push(E it){

    if(top<maxsize){
        arr[top++]=it;
        //size++;
    }

    else if(top==maxsize){

        maxsize*=2;
        arr=(E*)realloc(arr,sizeof(E)*maxsize);
        arr[top++]=it;
        //size++;

    }

}

//pop

template<class E> E Stack<E>::pop(){

    //assert(size!=0,"Nothing to pop. Stack is empty!!!")
    if(top==0){
        //cout<<"Stack is empty!!"<<endl;
    }
    // E temp=arr[top-1];
    // top--;
    // return temp;
    else
    {
        return arr[--top];
    }

}

//clear

template <class E> void Stack<E>::clear(){

    top=0;
    //size=0;

}

//length

template<class E> int Stack<E>::length(){

    return top;

}

//topValue

template<class E> E Stack<E>::topValue(){

    return arr[top-1];

}

//isEmpty

template<class E> bool Stack<E>::isEmpty(){

    if(top==0)return true;
    return false;

}

//showStack

template<class E> void Stack<E>::showStack(){

    // E* brr=new E[size];
    // for(int i=size-1;i>=0;i++){

    //     brr[size-i-1]=arr[i];

    // }

    //if(size==0)cout<<"<>"<<endl;
    cout<<"< ";
    for(int i=0;i<top;i++){

        cout<<arr[i]<<" ";
    }
    cout<<">"<<endl;

}


