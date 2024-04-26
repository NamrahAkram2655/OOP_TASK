#include <iostream>
using namespace std;
int main()
{
    //task 6
     int choice;
    cout << "\t\tMENUUUUU\t\t" << endl;
    cout << "Medium\tSpeed" << endl
         << "Air\t1100 per feet second" << endl
         << "Water\t4900 per feet second" << endl
         << "Steel\t16400 per feet second" << endl
         << endl;
    cout << "Enter your choice 1,2,3 where AIR = 1 and WATER = 2 and STEEL = 3 " << endl;
    cin >> choice;

    while (choice > 3 || choice < 1)
    {
        cout << "Enter your choice 1,2,3 where AIR = 1 and WATER = 2 and STEEL = 3 " << endl;
        cin >> choice;
    }
    int distance;
    cout << "Enter ditsnace : ";
    cin >> distance;
    int t1, t2, t3;

    if (choice == 1)
    {
        t1 = distance / 1100;
        cout << "The time is : " << t1 << endl;
    }
    else if (choice == 2)
    {
        t1 = distance / 4900;
        cout << "The time is : " << t1 << endl;
    }
    else if (choice == 3)
    {
        t1 = distance / 16400;
        cout << "The time is : " << t1 << endl;
    }
    return 0;
}