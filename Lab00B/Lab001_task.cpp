#include <iostream>
#include <string>
using namespace std;
float celcius(float ferhanheit)
{
    return (0.55 * (ferhanheit - 32));
}
int wordcounter(string n)
{
    int space = 1;
    for (int i = 0; n[i] != '\0'; i++)
    {
        if (n[i] == ' ')
        {
            space++;
        }
    }
    return space;
}
void getdata(int a[3][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "Enter value at a[" << i << "][" << j << "]"
                 << " : ";
            cin >> a[i][j];
        }
    }
}
void display(int a[3][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << "\t" << a[i][j];
        }
        cout << endl;
    }
}
void sum(int a1[3][3], int a2[3][3])
{
    int sum[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i][j] = a1[i][j] + a2[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "\t" << sum[i][j];
        }
        cout << endl;
    }
}
int main()
{

    // task1

    float cel, faren;
    float arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = celcius(i);
    }
    cout << "Celcius   Farenheit" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << i + 1 << "\t" << arr[i] << endl;
    }

    // task2
    int A[10];
    int result[10];
    for (int i = 0; i < 10; i++)
    {
        cout << "Enter " << i + 1 << " element : ";
        cin >> A[i];
    }
    for (int i = 0; i < 10; i++)
    {
        result[i] = A[i] + A[i + 1];
        cout << " " << result[i] << endl;
        i++;
    }

    // task 3
    int m1[3][3];
    int m2[3][3];

    int r[3][3];
    getdata(m1, 3);
    display(m1, 3);
    getdata(m2, 3);
    display(m2, 3);
    cout << "The sum of both matrices is " << endl;
    sum(m1, m2);

    // task 4
    string n;
    cout << "Enter any string : ";
    cin.ignore();
    getline(cin, n);
    int s = wordcounter(n);
    cout << "The total words are " << s << endl;

    // task 5
    string pass;
    cout << "Enter password : ";
    cin >> pass;
    int val = 0, low = 0, upper = 0;
    while (pass.length() < 6)
    {
        cout << "Enter atleast 6 letters long password : ";
        cin >> pass;
    }

    for (int i = 0; i < pass.length(); i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            low++;
        }
        else if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            upper++;
        }
        else if (pass[i] >= '0' && pass[i] <= '9')
        {
            val++;
        }
    }
    if (val >= 1 && low >= 1 && upper >= 1)
    {
        cout << "Valid password ";
    }
    else
    {
        cout << "Invalid password ";
    }

    return 0;
}