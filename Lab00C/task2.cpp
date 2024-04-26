/*Task 2 Namrah Akram BITF21m542*/

#include <iostream>
using namespace std;
void getdata(int arr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "Enter " << i + 1 << " value : ";
        cin >> arr[i];
    }
    cout << endl;
}
void displayData(const int arr[], int size)
{
    cout << "The values in array are : " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}
int counteven(const int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}
int mean(const int arr[], int size)
{
    int total = 0, count = 0;
    for (int i = 0; i < size; i++)
    {
        total = arr[i] + total;
        count++;
    }
    int m = total / count;
    return m;
}
int main()
{
    int arr[10];
    getdata(arr, 10);
    displayData(arr, 10);
    cout << "The total even numbers in array are : " << counteven(arr, 10) << endl;
    cout << "The mean of numbers in array is : " << mean(arr, 10) << endl;
    return 0;
}