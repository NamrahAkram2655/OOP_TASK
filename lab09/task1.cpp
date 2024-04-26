/*NAMRAH AKRAM BITF21M542 LAB-09*/

#include <iostream>
using namespace std;

template <class t>

class Array
{
private:
    t *data;
    int size;

public:
    Array()
    {
        size = 5;
        data = new t[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    Array(int size)
    {
        this->size = size;
        data = new t[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = 0;
        }
    }

    Array(const Array &obj)
    {
        size = obj.size;
        data = new t[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = obj.data[i];
        }
    }

    ~Array()
    {
        delete[] data;
    }

    int getsize() const
    {
        return size;
    }

    void setElement(t k, int i)
    {
        if (i >= 0 && i < size)
        {
            data[i] = k;
        }
        else
        {
            cout << "out of index\n";
        }
    }

    int countElement(t key) const
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (data[i] == key)
            {
                count++;
            }
        }
        return count;
    }

    Array operator=(const Array &obj)
    {
        if (this != &obj)
        {
            delete[] data;
            size = obj.size;
            data = new t[size];

            for (int i = 0; i < size; i++)
            {
                data[i] = obj.data[i];
            }
        }
        return *this;
    }

    Array getsubArray(int start_index, int end_index)
    {
        int value = 0;
        for (int i = start_index; i <= end_index; i++)
        {
            if (start_index > 0 && start_index < end_index && end_index > 0 && end_index <= size)
            {
                value++;
            }
        }
        Array temp(value);

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

    Array operator+(Array &obj)
    {
        int s2 = size + obj.size;
        int j = 0;
        Array result(s2);

        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i];
        }
        for (int i = 0; i < s2; i++)
        {
            result.data[size + i] = obj.data[i];
            j++;
        }

        return result;
    }

    bool operator==(Array &obj) const
    {
        int count = 0;
        if (size == obj.size)
        {
            for (int i = 0; i < size; i++)
            {
                if (data[i] == obj.data[i])
                {
                    count++;
                }
            }
        }
        if (count == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    t &operator[](int index)
    {
        if (index > 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout << "out of bounds \n";

            t a = -1;

            t *x = &a;

            return *x;
        }
    }

    t operator[](int index) const
    {
        if (index > 0 && index < size)
        {
            return data[index];
        }
        else
        {
            cout << "out of bounds \n";
            t a = -1;
            return a;
        }
    }
    // void input();
    template <class t1>
    friend istream &operator>>(istream &input, Array<t1> &obj);
    template <class t2>
    friend ostream &operator<<(ostream &output, const Array<t2> &obj);
};
template <class t1>
istream &operator>>(istream &input, Array<t1> &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Enter value : " << i + 1 << " : ";
        cin >> obj.data[i];
    }
    return input;
}
// template <class t>  //just tried how to take input outside class-template
// void Array<t>::input()
// {
// }
template <class t2>
ostream &operator<<(ostream &output, const Array<t2> &obj)
{
    for (int i = 0; i < obj.size; i++)
    {
        cout << obj.data[i] << " ";
    }
    return output;
}

int main()
{

    Array<char> c1;
    c1.setElement('g', 2);
    c1[3] = 'r';
    cout << c1 << endl;

    Array<float> obj5(10);

    obj5.setElement(1.8, 0);
    obj5.setElement(23.7, 1);
    obj5.setElement(43.2, 7);

    cout << "Values of object-5 : " << obj5 << endl;

    Array<int> obj1(10);
    Array<int> obj2(10);

    obj1.setElement(44, 0);
    obj1.setElement(23, 1);
    obj1.setElement(53, 4);
    obj1.setElement(53, 5);
    obj1.setElement(2, 7);

    obj2.setElement(53, 8);
    obj2.setElement(10, 0);
    obj2.setElement(13, 1);
    obj2.setElement(53, 3);

    cout << "sub-array : " << obj1.getsubArray(1, 6);

    cout << "\nElements of obj-1: " << obj1 << endl;
    cout << "Elements of obj-2: " << obj2 << endl;

    Array<int> obj3 = obj1.operator+(obj2);
    cout << "\nConcatination of two object arrays obj1 && obj2 : " << obj3 << endl;

    cout << "\nThe count of elements : " << obj3.countElement(53) << endl;
    cout << "\nChecking if obj-1 is equal to obj-2 : " << obj1.operator==(obj2);

    return 0;
}