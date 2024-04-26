#include <iostream>
using namespace std;
int main()
{
    // task 3
    float len1, len2, width1, width2, area1, area2;
    cout << "Enter data for first rectangle " << endl;
    cout << "Enter length : ";
    cin >> len1;
    cout << "Enter width : ";
    cin >> width1;
    area1 = len1 * width1;

    cout << "Enter data for Second rectangle " << endl;
    cout << "Enter length : ";
    cin >> len2;
    cout << "Enter width : ";
    cin >> width2;
    area2 = len2 * width2;

    cout << "The area of first rectangle is " << area1 << endl
         << "The area of Second rectangle is " << area2 << endl;

    if (area1 > area2)
    {
        cout << "The length of first rectangle is greater than second " << endl;
    }
    else if (area2 > area1)
    {
        cout << "The length of second rectangle is greater than first " << endl;
    }
    else
    {
        cout << "They are equal " << endl;
    }
    return 0;
}