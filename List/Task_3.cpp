#include <iostream>
// #include "Arr.h"  // for array-based list. Comment out for linked-list implementation
#include "LL.h" // for linked-list-based list. Comment out for array implementation
using namespace std;
int main()
{

    int total_car, total_garage, max_capacity;

    cout << "Tatal cars: ";
    cin >> total_car;
    cout << "Tatal garages: ";
    cin >> total_garage;
    cout << "Maximum capacity: ";
    cin >> max_capacity;
    list garage[max_capacity - 1]; // array of lists for garages to store cars

    for (int i = 0; i < total_garage; i++)
    {
        int garage_no, no_of_cars;
        cout << "Garage no: ";
        cin >> garage_no;
        cout << "Parked cars: ";
        cin >> no_of_cars;

        garage[garage_no - 1].init(no_of_cars, max_capacity); // initialize the list for each garage with cars
    }

    for (int i = 0; i < total_garage; i++)
    {

        cout << "Garage:" << i + 1 << "=  ";
        garage[i].showList();
    }

    while (1)
    {
        string str;
        cin >> str;

        // end the program
        if (str == "end")
        {

            for (int i = 0; i < total_garage; i++)
            {

                cout << "Garage:" << i + 1 << "=  ";
                garage[i].showList();
            }
            return 0;
        }

        // request a car from the garage
        if (str == "req")
        {

            int i;
            for (i = 0; i < total_garage; i++)
            {
                if (garage[i].length() > 0)
                {
                    break;
                }
            }

            if (i == total_garage) // if all garages are empty
            {
                cout << "All garages are empty!!!" << endl;
                for (int j = 0; j < total_garage; j++)
                {
                    cout << "Garage:" << j + 1 << "=  ";
                    garage[j].showList();
                }
            }
            else
            {
                // find the car with least label
                int car_min;
                garage[i].moveToStart();
                car_min = garage[i].getvalue();
                int minpos = 0;
                for (int j = 0; j < garage[i].length(); j++)
                {

                    if (garage[i].getvalue() < car_min)
                    {
                        car_min = garage[i].getvalue();
                        minpos = j;
                    }
                    if (j != garage[i].length() - 1)
                    {
                        garage[i].next();
                    }
                }
                garage[i].moveToPos(minpos);
                garage[i].remove();
                garage[i].moveToStart();
                for (int j = 0; j < total_garage; j++)
                {
                    cout << "Garage:" << j + 1 << "=  ";
                    garage[j].showList();
                }
            }
        }
        // return a car to the garage
        if (str == "ret")
        {
            int car;
            cin >> car;
            int i;
            for (i = total_garage - 1; i >= 0; i--)
            {
                if (garage[i].length() < max_capacity)
                {
                    break;
                }
            }
            if (i == -1) // if all garages are filled
            {
                cout << "All garages are filled!!!" << endl;
                for (int j = 0; j < total_garage; j++)
                {
                    cout << "Garage:" << j + 1 << "=  ";
                    garage[j].showList();
                }
            }
            else if (garage[i].length() == 0)
            {
                garage[i].insert(car);
                garage[i].moveToStart();
                for (int j = 0; j < total_garage; j++)
                {
                    cout << "Garage:" << j + 1 << "=  ";
                    garage[j].showList();
                }
            }
            else
            {
                garage[i].moveToStart();
                int car_max = garage[i].getvalue();
                int maxpos = 0;
                int size = garage[i].length();
                for (int j = 0; j < size; j++)
                {

                    if (garage[i].getvalue() > car_max)
                    {
                        maxpos = j;
                    }
                    if (j != size - 1)
                    {
                        garage[i].next();
                    }
                }

                garage[i].moveToPos(maxpos);
                if (maxpos == 0)
                {
                    if (car < garage[i].getvalue()) // if the car is less than the first car in the garage
                    {

                        garage[i].moveToPos(maxpos + 1);
                        garage[i].insert(car);
                    }
                    else // if the car is the largest in the garage

                    {
                        garage[i].insert(car);
                    }
                    garage[i].moveToStart();
                    for (int j = 0; j < total_garage; j++)
                    {
                        cout << "Garage:" << j + 1 << "=  ";
                        garage[j].showList();
                    }
                }

                else
                {
                    garage[i].moveToPos(maxpos + 1);
                    garage[i].insert(car);
                    garage[i].moveToStart();
                    for (int j = 0; j < total_garage; j++)
                    {
                        cout << "Garage:" << j + 1 << "=  ";
                        garage[j].showList();
                    }
                }
            }
        }
    }
}