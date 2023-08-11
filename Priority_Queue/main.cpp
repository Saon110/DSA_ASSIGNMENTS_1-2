#include<iostream>
#include"Priority_Queue.h"
using namespace std;


int main()
{
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    Priority_Queue<int> P;
    // P.Insert(16);
    // P.Insert(10);
    // P.Insert(12);
    // P.Insert(23);
    // P.Insert(12);
    // P.Insert(23);
    // P.Print();
    // P.IncreaseKey(3,34);
    // P.Print();
    // P.Decreasekey(3,24);
    // P.Decreasekey(3,19);
    // P.Print();
    // P.Sort();
    while (1)
    {
        int choice;
        cin >> choice;

        if (choice == 1)

        {
            int n;
            cin >> n;
            P.Insert(n);
        }

        if (choice == 2)

        {
            int max1 = P.Findmax();
            cout << "Max: " << max1 << endl;
        }

        if (choice == 3)

        {
            int max2 = P.ExtractMax();
            cout << "Max: " << max2 << " has been extracted." << endl;
        }

        if (choice == 4)

        {
            int index, key;
            cin >> index >> key;
            P.IncreaseKey(index, key);
        }

        if (choice == 5)

        {
            int index, key;
            cin >> index >> key;
            P.Decreasekey(index, key);
        }

        if (choice == 6)

        {
            P.Print();
        }

        if (choice == 7)

        {
            P.Sort();
            return 0;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}