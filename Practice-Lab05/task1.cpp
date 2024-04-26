#include <iostream>
#include <string>

using namespace std;

class NumDays
{
private:
    double hours;
    double days;
    void calculateDays()
    {
        days = hours / 8.0;
    }

public:
    NumDays(double h = 0.0)
    {
        hours = h;
        days = h / 8.0;
    }

    // Getter and Setter for hours
    double getHours() const
    {
        return hours;
    }
    void setHours(double h)
    {
        hours = h;
        calculateDays();
    }

    // Getter for days
    double getDays() const
    {
        return days;
    }

    // Overloaded operators
    NumDays operator+(const NumDays &other) const
    {
        return NumDays(hours + other.hours);
    }

    NumDays operator-(const NumDays &other) const
    {
        return NumDays(hours - other.hours);
    }

    NumDays &operator++()
    { // Prefix increment
        ++hours;
        calculateDays();
        return *this;
    }

    NumDays operator++(int)
    { // Postfix increment
        NumDays temp = *this;
        ++(*this);
        return temp;
    }

    NumDays &operator--()
    { // Prefix decrement
        --hours;
        calculateDays();
        return *this;
    }

    NumDays operator--(int)
    { // Postfix decrement
        NumDays temp = *this;
        --(*this);
        return temp;
    }
};

class TimeOff
{
private:
    string employeeName;
    int employeeId;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;

    const double MAX_VACATION_HOURS = 240.0;

public:
    TimeOff(const string &name, int id, double sick, double vac, double unpaid)
        : maxSickDays(sick), maxVacation(vac), maxUnpaid(unpaid)
    {
        this->employeeName = name;
        this->employeeId = id;
    }

    // Functions for storing and retrieving data
    void setEmployeeName(const string &name)
    {
        employeeName = name;
    }
    string getEmployeeName() const
    {
        return employeeName;
    }

    void setEmployeeId(int id)
    {
        employeeId = id;
    }
    int getEmployeeId() const
    {
        return employeeId;
    }

    void setMaxSickDays(double days)
    {
        maxSickDays.setHours(days * 8.0);
    }
    double getMaxSickDays() const
    {
        return maxSickDays.getDays();
    }

    void setSickTaken(double days)
    {
        sickTaken.setHours(days * 8.0);
    }
    double getSickTaken() const
    {
        return sickTaken.getDays();
    }

    void setMaxVacation(double days)
    {
        if (days * 8.0 > MAX_VACATION_HOURS)
        {
            cout << "Error: Vacation days cannot exceed 240 hours.\n";
            return;
        }
        maxVacation.setHours(days * 8.0);
    }
    double getMaxVacation() const
    {
        return maxVacation.getDays();
    }

    void setVacTaken(double days)
    {
        vacTaken.setHours(days * 8.0);
    }
    double getVacTaken() const
    {
        return vacTaken.getDays();
    }

    void setMaxUnpaid(double days)
    {
        maxUnpaid.setHours(days * 8.0);
    }
    double getMaxUnpaid() const
    {
        return maxUnpaid.getDays();
    }

    void setUnpaidTaken(double days)
    {
        unpaidTaken.setHours(days * 8.0);
    }
    double getUnpaidTaken() const
    {
        return unpaidTaken.getDays();
    }
};

int main()
{
    int monthsWorked;
    cout << "Enter the number of months the employee has worked for the company: ";
    cin >> monthsWorked;

    // Create TimeOff object
    TimeOff employee("John Doe", 1234, 0, 0, 0);

    // Calculate and display employee's maximum number of sick leave and vacation days
    employee.setMaxSickDays(8 * monthsWorked);
    employee.setMaxVacation(12 * monthsWorked / 30.0); // Assuming 30 days per month
    cout << "Employee: " << employee.getEmployeeName() << endl;
    cout << "Max Sick Leave: " << employee.getMaxSickDays() << " days\n";
    cout << "Max Vacation: " << employee.getMaxVacation() << " days\n";

    return 0;
}
