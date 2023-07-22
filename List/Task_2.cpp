#include<iostream>
#include"Arr_LL_common.h"
using namespace std;
int main(){

    newlist l;
    int K,X;
    cin>>K>>X;
    l.init(K,X);
    for(int i=0;i<K;i++){
        int n;
        cin>>n;
        l.insert(n);
    }
    l.showList();

    cout<<"List of functions:"<<endl;
    cout<<"0.Exit"<<endl;
    cout<<"1.Clear"<<endl;
    cout<<"2.Append"<<endl;
    cout<<"3.Search"<<endl;

    while(1){
        int Q,P;
        cin>>Q>>P;
        if(Q==0){

            return 0;
        }

        else if(Q==1){

            l.clear();
            l.showList();
            cout<<"Return value:"<<-1<<endl;
        }

        else if(Q==2){
            //cin>>P;
            l.append(P);
            l.showList();
            cout<<"Return value:"<<-1<<endl;

        }

        else if(Q==3){
            //cin>>P;
            int r=l.Search(P);
            l.showList();
            cout<<"Return value:"<<r<<endl;
        }

    }
}