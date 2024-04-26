#include <iostream>
using namespace std;
int main()
{
    // task 2
    int n1, n2;
    cout << "Enter first number : ";
    cin >> n1;
    cout << "Enter second number : ";
    cin >> n2;
    cout << "a = " << n1 << endl
         << "b = " << n2 << endl;
    if (n1 > n2)
    {
        cout << n1 << " is greater than " << n2 << endl;
        cout << "The values in acesnding order are " << endl
             << n2 << n1;
    }
    else if (n2 > n1)
    {
        cout << n2 << " is greater than " << n1 << endl;
        cout << "The values in acesnding order are " << endl
             << n1 << n2;
    }
    else
    {
        cout << "Both are equal" << endl;
    }

    return 0;
}