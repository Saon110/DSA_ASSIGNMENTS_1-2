#include<iostream>
#include "BST.h"
using namespace std;

int main()
{ 
    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    BST<int> bst;
    char ch;
    while(cin>>ch)
    {
        
        if(ch == 'I')
        {
            int n;
            cin>>n;
            bst.insert(n);
            bst.print();
        }
        else if(ch == 'F')
        {
            int n;
            cin>>n;
            if(bst.find(n))
            {
                cout<<"True"<<endl;
            }
            else
            {
                cout<<"False"<<endl;
            }
        }
        else if(ch == 'D')
        {
            int n;
            cin>>n;
            bst.Delete(n);
            bst.print();
        }
        else if(ch == 'T')
        {
            string s;
            cin>>s;
            if(s=="Pre")
            {
                bst.preOrder();
            }
            else if(s=="Post")
            {
                bst.postOrder();
            }
            else if(s=="In")
            {
                bst.inOrder();
            }
            else
            {
                cout<<"Invalid input\n";
            }

        }
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}