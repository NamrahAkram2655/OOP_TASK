#include <iostream>
using namespace std;

class Employee
{
private:
    string firstname, lastname, SSn;

public:
    Employee()
    {
        this->firstname = this->lastname = this->SSn = "";
    }
    Employee(string firstname, string lastname, string SSn)
    {
        this->firstname = firstname;
        this->lastname = lastname;
        this->SSn = SSn;
    }
    void setFname(string firstname)
    {
        this->firstname = firstname;
    }
    string getFname() const
    {
        return firstname;
    }
    void setLname(string lastname)
    {
        this->lastname = lastname;
    }
    string getLname() const
    {
        return lastname;
    }
    virtual void print()
    {
        cout << "Name : " << firstname << " " << lastname << endl;
        cout << "Social security number : " << SSn << endl;
    }
    virtual double earnings() = 0;
};

class SalariedEmployee : public Employee
{
private:
    double weeklySalary;

public:
    SalariedEmployee() : Employee()
    {
    }
    SalariedEmployee(string firstname, string lastname, string SSn, double weeklySalary) : Employee(firstname, lastname, SSn)
    {
        this->weeklySalary = weeklySalary = 0;
    }

    void setWeeklysalary(double weeklysalary)
    {
        this->weeklySalary = weeklysalary;
    }

    double getweeklysalary() const
    {
        return weeklySalary;
    }

    void print()
    {
        this->Employee::print();
        cout << "Weekly salary : " << weeklySalary << endl;
    }

    double earnings()
    {
        return weeklySalary;
    }
};
class HourlyEmployee : public Employee
{
private:
    double wage, hours;

public:
    HourlyEmployee(string firstname, string lastname, string SSn, double wage, double hours) : Employee(firstname, lastname, SSn)
    {
        this->wage = wage = 0;
        this->hours = hours = 0;
    }

    void setwage(double wage)
    {
        this->wage = wage;
    }
    double getwage() const
    {
        return wage;
    }
    void sethours(double hours)
    {
        this->hours = hours;
    }
    double gethours() const
    {
        return hours;
    }
    void print()
    {
        this->Employee::print();
        cout << "Wage : " << wage << endl;
        cout << "Hours : " << hours << endl;
    }
    double earnings()
    {
        return hours * wage;
    }
};
class CommissionEmployee : public Employee
{
private:
    double grossSale, CommisionRate;

public:
    CommissionEmployee(string firstname, string lastname, string SSn, double grossSale, double CommisionRate) : Employee(firstname, lastname, SSn)
    {
        this->grossSale = grossSale = 0;
        this->CommisionRate = CommisionRate = 0;
    }

    void setgrossSale(double grossSale)
    {
        this->grossSale = grossSale;
    }

    double getGrossSale() const
    {
        return grossSale;
    }

    void setCommisionRate(double Commisionrate)
    {
        this->CommisionRate = Commisionrate;
    }

    double getCommisionRate() const
    {
        return CommisionRate;
    }

    void print()
    {
        this->Employee::print();
        cout << "Gross Sale : " << grossSale << endl;
        cout << "Commision Rate : " << CommisionRate << endl;
    }

    double earnings()
    {
        return grossSale * CommisionRate;
    }
};

class BasePlusCommisionEmployee : public CommissionEmployee
{
private:
    double baseSalary;

public:
    BasePlusCommisionEmployee(string firstname, string lastname, string SSn, double grossSale, double CommisionRate, double baseSalary) : CommissionEmployee(firstname, lastname, SSn, grossSale, CommisionRate)
    {
        this->baseSalary = baseSalary = 0;
    }

    void setbaseSalary(double baseSalary)
    {
        this->baseSalary = baseSalary;
    }
    double getbaseSalary()
    {
        return baseSalary;
    }
    void print()
    {
        this->CommissionEmployee::print();
        cout << "Base Salary : " << baseSalary << endl;
    }
    double earnings()
    {
        return this->CommissionEmployee::earnings() + baseSalary;
    }
};
int main()
{
    SalariedEmployee e1("Ayesha", "Ashraf", "Bitf21m501", 500.0);
    e1.setWeeklysalary(500.0);
    e1.print();
    cout << "Earnings : " << e1.earnings() << endl;
    cout << endl;

    HourlyEmployee h1("Namrah", "Akram", "Bitf21m542", 340.0, 10.0);
    h1.setwage(340.0);
    h1.sethours(10.0);
    h1.print();
    cout << "Earnings : " << h1.earnings() << endl;
    cout << endl;

    CommissionEmployee c1("Minahal", "Fatime", "Bitf21m515", 32.0, 10.0);
    c1.setgrossSale(32.0);
    c1.setCommisionRate(10.0);
    c1.print();
    cout << "Earnings : " << c1.earnings() << endl;
    cout << endl;

    BasePlusCommisionEmployee p1("Bisma", "Ali", "Bitf21m529", 10, 10, 10);
    p1.setbaseSalary(10);
    p1.setgrossSale(10);
    p1.setCommisionRate(10);
    p1.print();
    cout << "Earnings : " << p1.earnings() << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    Employee *pa[4];
    pa[0] = new SalariedEmployee("Ayesha", "Ashraf", "Bitf21m501", 500.0);
    pa[1] = new HourlyEmployee("Namrah", "Akram", "Bitf21m542", 340.0, 10.0);
    pa[2] = new CommissionEmployee("Minahal", "Fatima", "Bitf21m515", 32.0, 10.0);
    pa[3] = new BasePlusCommisionEmployee(p1);

    // run all data no slicing cz virtual

    for (int i = 1; i < 4; i++)
    {
        pa[i]->print();
        pa[i]->earnings();
        cout << endl;
    }

    for (int i = 0; i < 4; i++)
    {
        delete pa[i];
    }

    return 0;
}