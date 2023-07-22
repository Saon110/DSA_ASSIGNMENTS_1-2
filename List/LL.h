#include<iostream>
using namespace std;

class listnode{

    public:
    int val;
    listnode* Next;

  
    //default constructor
    listnode(){
        val=0;
        Next=NULL;
    }

    listnode(int n){

        val=n;
        Next=NULL;

    }
    listnode(int n,listnode* addr){
        val=n;
        Next=addr;
    }
};

class list{

    listnode* head;
    listnode* curr;
    listnode* tail;
    int size;

    public:

    list();//constructor
    void showList();
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

};

//constructor

list::list(){
    size=0;
}

//showlist

void list::showList(){
    //int pos=currpos();
        //cout<<current_pos<<"<-"<<endl;
        if(size==0)cout<<"<>"<<endl;
        else{
            listnode* temp=new listnode;
            temp=head;
            int i=0;
            cout<<"< ";
            while(temp->Next!=NULL){
                
                if(i==currpos()){cout<<"|"<<" ";}
                cout<<temp->Next->val<<" ";
                i++;
                temp=temp->Next;
        }

           if(currpos()==length())cout<<"| ";
           cout<<"> "<<endl;
           //delete temp;
      }
}

//init
void list::init(int K,int X){

    curr = tail = head = new listnode;
    size= 0;
    for(int i=0;i<K;i++){

        int n;
        cin>>n;
        insert(n);
        moveToPos(length());
    }
    moveToPos(0);

}

//insert
void list::insert(int n){

    // listnode* newnode=new listnode;
    // newnode->val=n;
    // newnode->Next=curr->Next;
    // curr->Next=newnode;
    curr->Next = new listnode(n, curr->Next);
    if(curr==tail)tail=curr->Next;
    //if(curr!=head)curr=curr->Next;
    size++;
    //showlist();

    
}

//remove

int list::remove(){

    if(curr->Next==NULL){
        cout<<"Already empty!"<<endl;
        //showlist();
        return -1;
    }
    else{
        int n=curr->Next->val;
        listnode* temp=curr->Next;
        if(curr->Next==tail)tail=curr;
        curr->Next=curr->Next->Next;
        delete temp;
        //showlist();
        return n;
    }

}

//moveToStart

void list::moveToStart(){

    curr=head;
    //showlist();
}

//mooveToEnd

void list::moveToEnd(){
    curr=tail;
    prev();
    //showlist();
}

//prev

void list::prev(){

    if(curr==head){
        cout<<"Already at the head!"<<endl;
        //showlist();
        return;
    }
    listnode* temp=head;
    while(temp->Next!=curr){
        temp=temp->Next;
    }
    curr=temp;
}

//next

void list::next(){

    if(curr==tail){
        cout<<"No next element"<<endl;
        //showlist();
        return;
    }
    curr=curr->Next;
    //showlist();
}

//length

int list::length(){

    //showlist();
    return size;
}

int list::currpos(){
    int count=0;
    listnode* temp=head;
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

void list::moveToPos(int pos){

    curr=head;
    for(int i=0;i<pos;i++)curr=curr->Next;
    //showlist();

}

//getvalue

int list::getvalue(){

    //showlist();
    return curr->Next->val;
}


