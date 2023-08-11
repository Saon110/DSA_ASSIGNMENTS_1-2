#include <iostream>
using namespace std;

template <class E>
class Priority_Queue
{

private:
    int size;
    int index;
    int maxsize;
    E *arr;

    void Max_Heapify(E *A, int i)
    {
        int l = i * 2;
        int r = i * 2 + 1;
        int p = i / 2;
        int max = i;

        if (l < index && A[l] > A[i])
        {
            max = l;
        }

        // else
        // {
        //     max = i;
        // }

        if (r < index && A[r] > A[max])
        {
            max = r;
        }

        if (max != i)
        {
            // E temp = A[i];
            // A[i] = A[max];
            // A[max] = temp;
            swap(A[i], A[max]);
            Max_Heapify(A, max);
        }
    }

    void Build_max_heap(E *A)
    {
        int l = size / 2;
        for (int i = l; i > 0; i--)
        {
            Max_Heapify(A, i);
        }
    }

public:
    Priority_Queue();
    void Insert(E n);
    E Findmax();
    E ExtractMax();
    void IncreaseKey(int i, E key);
    void Decreasekey(int i, E key);
    void Print();
    void Sort();
    bool empty();
    ~Priority_Queue();
};

template <class E>
Priority_Queue<E>::Priority_Queue()
{
    size = 0;
    index = 1;
    maxsize = 2;
    arr = new E[maxsize];
}

template <class E>
E Priority_Queue<E>::Findmax()
{
    return arr[1];
}

template <class E>
E Priority_Queue<E>::ExtractMax()
{
    E temp = arr[1];
    arr[1] = arr[size];
    index--;
    size--;
    Max_Heapify(arr, 1);
    return temp;
}

template <class E>
void Priority_Queue<E>::Insert(E n)
{
    // if (index == maxsize)
    // {
    //     maxsize *= 2;
    //     arr = (E *)realloc(arr, maxsize);
    // }
    if (index == maxsize)
    {
        maxsize *= 2;
        E *newArr = new E[maxsize];
        for (int i = 1; i <= size; i++)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }

    arr[index] = n;
    size++;
    int i = index;
    while (i / 2 > 0 && arr[i] > arr[i / 2])
    {
        // E temp = arr[i];
        // arr[i] = arr[i / 2];
        // arr[i / 2] = temp;
        swap(arr[i],arr[i/2]);
        i = i / 2;
    }
    index++;
}

template <class E>
void Priority_Queue<E>::IncreaseKey(int i, E key)
{
    if (arr[i] > key)
    {
        cout << "New key is not larger than the previous key" << endl;
        return;
    }

    arr[i] = key;

    while (i / 2 > 0 && arr[i] > arr[i / 2])
    {
        // E temp = arr[i];
        // arr[i] = arr[i / 2];
        // arr[i / 2] = temp;
        swap(arr[i],arr[i/2]);
        i = i / 2;
    }

    cout << "Key increased!" << endl;
}

template <class E>
void Priority_Queue<E>::Decreasekey(int i, E key)
{
    if (arr[i] < key)
    {
        cout << "New key is not smaller than the previous key" << endl;
        return;
    }

    arr[i] = key;

    Max_Heapify(arr, i);
    cout << "Key decreased!"<<endl;
}

template <class E>
void Priority_Queue<E>::Sort()
{
    int l = size;
    cout<<"No of elements: "<<l<<endl;
    while (size > 0)
    {
        swap(arr[1], arr[size]);
        size--;
        index--;
        Build_max_heap(arr);
    }

    // for (int i = 1; i <= l; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    int k = 2;
    for (int i = 1; i <= l; i++)
    {
        if (i % k == 0)
        {
            cout << endl;
            k *= 2;
        }
        cout << arr[i] << "  ";
    }
    cout << endl;
}

template <class E>
void Priority_Queue<E>::Print()
{
    int k = 2;
    cout<<"No of elements: "<<size<<endl;

    for (int i = 1; i <= size; i++)
    {
        if (i % k == 0)
        {
            cout << endl;
            k *= 2;
        }
        cout << arr[i] << "  ";
    }
    cout << endl;
}

template <class E>
Priority_Queue<E>::~Priority_Queue()
{
    delete[] arr;
}

template<class E>
bool Priority_Queue<E>::empty()
{
    return size==0;
}

// int main()
// {
//     freopen("input1.txt", "r", stdin);
//     freopen("output1.txt", "w", stdout);
//     Priority_Queue<int> P;
//     // P.Insert(16);
//     // P.Insert(10);
//     // P.Insert(12);
//     // P.Insert(23);
//     // P.Insert(12);
//     // P.Insert(23);
//     // P.Print();
//     // P.IncreaseKey(3,34);
//     // P.Print();
//     // P.Decreasekey(3,24);
//     // P.Decreasekey(3,19);
//     // P.Print();
//     // P.Sort();
//     while (1)
//     {
//         int choice;
//         cin >> choice;

//         if (choice == 1)

//         {
//             int n;
//             cin >> n;
//             P.Insert(n);
//         }

//         if (choice == 2)

//         {
//             int max1 = P.Findmax();
//             cout << "Max: " << max1 << endl;
//         }

//         if (choice == 3)

//         {
//             int max2 = P.ExtractMax();
//             cout << "Max: " << max2 << " has been extracted." << endl;
//         }

//         if (choice == 4)

//         {
//             int index, key;
//             cin >> index >> key;
//             P.IncreaseKey(index, key);
//         }

//         if (choice == 5)

//         {
//             int index, key;
//             cin >> index >> key;
//             P.Decreasekey(index, key);
//         }

//         if (choice == 6)

//         {
//             P.Print();
//         }

//         if (choice == 7)

//         {
//             P.Sort();
//             return 0;
//         }
//     }
//     fclose(stdin);
//     fclose(stdout);
//     return 0;
// }