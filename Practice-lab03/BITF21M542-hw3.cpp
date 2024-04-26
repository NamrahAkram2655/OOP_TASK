/*Namrah Akram BITF21m542 Homwwork-3*/

#include <iostream>
#include <string>

using namespace std;

class Circle
{
private:
    int x, y; // private data members
    float radius;
    static const double PI;

public:
    void setx(int x) // setters
    {
        if (x >= -50 && x <= 50)
        {
            this->x = x;
        }
        else
        {
            this->x = 0;
        }
    }

    void sety(int y)
    {
        if (y >= -50 && y <= 50)
        {
            this->y = y;
        }
        else
        {
            this->y = 0;
        }
    }

    void setr(float radius)
    {
        if (radius >= 1 && radius <= 10)
        {
            this->radius = radius;
        }
        else
        {
            this->radius = 5;
        }
    }

    int getx() const // getters
    {
        return x;
    }

    int gety() const
    {
        return y;
    }

    float getr() const
    {
        return radius;
    }

    const double getp()
    {
        return PI;
    }

    Circle(int x, int y, float radius) // constructors
    {
        setx(x);
        sety(y);
        setr(radius);
    }

    Circle(int x, float radius)
    {
        setx(x);
        setr(radius);
    }

    Circle(int x, int y)
    {
        setx(x);
        sety(y);
    }

    Circle()
    {
        this->x = 0;
        this->y = 0;
        this->radius = 5.0;
    }

    Circle(const Circle &obj) // copy constructor
    {
        x = obj.x;
        y = obj.y;
        radius = obj.radius;
    }

    ~Circle() // destructor
    {
        cout << "Destructor executed" << endl;
    }

    void setCircle(int x, int y, float radius) // Member Functions
    {
        setx(x);
        sety(y);
        setr(radius);
    }

    void getCircle()
    {
        cout << "Enter value of x: ";
        cin >> x;
        cout << "Enter value of y : ";
        cin >> y;
        cout << "Enter radius : ";
        cin >> radius;

        setx(x);
        sety(y);
        setr(radius);
    }

    void putCircle() const
    {
        cout << "Vlaue of x : " << x << "\t\ty: " << y << "\t\tradius: " << radius << endl;
    }

    double getArea() const
    {
        return PI * (radius * radius);
    }

    double getDiameter() const
    {
        return (2 * radius);
    }

    double getCircumference() const
    {
        return (2 * PI * radius);
    }

    Circle addCircle(const Circle &obj) const
    {
        return Circle(x + obj.x, y + obj.y, radius + obj.radius);
    }

    bool isEqual(const Circle &obj) const
    {
        return (x == obj.x && y == obj.y && radius == obj.radius);
    }

    int findCircle(const Circle arr[], const int size) const
    {
        for (int i = 0; i < size; i++)
        {
            if (x == arr[i].x && y == arr[i].y && radius == arr[i].radius)
            {
                return i;
            }
            return -1;
        }
    }

    Circle updateObjects(Circle ar[], const int size)
    {
        for (int i = 0; i < size; i++)
        {
            if (ar[i].x == x && ar[i].y == y)
            {
                ar[i].radius = radius;
                return ar[i];
            }
        }
    }
};

const double Circle::PI = 3.141593;

int main()
{
    Circle c1(6, 2, 1.0), c2(10, 2, 1.0);

    cout << "C1 : ";
    c1.putCircle();
    cout << "C2 : "; // printing data of circle
    c2.putCircle();

    cout << "\n\n";

    cout << "Area of circle c1 : " << c1.getArea() << endl;
    cout << "Circumference c1 : " << c1.getCircumference() << endl;
    cout << "Diameter c1 : " << c1.getDiameter() << endl;
    cout << "Checking if c1 is equal to c2 : " << c1.isEqual(c2) << endl;

    cout << "\n\nAdding c1 and c3 \n\n"; // addition function

    Circle c3(3, 5, 100);
    c3 = c3.addCircle(c1);
    c3.putCircle();

    Circle c6(2, -544, 8);
    cout << "C6 : ";

    c6.putCircle();
    cout << "\n\nUpdating c5 object radius with of c6\n\n";

    // updating array with object radius

    Circle c5[10];
    cout << "\nEnter data for array \n\n";
    for (int i = 0; i < 2; i++)
    {
        c5[i].getCircle(); // taking input
    }

    c6 = c6.updateObjects(c5, 2);

    c6.putCircle();

    cout << "\n\n Printing data of Array now :  \n";
    for (int i = 0; i < 2; i++)
    {
        c5[i].putCircle(); // printing array
    }

    return 0;
}