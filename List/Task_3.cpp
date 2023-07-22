#include<iostream>
#include"Arr.h"
//#include"LL.h"
using namespace std;
int main(){

    int X,Y,Z;
    //cin>>X>>Y>>Z;
    cout<<"Tatal cars: ";
    cin>>X;
    cout<<"Tatal garages: ";
    cin>>Y;
    cout<<"Maximum capacity: ";
    cin>>Z;
    list garage[Y-1];
    // for(int i=0;i<Y;i++){

    //     garage[i].init(0,Z);

    // }
    for(int i=0;i<Y;i++){
        int g,c,size;
        cout<<"Garage no: ";
        cin>>g;
        cout<<"Parked cars: ";
        cin>>c;
        //size=garage[g-1].length();
        //cin>>g>>c;
        garage[i].init(c,Z);
        // for(int j=0;j<c;j++){

        //     int n;
        //     cin>>n;
        //     garage[g-1].moveToPos(size);
        //     garage[g-1].insert(n);
        // }
    }
        //char c;
        // cin>>c;
        // if(c=='\n'){
        //     continue;
        // }
        // else if(c==' '){
        //}
    for(int i=0;i<Y;i++){
        // int size=garage[i].length();
        // cout<<i+1<<" ";
        // for(int j=0;j<size;j++){

        //     garage[i].moveToPos(j);
        //     cout<<garage[i].getvalue()<<" ";

        // }
        cout<<"Garage:"<<i+1<<"=  ";
        garage[i].showList();
    }    

    while(1){
        string str;
        cin>>str;

        //end
        if(str=="end"){

        for(int i=0;i<Y;i++){
        
            cout<<"Garage:"<<i+1<<"=  ";
            garage[i].showList();
        }    
           return 0;
        }

        //req
        if(str=="req"){

            //int c=0;
            //int minindex=0;
            int i;
            for(i=0;i<Y;i++){
                if(garage[i].length()>0){
                    // minindex=i;
                    // c=1;
                    break;
                }
                else if(i==Y)break;
            }

            // int arr[Y];
            // for(int i=0;i<Y;i++){
            //     arr[i]=garage[i].length();
            // }
            //find the garage with least label
            // for(int i=0;i<Y;i++){
            //     for(int j=i;j<Y;j++){
            //         if(arr[j]<arr[i]){
            //             int temp=arr[i];
            //             arr[i]=arr[j];
            //             arr[j]=temp;
            //         }
            //     }
            // }
            // int minindex=0;
            // for(int i=0;i<Y;i++){
            //     //if(arr[i]==0)continue;
            //     if(arr[i]>0){
            //         minindex=i;
            //         break;
            //     }
            // }
            if(garage[i].length()==0){
                cout<<"All garages are empty!!!"<<endl;
                for(int j=0;j<Y;j++){
                    cout<<"Garage:"<<j+1<<"=  ";
                    garage[j].showList();
                }
            }
            else{
                //find the car with least label
                int car_min;
                garage[i].moveToStart();
                car_min=garage[i].getvalue();
                int minpos=0;
                for(int j=0;j<garage[i].length();j++){
                    //garage[minindex].moveToPos(i);
                    if(garage[i].getvalue()<car_min){
                        car_min=garage[i].getvalue();
                        minpos=j;

                    }
                    garage[i].next();
                }
                garage[i].moveToPos(minpos);
                garage[i].remove();
                garage[i].moveToStart();
                for(int j=0;j<Y;j++){
                    cout<<"Garage:"<<j+1<<"=  ";
                    garage[j].showList();
                }
                
            }
            
        }
        //return
        if(str=="ret"){
            int n;
            cin>>n;
            // int c=0;
            // int maxindex=Y-1;
            int i;
            for(i=Y-1;i>=0;i--){
                if(garage[i].length()<Z){
                    // maxindex=i;
                    // c=1;
                    break;
                }
                else if(i==Y)break;
            }
            if(garage[i].length()>Z){
                cout<<"All garages are filled!!!"<<endl;
                for(int j=0;j<Y;j++){
                    cout<<"Garage:"<<j+1<<"=  ";
                    garage[j].showList();
                }
            }
            else{
                garage[i].moveToStart();
                int car_max=garage[i].getvalue();
                int maxpos=0;
                int size=garage[i].length();
                for(int j=1;j<size;j++){
                    //garage[maxindex].moveToPos(0);
                    if(garage[i].getvalue()>car_max){
                        maxpos=j;
                    }
                    garage[i].next();
                    
                }

                    garage[i].moveToPos(maxpos);
                    if(maxpos==0){
                        if(n<garage[i].getvalue()){
                            garage[i].moveToEnd();
                            garage[i].next();
                            garage[i].insert(n);
                        }
                        else{
                            garage[i].insert(n);}
                        garage[i].moveToStart();
                        for(int j=0;j<Y;j++){
                        cout<<"Garage:"<<j+1<<"=  ";
                        garage[j].showList();
                }
                    }

                    else{
                    garage[i].next();
                    garage[i].insert(n);
                    garage[i].moveToStart();
                    for(int j=0;j<Y;j++){
                    cout<<"Garage:"<<j+1<<"=  ";
                    garage[j].showList();
                }}

            }

        }

    }

    

}