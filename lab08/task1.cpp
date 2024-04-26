/*NAMRAH AKRAM BITF21M542 LAB-08*/

#include <iostream>
using namespace std;

class Collection
{
private:
    int *data;
    int size;

public:
    // Constructors
    Collection(int size)
    {
        this->size = size;

        data = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            data[i] = 0;
        }
    }

    Collection(int data2[], int size)
    {
        this->size = size;

        data = new int[this->size];

        for (int i = 0; i < this->size; i++)
        {
            data[i] = data2[i];
        }
    }

    // deep copy constructor
    Collection(const Collection &obj)
    {
        size = obj.size;

        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }

    // destructor
    ~Collection()
    {
        delete[] data;
    }

    // getter
    int getsize() const
    {
        return size;
    }

    // counting element key in array
    int countElement(int key) const
    {
        int counter = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
            {
                counter++;
            }
        }
        return counter;
    }

    // replacing the value at i index with k
    int setElement(int i, int k) const
    {
        if (i < 0 || i > size)
        {
            cout << "Out of index\n";
        }
        else if (i > 0 && i < size)
        {
            data[i] = k;
        }

        return data[i];
    }

    // Return an array with start and end index values of left hand side object
    Collection getSubCollection(int start_index, int end_index)
    {
        int value = 0;
        for (int i = start_index; i <= end_index; i++)
        {
            if (start_index > 0 && start_index < end_index && end_index > 0 && end_index <= size)
            {
                value++;
            }
        }
        Collection temp(value);

        int k = 0;
        for (int i = start_index; i <= end_index; i++)
        {
            if (start_index > 0 && start_index < end_index && end_index > 0 && end_index <= size)
            {
                temp.data[k] = data[i];
                k++;
            }
            else
            {
                temp.size = 0;
                temp.data = NULL;
            }
        }
        return temp;
    }

    // doing sum of two object arrays
    Collection operator+(Collection &obj) const
    {
        Collection result(this->size);

        for (int i = 0; i < size; i++)
        {
            if (size != obj.size)
            {
                result.size = 0;
                result.data = NULL;
            }
            else if (size == obj.size)
            {
                result.data[i] = data[i] + obj.data[i];
            }
        }
        return result;
    }

    // Assigning of R.H.S TO L.H.S
    Collection operator=(const Collection &obj)
    {
        if (this != &obj)
        {
            delete[] data;

            size = obj.size;
            data = new int[size];

            for (int i = 0; i < size; i++)
            {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }

    // Subscript operator for non-constant object
    int &operator[](int index)
    {
        if (index > 0 && index < size)
        {
            return data[index];
        }
        int a = 99;

        int *x = &a;
        cout << "INDEX IS OUT OF BOUNDS";

        return *x;
    }

    // Subscript operator for constant object
    int operator[](int index) const
    {
        if (index > 0 && index < size)
        {
            return data[index];
        }

        cout << "INDEX IS OUT OF BOUNDS";
        return 99;
    }

    // Checking that array contains negetive and 0 data collection
    bool operator-()
    {
        int c = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] <= 0)
            {
                c++;
            }
        }
        if (c == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // freind functions
    friend ostream &operator<<(ostream &output, const Collection &obj);
    friend istream &operator>>(istream &intput, Collection &obj);
};
ostream &operator<<(ostream &output, const Collection &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        output << " " << obj.data[i];
    }
    return output;
}
istream &operator>>(istream &intput, Collection &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << "\nEnter data for array : ";
        cin >> obj.data[i];
    }

    return cin;
}
int main()
{
    int array1[8] = {3, 2, 3, 4, 2, 3, 3, 2};
    int array2[8] = {1, 9, 3, 4, 2, 12, 2, 2};
    int array3[9] = {2, 6, 8, 34, 32, 12, 1, 9, 8};

    Collection cal2(array1, 8);
    Collection cal3(array2, 8), c4(8);
    cout << endl;

    cout << "Count in array : " << cal2.countElement(3);

    cout << endl;
    c4 = cal3.getSubCollection(2, 5);
    cout << "Sub-collection data : " << c4;

    cout << endl;

    c4 = cal3.operator=(cal2);
    cout << endl;
    cout << "using assignment operator : " << c4;

    cout << endl;
    const Collection cal5(array1, 8);
    cout << "Data by using subscipt operator : " << cal5[4] << endl;
    cout << " " << cal5[12];

    Collection cal6(10);
    cin >> cal6;
    cout << "\n\ntelling that all elemets in array are negetive zero or not : " << cal6.operator-();

    Collection cal1(array3, 9);
    cal1.setElement(4, 8);
    cout << "\n\nElements of array with setElement function : " << cal1;

    return 0;
}