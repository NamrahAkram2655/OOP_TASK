#include <iostream>
using namespace std;
int main()
{
    // task 5
    int seconds, hours, min, days;
    cout << "Enter seconds : ";
    cin >> seconds;
    int s2 = seconds;
    if (seconds < 60)
    {
        cout << "The seconds are " << seconds << endl;
    }
    else if (seconds == 60)
    {
        min = seconds / 60;
        cout << "The minutes are " << min << " and seconds are " << seconds << endl;
    }

    if (s2 >= 86400)
    {
        days = s2 / 86400;
        cout << endl
             << "The days are " << days << endl;
    }
    else if (seconds >= 3600)
    {
        hours = seconds / 3600;
        cout << "hours : " << hours;
        seconds = seconds - (hours * 3600);
        cout << "\t seconds : " << seconds;
    }
    return 0;
}