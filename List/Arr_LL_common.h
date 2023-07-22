#include<iostream>
#include"Arr.h"
//#include"LL.h"
using namespace std;

class newlist:public list{

    public:

    void clear();
    void append(int);
    int Search(int);

};

void newlist::clear(){

    moveToStart();
    //int size=length();
    //int i=0;
    while(length()){
        remove();
        //next();
        //if(i=size)return;
        //cout<<
        //i++;
    }
}

//append

void newlist::append(int n){

    // if(length()==0){
    //     insert(n);
    // }
    //else{
        //moveToEnd();
        //next();
        int c=currpos();
        moveToPos(length());
        insert(n);
        moveToPos(c);
    //}
}

//Search

int newlist::Search(int n){

    int c=currpos();
    moveToStart();
    int size=length();
    for(int i=0;i<size;i++){
        if(n==getvalue())
        {
            moveToPos(c);
            return 1;
        }
        next();
    }
    moveToPos(c);
    return -1;
}
