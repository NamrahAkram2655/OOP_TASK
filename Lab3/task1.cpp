#include <iostream>
#include <string>

using namespace std;

int *pairwiseDifference(const int ar[], const int size, int &newArraysize)
{
    if (size > 0)
    {
        newArraysize = 0;
    }

    if (size % 2 == 0)
    {
        newArraysize = size / 2;
    }
    else
    {
        newArraysize = (size / 2) + 1;
    }

    int *ptr = new int[newArraysize];

    int c = 0;

    if (size % 2 == 0)
    {
        for (int i = 1; i <= size; i++)
        {
            if (i % 2 == 0)
            {
                *(ptr + c) = *(ar + i) - *(ar + i - 1);
                c++;
            }
        }
    }
    else
    {
        int c2 = 0, i;
        for (i = 1; i <= size; i++)
        {
            if (i % 2 == 0)
            {
                *(ptr + c2) = *(ar + i) - *(ar + i - 1);
                c2++;
            }
            *(ptr + c2) = *(ar + size);
        }
    }

    return ptr;
}

int main()
{
    const int size = 10;
    int arr[size];

    // ager mai array ko 1 se start na kerti to condition change kerni hogi function mai *(arr+i-2)+*(arr+i-1) because wo 0 index ko dekh nhi pa rha

    // ager mai array ko 1 se start kerti to condition change kerni hogi function mai *(arr+i)+*(arr+i-1) because 1 se strat ho rha

    for (int i = 1; i <= size; i++)
    {
        cout << "Enter value at index " << i << " : ";
        cin >> arr[i];
    }

    int newsize = 0;

    int *create = pairwiseDifference(arr, size, newsize);

    if (newsize == 0)
    {
        cout << "it has no elements " << endl;
    }
    else
    {
        if (size % 2 == 0)
        {
            for (int i = 0; i < newsize; i++)
            {
                cout << " " << *(create + i);
            }
        }
        else
        {
            for (int i = 0; i < newsize; i++)
            {
                cout << " " << *(create + i);
            }
            // cout << " " << *(create + newsize);
        }
    }

    if (create != NULL)
    {
        delete[] create;
    }

    return 0;
}