
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:

    int regno;
    string firstName;
    string lastName;
    string program;
    float cgpa;

public:

    void setregno(int regno)
    {
        if (regno >= 501 && regno <= 565)
        {
            this->regno = regno;
        }
        else
        {
            this->regno = 0;
        }
    }
    void setFname(string fisrtName)
    {
        this->firstName = firstName;
    }

    void setLname(string lastName)
    {
        this->lastName = lastName;
    }

    void setProgram(string ptogram)
    {
        this->program = program;
    }

    void setCGPA(float cgpa)
    {
        if (cgpa >= 0.0 && cgpa <= 4.00)
        {
            this->cgpa = cgpa;
        }
        else
        {
            this->cgpa = -1;
        }
    }

    int getRegno()
    {
        return regno;
    }

    string getFname()
    {
        return firstName;
    }
    string getLname()
    {
        return lastName;
    }
    string getProgram()
    {
        return program;
    }
    float getCGPA()
    {
        return cgpa;
    }

    Student(int regno, string firstName, string lastName, string program)
    {
        setregno(regno);
        this->firstName = firstName;
        this->lastName = lastName;
        this->program = program;
        cgpa = -1;
    }

    Student(int regno, string firstName, string program)
    {
        setregno(regno);
        this->firstName = firstName;
        this->lastName = "";
        this->program = program;
        cgpa = -1;
    }

    Student(int regno, string firstName, string lastName, string program, float cgpa)
    {
        setregno(regno);
        setCGPA(cgpa);
        this->firstName = firstName;
        this->lastName = lastName;
        this->program = program;
    }
    Student(const Student &obj)
    {
        regno = obj.regno;
        firstName = obj.firstName;
        lastName = obj.lastName;
        program = obj.program;
        cgpa = obj.cgpa;
    }

    ~Student()
    {
        cout << "Destructor executed \n";
    }

    // Member Functions

    void setData(int regno, string firstName, string lastName, string program, float cgpa)
    {
        setregno(regno);
        setCGPA(cgpa);
        this->firstName = firstName;
        this->lastName = lastName;
        this->program = program;
    }

    void read()
    {
        cout << "ENTER DATA OF STUDENT \n\n";
        cout << "Enter regno: ";
        cin >> regno;
        cout << "Enter first name : ";
        cin.ignore();
        getline(cin, firstName);
        cout << "Enter Last Name : ";
        getline(cin, lastName);
        cout << "Enter Program : ";
        getline(cin, program);
        cout << "Enter Cgpa : ";
        cin >> cgpa;
    }

    void write()
    {
        setregno(regno);
        setCGPA(cgpa);
        cout << "\nDATA OF STUDENT" << endl;
        cout << "Registration No : " << regno << "\tFirst Name : " << firstName << "\tLast Name : " << lastName << "\tProgram : " << program << "\tCgpa : " << cgpa;
    }

    bool isFirstSemester()
    {
        return (cgpa == -1);
    }
    float getPercentage()
    {
        if (cgpa > 0.0)
        {
            return ((cgpa / 4) * 100);
        }
        else
        {
            return -1;
        }
    }
    bool isPromoted()
    {
        return (cgpa > 2);
    }
};

int main()
{
    Student s1(5581, "Namrah", " Akram", "BSIT", 4.64);

    Student s2(0, "", "", "", 0);
    s2.read();
    s2.write();
    Student s3(0, "", "", "", 0);
    s3.setData(522, "Malika", " don", "Bsit", 3.76);

    s1.write();

    cout << "\tPercentage : " << s1.getPercentage() << "\t Promoted : " << s1.isPromoted() << "\tfirst Seme :" << s1.isFirstSemester() << "\n";

    s2.write();

    cout << "\tPercentage : " << s2.getPercentage() << "\t Promoted : " << s2.isPromoted() << "\tfirst Seme :" << s2.isFirstSemester() << "\n";

    s3.write();

    cout << "\tPercentage : " << s3.getPercentage() << "\t Promoted : " << s3.isPromoted() << "\tfirst Seme :" << s3.isFirstSemester();

    Student s4(0,"","","",0);

    s4.setregno(540);
    s4.setFname("Rida");
    s4.setLname("Fatima");
    s4.setProgram("bsit");
    s4.setCGPA(3.8);

    s4.write();
    cout << "\tPercentage : " << s4.getPercentage() << "\t Promoted : " << s4.isPromoted() << "\tfirst Seme :" << s4.isFirstSemester();
    cout << "\n\n";
    return 0;
}