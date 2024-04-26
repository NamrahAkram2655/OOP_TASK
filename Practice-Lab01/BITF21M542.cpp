/*BITF21M542 - NAMRAH AKRMA HOMEWORK-4*/

#include <iostream>
#include <string>

using namespace std;

class RationalNumber
{
private:
    int numinator; // private members
    int denominator;

public:

    void setnuminator(int numinator) // setters
    {
        this->numinator = numinator;
    }

    void setdenominator(int denominator)
    {
        if (denominator > 0)
        {
            this->denominator = denominator;
        }
        else
        {
            this->denominator = 1;
        }
    }

    int getnuminator() const // getters
    {
        return numinator;
    }

    int getdenominator() const
    {
        return denominator;
    }

    // Constructors

    RationalNumber(int numinator, int denominator)
    {
        setnuminator(numinator);
        setdenominator(denominator);
    }

    RationalNumber(int numinator)
    {
        setnuminator(numinator);
    }

    // OPERATOR OVERLOADING MEMBER FUNCTIONS

    RationalNumber operator+(const RationalNumber &obj) const
    {
        RationalNumber temp(0, 0);

        temp.numinator = (this->numinator) * obj.denominator + (this->denominator) * obj.numinator;

        temp.denominator = this->denominator * obj.denominator;

        return temp;
    }

    RationalNumber operator-(const RationalNumber &obj) const
    {
        RationalNumber temp(0, 0);

        temp.numinator = (this->numinator) * obj.denominator - (this->denominator) * obj.numinator;

        temp.denominator = this->denominator * obj.denominator;

        return temp;
    }

    RationalNumber operator*(const RationalNumber &obj) const
    {
        RationalNumber temp(0, 0);

        temp.numinator = this->numinator * obj.numinator;
        temp.denominator = this->denominator * obj.denominator;

        return temp;
    }

    RationalNumber operator/(const RationalNumber &obj) const
    {
        RationalNumber temp(0, 0);

        temp.numinator = this->numinator * obj.denominator;
        temp.denominator = this->denominator * obj.numinator;

        return temp;
    }

    bool operator==(const RationalNumber &obj) const
    {
        return ((this->numinator) * obj.denominator == (this->denominator) * obj.numinator);
    }

    bool operator<(const RationalNumber &obj)
    {
        return (this->numinator * obj.denominator) < (this->denominator * obj.numinator);
    }

    RationalNumber operator-() const
    {
        if (numinator > 0)
        {
            return RationalNumber((-numinator), (denominator));
        }
        else
        {
            return RationalNumber((numinator), (denominator));
        }
    }

    bool operator!()
    {
        return (numinator < 0 || denominator < 0);
    }

    // class Friend function

    friend istream &operator>>(istream &input, RationalNumber &obj);
    friend ostream &operator<<(ostream &print, const RationalNumber &obj);
};

// defining class functions globally

istream &operator>>(istream &input, RationalNumber &obj)
{
    cout << "Numinator = ";
    input >> obj.numinator;
    cout << "Denominator = ";
    input >> obj.denominator;

    obj.setdenominator(obj.denominator);

    return input;
}

ostream &operator<<(ostream &print, const RationalNumber &obj)
{
    print << obj.numinator << "/" << obj.denominator << endl;

    return print;
}

int main()
{
    RationalNumber r1(3, 5), r2(7, 8);
    cout << r1 << r2;
    cout << r1 / r2;
    cout << r1 + r2;
    cout << r1 - r2;
    cout << r1 * r2;
    cout<<(r1<r2)<<endl;
    cout<<(r1==r2);
    return 0;
}