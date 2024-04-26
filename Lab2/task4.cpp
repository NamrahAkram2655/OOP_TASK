#include <iostream>
using namespace std;

void getPosneg(const int ar[], const int n_ar, int *&pos, int &n_pos, int *&neg, int &n_neg)
{
    if (n_ar > 0)
    {
        n_neg = 0;
        n_pos = 0;
    }
    for (int i = 0; i < n_ar; i++)
    {
        if (ar[i] < 0)
        {
            n_neg++;
        }
        else
        {
            n_pos++;
        }
    }
    int c1 = 0, c2 = 0;
    pos = new int[n_pos];
    neg = new int[n_neg];

    for (int i = 0; i < n_ar; i++)
    {
        if (ar[i] < 0)
        {
            *(neg + c1) = ar[i];
            c1++;
        }
        else
        {
            *(pos + c2) = ar[i];
            c2++;
        }
    }
}

int main()
{
    int arr[10] = {9, -65, -3, 12, 2, -5, -87, 5, 34, -2};
    int possize = 0, negsize;
    int *pos, *neg;

    getPosneg(arr, 10, pos, possize, neg, negsize);

    if (possize == 0)
    {
        cout << "There is no positive numbers in this array " << endl;
    }
    else
    {
        cout << "There is positive numbers in this array : ";
        for (int i = 0; i < possize; i++)
        {
            cout << "\t" << *(pos + i);
        }
    }

    cout << endl;

    if (negsize == 0)
    {
        cout << "There is negetive numbers in this array " << endl;
    }
    else
    {
        cout << "There is negetive numbers in this array : ";
        for (int i = 0; i < negsize; i++)
        {
            cout << "\t" << *(neg + i);
        }
    }
    cout << endl;

    if (pos != NULL)
    {
        delete[] pos;
    }
    if (neg != NULL)
    {
        delete[] neg;
    }
    return 0;
}
