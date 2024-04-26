#include <iostream>
#include <string>
using namespace std;

int *getEvenNumbers(const int ar[], const int size, int &evenArraySize)
{
    if (size > 0)
    {
        evenArraySize = 0;
    }
    for (int i = 0; i < size; i++)
    {
        if (ar[i] % 2 == 0)
        {
            evenArraySize++;
        }
    }

    int *ptr = new int[evenArraySize];
    int c = 0;

    for (int i = 0; i < size; i++)
    {
        if (ar[i] % 2 == 0)
        {
            *(ptr + c) = ar[i];
            c++;
        }
    }

    return ptr;
}

int main()
{
    int arr[10] = {3, 1, 23, 4, 56, 7, 8, 8, 9, 5};
    int newsize = 0;

    int *create = getEvenNumbers(arr, 10, newsize);

    if (newsize == 0)
    {
        cout << "Array has no even numbers ";
    }
    else
    {
        cout << "Even numbers in array : ";
        for (int i = 0; i < newsize; i++)
        {
            cout << " " << *(create + i);
        }
    }

    if (create != NULL)
    {
        delete[] create;
    }

    return 0;
}