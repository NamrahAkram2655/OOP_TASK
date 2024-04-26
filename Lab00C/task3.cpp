/*Task 3 Namrah Akram BITF21m542*/
#include <iostream>
using namespace std;
int main()
{
    int A[4][4];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "Enter element at A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }
    cout << endl;
    cout << "DISPLAYNG MATRIX" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
    cout << "DISPLAYNG TRANPOSE OF MATRIX" << endl;

    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            cout << "\t" << A[i][j];
        }
        cout << endl;
    }
    return 0;
}