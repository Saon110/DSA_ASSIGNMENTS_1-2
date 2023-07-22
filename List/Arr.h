#include<iostream>
using namespace std;

class list{

    int curr;
    int maxsize;
    int listsize;
    int* arr;
   

    public:

    list();
    //Alist(int K,int X);
    void init(int,int);  //initializing
    void insert(int); //insert in current position
    int remove();     //remove from current position
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

//default constructor
list::list(){

     //init(K,X);
     listsize=0;
     maxsize=0;

}

 void list::showList(){


        if(listsize==0)cout<<"<>"<<endl;
        else{
        cout<<"<"<<" ";
        for(int i=0;i<listsize;i++){
            if(i==curr)cout<<"|"<<" ";
            cout<<arr[i]<<" ";
        }
        if(curr==listsize)cout<<"|"<<" ";
        cout<<">"<<" ";
        cout<<endl;
        }
    }

//init

void list::init(int K,int X){

    maxsize=X;
    curr=0;
    listsize=0;
    int p=curr;
    //arr=(int*)malloc(sizeof(int)*X);
    arr=new int[maxsize];
    for(int i=0;i<K;i++){
        int n;
        cin>>n;
        insert(n);
        moveToPos(length());
    }
    moveToPos(p);
    //showList();
    
}

//insert

void list::insert(int n){

    if(listsize==maxsize){
        maxsize*=2;
        arr=(int*)realloc(arr,sizeof(int)*maxsize);
    }
    for(int i=listsize;i>curr;i--){
        arr[i]=arr[i-1];
    }
    arr[curr]=n;
    listsize++;
    //showList();

}

//remove

int list::remove(){

    int r=arr[curr];
        for(int i=curr;i<listsize;i++){
            arr[i]=arr[i+1];
        }
        listsize--;
       // cout<<"size:"<<listsize<<endl;
       // showList();
        return r;

}

//moveToStart

void list::moveToStart(){

    curr=0;
    //showList();
}

//moveToEnd

void list::moveToEnd(){
    curr=listsize-1;
    //showList();
}

//prev

void list::prev(){

    if(curr==0){
        //cout<<"After next";
        //showList();
        return;
    }
    curr--;
    //showList();
}

//next

void list::next(){

    if(curr==listsize-1){
        //cout<<"After next";
       // showList();
        return;
    }
    curr++;
    //showList();
}

//length

int list::length(){
    //showList();
    return listsize;
}

//currpos

int list::currpos(){

   // showList();
    return curr;
}

//moveToPos

void list::moveToPos(int pos){

    curr=pos;
    //showList(); 
}

//getValue

int list::getvalue(){

    //showList();
    return arr[curr];
}



