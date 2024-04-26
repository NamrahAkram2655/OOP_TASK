#include "iostream"

using namespace std;

class FeetInches
{
private:
	int feet;	// To hold a number of feet
	int inches; // To hold a number of inches

	void simplify()
	{
		if (inches >= 12)
		{
			feet += (inches / 12);
			inches = inches % 12;
		}
		else if (inches < 0)
		{
			feet -= ((abs(inches) / 12) + 1);
			inches = 12 - (abs(inches) % 12);
		}
	}

public:
	// Constructor
	FeetInches(int f = 0, int i = 0)
	{
		feet = f;
		inches = i;
		simplify();
	}

	FeetInches(const FeetInches& right)
	{
		feet = right.feet;
		inches = right.inches;
		simplify();
	}

	// Mutator functions
	void setFeet(int f)
	{
		feet = f;
	}

	void setInches(int i)
	{
		inches = i;
		simplify();
	}

	// Accessor functions
	int getFeet() const
	{
		return feet;
	}

	int getInches() const
	{
		return inches;
	}

	FeetInches operator+(const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches + right.inches;
		temp.feet = feet + right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator-(const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches - right.inches;
		temp.feet = feet - right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator*(const FeetInches& right)
	{
		FeetInches temp;

		temp.inches = inches * right.inches;
		temp.feet = feet * right.feet;
		temp.simplify();

		return temp;
	}

	FeetInches operator++()
	{
		++inches;
		simplify();

		return *this;
	}

	FeetInches operator++(int)
	{
		FeetInches temp(feet, inches);

		inches++;
		simplify();

		return temp;
	}

	FeetInches operator--()
	{
		--inches;
		simplify();

		return *this;
	}

	FeetInches operator--(int)
	{
		FeetInches temp(feet, inches);

		inches--;
		simplify();

		return temp;
	}

	bool operator>(const FeetInches& right)
	{
		bool status;

		if (feet > right.feet)
			status = true;
		else if (feet == right.feet && inches > right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator<(const FeetInches& right)
	{
		return !(*this > right);
	}

	bool operator>=(const FeetInches& right)
	{
		bool status;

		if (feet >= right.feet)
			status = true;
		else if (feet == right.feet && inches >= right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator<=(const FeetInches& right)
	{
		return !(*this >= right);
	}

	bool operator==(const FeetInches& right)
	{
		bool status;

		if (feet == right.feet && inches == right.inches)
			status = true;
		else
			status = false;

		return status;
	}

	bool operator!=(const FeetInches& right)
	{
		return !(*this == right);
	}

	friend ostream& operator<<(ostream&, const FeetInches&);
	friend istream& operator>>(istream&, FeetInches&);
};

ostream& operator<<(ostream& out, const FeetInches& obj)
{
	out << "Feet = " << obj.feet << "\tInches = " << obj.inches << endl;

	return out;
}

istream& operator>>(istream& in, FeetInches& obj)
{
	cout << "Enter Feet:\t";
	in >> obj.feet;

	cout << "Enter Inches:\t";
	in >> obj.inches;

	return in;
}

class RoomDimension
{
private:
	FeetInches length;
	FeetInches width;

public:

	void setlength(int feet, int inches)
	{
		length.setFeet(feet);
		length.setInches(inches);
	}
	void setwidth(int feet, int inches)
	{
		width.setFeet(feet);
		width.setInches(inches);
	}

	FeetInches getlength() const
	{
		length.getFeet();
		length.getInches();

		return length;
	}

	FeetInches getwidth() const
	{
		width.getFeet();
		width.getInches();

		return width;
	}

	RoomDimension(FeetInches length, FeetInches width) :length(length), width(width)
	{

	}

	FeetInches getarea() 
	{
		return FeetInches(length * width);
	}

	void display()
	{
		cout << length;
        cout<< width << endl;
	}
};

class RoomCarpet
{
private:

	RoomDimension roomSize;
	float costPerSquareFoot;

public:
	
	void setRoomsize(int lengthf, int widthf, int lengthi,int widthi)
	{
		roomSize.setlength(lengthf, lengthi);
		roomSize.setwidth(widthf, widthi);
	}

	void setcost(float costPerSquareFoot)
	{
		this->costPerSquareFoot = costPerSquareFoot;
	}

	RoomDimension getRoomsize()
	{
		roomSize.getlength();
		roomSize.getwidth();

        return roomSize;
	}

	RoomCarpet(RoomDimension roomSize, float costPerSquareFoot):roomSize(roomSize)
	{
		this->costPerSquareFoot = costPerSquareFoot;
	}

	static float costCarpet(RoomDimension f1 , float cost)
	{
		return  cost * (f1.getlength().getFeet()*f1.getwidth().getFeet());
	}

	void print()
	{
		cout <<"cost : " <<costPerSquareFoot << endl;
		roomSize.display();
	}
};

int main()
{
	FeetInches f1(2, 3);
	FeetInches f2(4, 5);

	RoomDimension r1(f1,f2);
	r1.display();

	cout << "Area is : " << r1.getarea() << endl;

	RoomCarpet c1(r1,4);
	c1.print();

	cout<<"Total cost of carpet is : "<<RoomCarpet::costCarpet(r1, 4);


	return 0;
}