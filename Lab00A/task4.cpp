#include <iostream>
using namespace std;
int main()
{
    // task 4
    int num;
    cout << "Enter any number : ";
    cin >> num;
    while (num > 10 || num < 1)
    {
        cout << "Enter again any number in range of 1-9 : ";
        cin >> num;
    }
    switch (num)
    {
    case 1:
        cout << "I" << endl;
        break;
    case 2:
        cout << "II" << endl;
        break;
    case 3:
        cout << "III" << endl;
        break;
    case 4:
        cout << "IV" << endl;
        break;
    case 5:
        cout << "V" << endl;
        break;
    case 6:
        cout << "VI" << endl;
        break;
    case 7:
        cout << "VII" << endl;
        break;
    case 8:
        cout << "VIII" << endl;
        break;
    case 9:
        cout << "IX" << endl;
        break;
    case 10:
        cout << "X" << endl;
        break;
    default:
        break;
    }
    return 0;
}