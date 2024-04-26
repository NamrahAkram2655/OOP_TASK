#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
    int yearModel;
    string makeOfCar;
    int Speed;

public:
    Car(int y1, string m1, int s1 = 0)
    {
        yearModel = y1;
        makeOfCar = m1;
        Speed = s1;
    }

    Car(const Car &obj1)
    {
        yearModel = obj1.yearModel;
        makeOfCar = obj1.makeOfCar;
        Speed = obj1.Speed;
    }

    ~Car()
    {
        cout << "Destructor executed" << endl;
    }

    // FUNCTIONS TO GET
    int getYear()
    {
        return yearModel;
    }

    string getmake()
    {
        return makeOfCar;
    }

    int getspeed()
    {
        return Speed;
    }

    // FUNCTION TO SET VALUES

    void setyear(int y1)
    {
        yearModel = y1;
    }

    void setmake(string m1)
    {
        makeOfCar = m1;
    }

    void setspeed(int s1)
    {
        Speed = s1;
    }

    // MEMBER FUNCTIONS

    void setCar(int y, string m, int s)
    {
        yearModel = y;
        makeOfCar = m;
        Speed = s;
    }

    void getCar()
    {
        cout << "Enter year Model of Car : ";
        cin >> yearModel;
        cout << "Enter Maker of Car : ";
        cin >> makeOfCar;
        cout << "Enter Speed of Car : ";
        cin >> Speed;
    }

    void putCar()
    {
        cout << yearModel << "\t\t" << makeOfCar << "\t\t" << Speed << endl;
    }

    int accelerator()
    {
        Speed = Speed + 5;
        return Speed;
    }

    int brake()
    {
        Speed = Speed - 5;
        return Speed;
    }
};

int main()
{

    cout << "USING PARAMETERIZED CONSTRUCTOR" << endl;

    cout << "Year\t\tMaker\t\tspeed" << endl;
    Car c1(2003, "SUZUKI", 700);
    c1.putCar();

    cout << "\n\n";

    cout << "USING ACCSESER AND MUTATOR" << endl;

    Car c2(0, "", 0);

    c2.setyear(2006);
    c2.setmake("TOYOTA");
    c2.setspeed(800);

    cout << "Year\t\tMaker\t\tspeed" << endl;

    cout << c2.getYear() << "\t\t" << c2.getmake() << "\t\t" << c2.getspeed() << endl;

    cout << "\n\n";

    cout << "USING SETCAR AND PUT CAR MEMBER FUNCTIONS" << endl;

    Car c3(0, "");

    cout << "Year\t\tMaker\t\tspeed" << endl;

    c3.setCar(2021, "SUZUKI ALTO", 40);
    c3.putCar();
    c3.setCar(2015, "TOYOTA CAMRY", 45);
    c3.putCar();
    c3.setCar(2011, "HONDA ACCORD", 80);
    c3.putCar();
    c3.setCar(2012, "TOYOTA PRUIS", 60);
    c3.putCar();
    c3.setCar(2018, "DAIHATSU BOON", 55);
    c3.putCar();

    cout << "\n\n";

    cout << "COPY CONSTRUCTOR\n"
         << "Year\t\tMaker\t\tspeed" << endl;
    Car c5 = c3;
    c5.putCar();

    cout << "\n\n";

    cout << "USING GETCAR" << endl;
    Car c4(0, "");

    c4.getCar();
    cout << "Year\t\tMaker\t\tspeed" << endl;
    c4.putCar();

    cout << "Accelertaor " << endl;
    c4.accelerator();
    c4.putCar();

    c4.brake();
    cout << "Brake" << endl;
    c4.putCar();

    return 0;
}