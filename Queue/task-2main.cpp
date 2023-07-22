#include<iostream>
#include"Stack.h"
using namespace std;
int main(){

    // string type;
    // std::cout<<"Select a data type:"<<endl;
    // std::cin>>type;

    //for character data type

    // if(type=="char"){

    //     int X,K;
    //     //cout<<X<<K;
    //     std::cin>>X>>K;
    //     Stack<char>s;
    //     for(int i=0;i<K;i++){
    //         char c;
    //         std::cin>>c;
    //         s.push(c);
    //     }
    //     s.print();

    //     while(1){

    //         int Q;
    //         char P;
    //         std::cin>>Q;

    //         if(Q==0){
    //             return 0;
    //         }

    //         else if(Q==1){

    //             s.clear();
    //             s.print();
    //         }

    //         else if(Q==2){


    //             std::cin>>P;
    //             s.push(P);
    //             s.print();

    //         }

    //         else if(Q==3){

    //             char r;
    //             r=s.pop();
    //             s.print();
    //             std::cout<<"Return value: "<<r<<endl;
    //         }

    //         else if(Q==4){

    //             std::cout<<s.length()<<endl;
    //             s.print();
    //         }

    //         else if(Q==5){

    //             std::cout<<s.topValue()<<endl;
    //             s.print();
    //         }

    //         else if(Q==6){

    //             if(s.isEmpty()==true){
    //                 std::cout<<"True"<<endl;
    //             }
    //             else{
    //                 std::cout<<"False"<<endl;
    //             }
    //             s.print();
    //         }
    //     }

    // }

    // //for integer data type

    //if(type=="int"){

        //int X,K;
        //cout<<X<<K;
        //std::cin>>X>>K;
        Stack<int> 
        s;
        // for(int i=0;i<K;i++){
        //     int c;
        //     std::cin>>c;
        //     s.push(c);
        // }
        //s.print();

        while(1){

            int Q;
            int P;
            std::cin>>Q;

            if(Q==0){
                return 0;
            }

            else if(Q==1){

                s.clear();
                s.print();
            }

            else if(Q==2){


                std::cin>>P;
                s.push(P);
                s.print();

            }

            else if(Q==3){

                int r;
                r=s.pop();
                s.print();
                std::cout<<"Return value: "<<r<<endl;
            }

            else if(Q==4){

                s.print();
                std::cout<<s.length()<<endl;
                
            }

            else if(Q==5){

                
                s.print();
                std::cout<<s.topValue()<<endl;
            }

            else if(Q==6){


                s.print();

                if(s.isEmpty()==true){
                    std::cout<<"True"<<endl;
                }
                else{
                    std::cout<<"False"<<endl;
                }
                
            }
        }

    //}

}