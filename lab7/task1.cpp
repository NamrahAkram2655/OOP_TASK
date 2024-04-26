/*Namrah Akram BITF21M542*/
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setday(int day)
    {
        if (day >= 1 && day <= 31)
        {
            this->day = day;
        }
        else
        {
            this->day = 1;
        }
    }
    void setmonth(int month)
    {
        if (month >= 1 && month <= 12)
        {
            this->month = month;
        }
        else
        {
            this->month = 1;
        }
    }
    void setyear(int year)
    {
        if (year >= 1900)
        {
            this->year = year;
        }
        else
        {
            this->year = 1900;
        }
    }

    int getday()
    {
        return day;
    }
    int getmonth()
    {
        return month;
    }
    int getyear()
    {
        return year;
    }

    // constructors

    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int day, int month, int year)
    {
        setday(day);
        setmonth(month);
        setyear(year);
    }

    Date(int month, int year)
    {
        setmonth(month);
        setyear(year);
        day = 1;
    }
    ~Date()
    {
    }

    // operator overloading friend functions

    friend ostream &operator<<(ostream &output, const Date &obj);
    friend istream &operator>>(istream &input, Date &obj);

    // operator overloading

    Date operator++()
    {
        if (day == 31 && month == 12)
        {
            ++day;
            ++month;
            ++year;
            setday(day);
            setmonth(month);
        }
        else if (day == 31 && (month >= 1 && month < 12))
        {
            ++day;
            setday(day);
            ++month;
        }
        else
        {
            ++day;
            setday(day);
        }
        return *this;
    }

    Date operator++(int)
    {
        Date temp(*this);
        if (day == 31 && month == 12)
        {
            day++;
            month++;
            year++;
            setday(day);
            setmonth(month);
        }
        else if (day == 31 && (month >= 1 && month < 12))
        {
            day++;
            setday(day);

            month++;
        }
        else
        {
            day++;
            setday(day);
        }
        return temp;
    }

    Date operator--()
    {
        if (day == 1 && month == 1)
        {
            --day;
            --month;

            if (day == 0)
            {
                day = 31;
            }
            if (month == 0)
            {
                month = 12;
                --year;
            }
        }

        if (day == 1 && (month >= 1 && month < 12))
        {
            --day;
            --month;

            if (day == 0)
            {
                day = 31;
            }
        }
        else
        {
            --day;
        }

        return *this;
    }

    Date operator--(int)
    {
        Date temp(*this);
        if (day == 1 && month == 1)
        {
            day--;
            month--;

            if (day == 0)
            {
                day = 31;
            }
            if (month == 0)
            {
                month = 12;
                year--;
            }
        }

        if (day == 1 && (month >= 1 && month < 12))
        {
            day--;
            month--;

            if (day == 0)
            {
                day = 31;
            }
        }
        else
        {
            day--;
        }
        return temp;
    }

    int operator-(Date &obj)
    {
        Date temp;
        temp.day = this->day - obj.day;
        temp.month = this->month - obj.month;
        temp.year = this->year - obj.year;

        return temp.day;
    }

    bool operator+()
    {
        return ((day == 5 && month == 2) || (day == 23 && month == 3) || (day == 1 && month == 5));
    }
};
ostream &operator<<(ostream &output, const Date &obj)
{
    string MonthName;

    if (obj.month == 1)
    {
        MonthName = "January";
    }
    else if (obj.month == 2)
    {
        MonthName = "February";
    }
    else if (obj.month == 3)
    {
        MonthName = "March";
    }
    else if (obj.month == 4)
    {
        MonthName = "April";
    }
    else if (obj.month == 5)
    {
        MonthName = "May";
    }
    else if (obj.month == 6)
    {
        MonthName = "June";
    }
    else if (obj.month == 7)
    {
        MonthName = "July";
    }
    else if (obj.month == 8)
    {
        MonthName = "August";
    }
    else if (obj.month == 9)
    {
        MonthName = "September";
    }
    else if (obj.month == 10)
    {
        MonthName = "October";
    }
    else if (obj.month == 11)
    {
        MonthName = "November";
    }
    else
    {
        MonthName = "December";
    }

    cout << MonthName << " " << obj.day << "," << obj.year << endl;
}
istream &operator>>(istream &input, Date &obj)
{
    cout << "day : ";
    cin >> obj.day;
    cout << "month : ";
    cin >> obj.month;
    cout << "year : ";
    cin >> obj.year;

    obj.setday(obj.day);
    obj.setmonth(obj.month);
    obj.setyear(obj.year);
}

int main()
{
    Date obj(31, 10, 2003);

    cout << obj;
    ++obj;

    cout << "Date after increament is : " << obj;
    cout << endl;
    Date obj2(11, 12, 2003);
    cout << obj2;

    obj2++;

    cout << "Date after increament is : " << obj2;
    cout << endl;
    Date obj3(1, 1, 2001);
    cout << obj3;

    obj3--;
    cout << "Date after decreament is : " << obj3;
    cout << endl;

    Date obj4(23, 3, 2000);
    cout << "PUBLIC HOLIDAY OR NOT : " << +(obj4);
    return 0;
}