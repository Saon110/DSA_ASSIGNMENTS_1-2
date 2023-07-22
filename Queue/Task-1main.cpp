#include<iostream>
//#include"AQueue.cpp"
#include"LQueue.cpp"
using namespace std;

int main(){

    Queue<int> Q;
    while(1){

        int c;
        cin>>c;
        if(c==0){
            return 0;
        }
        else if(c==1){
            int it;
            cin>>it;
            Q.enqueue(it);
            Q.print();
        }
        else if(c==2){
            //int it;
            Q.dequeue();
            Q.print();
        }
        else if(c==3){
            
            cout<<Q.length()<<endl;
            Q.print();
        }
        else if(c==4){
            //int it;
            cout<<Q.front()<<endl;
            Q.print();
        }
        else if(c==5){
            
            cout<<Q.back()<<endl;
            Q.print();
        }
        else if(c==6){
            
            cout<<Q.isEmpty()<<endl;
            Q.print();
        }
        else if(c==7){
            
            Q.clear();
            Q.print();
        }
        
    }
}
