/*NAMRAH AKRAM BITF21M542 HOMEWORK-2*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Cuboids
{
private:
    float height;
    float width;
    float depth;

public:
    // mutators 

    void setHeight(float height)
    {
        if (height > 0 && height < 35.00)
        {
            this->height = height;
        }
        else
        {
            this->height = 1;
        }
    }

    void setWidth(float width)
    {
        if (width > 0 && width < 35.00)
        {
            this->width = width;
        }
        else
        {
            this->width = 1;
        }
    }

    void setDepth(float depth)
    {
        if (depth > 0 && depth < 35.00)
        {
            this->depth = depth;
        }
        else
        {
            this->depth = 1;
        }
    }
    //acessors
    float getHeight()
    {
        return height;
    }

    float getWidth()
    {
        return width;
    }

    float getDepth()
    {
        return depth;
    }

    // constructors

    Cuboids(float height, float width, float depth)
    {
        setHeight(height);          //calling setters to validate values
        setWidth(width);
        setDepth(depth);
    }

    Cuboids(float height, float width)
    {
        setHeight(height);
        setWidth(width);
        depth = 0;
    }

    Cuboids()                   //default constructor
    {
        height = 0.0;
        width = 0.0;
        depth = 0.0;
    }

    Cuboids(const Cuboids &obj1)        //copy constructor
    {
        height = obj1.height;
        width = obj1.width;
        depth = obj1.depth;
    }

    ~Cuboids()
    {
        cout << "Destructor executed" << endl;
    }

    // member functions
    void setCuboids(float height, float width, float depth)
    {
       this->height=height;
       this->width=width;
       this->depth=depth;
    }

    void getCuboids()           
    {
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter weight: ";
        cin >> width;
        cout << "Enter depth: ";
        cin >> depth;
    }

    void putCuboids()
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);

        cout << height << "\t\t" << width << "\t\t" << depth << "\n\n";
    }

    float getSurfaceArea()
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);

        return (2 * (height * width) + 2 * (height * depth) + 2 * (width * depth));
    }

    float getVolume()
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);

        return (height * width * depth);
    }

    float getSpaceDiagonal()
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);

        return sqrt((height * height) + (width * width) + (depth * depth));
    }

    void putCuboidsInfo()
    {
        setHeight(height);
        setWidth(width);
        setDepth(depth);

        cout << "Height : " << height << "\tWeight : " << width << "\tdepth : " << depth << "\tSurface Area : " << getSurfaceArea() << "\tVolume : " << getVolume() << "\tSpace Diagonal : " << getSpaceDiagonal() << "\n\n\n";
    }
};

int main()
{
    Cuboids c1;
    cout << "Cuboids c1 data Parameterized constructor used \n\n";
    c1.setCuboids(2.0, 2.0, 23);

    c1.putCuboidsInfo();

    cout << "Cuboids c2 data copy constructor used \n\n";
    Cuboids c2(c1);
    c2.putCuboidsInfo();

    cout << "cuboids c3 data setter and getter used\n\n";

    Cuboids c3;

    c3.setHeight(1.2);
    c3.setWidth(2.1);
    c3.setDepth(39);

    cout << "Height : " << c3.getHeight() << "\tWeight : " << c3.getWidth() << "\tDepth : " << c3.getDepth() << "\tVolume : " << c3.getVolume() << "\t\tSurface area : " << c3.getSurfaceArea() << "\t\tSpace diagonal : " << c3.getSpaceDiagonal() << "\n\n";

    cout << "cuboids c4 data parameterized constructor\n\n";

    Cuboids c4(5, 7.1, 999.5);
    c4.putCuboidsInfo();

    return 0;
}