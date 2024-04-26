#include <iostream>

using namespace std;

int main()
{
    int size;

    // Ask the user to enter the size of the float array
    cout << "Enter the size of the float array: ";
    cin >> size;

    // Allocate memory to the float array based on the user input size
    float *arr = new float[size];

    // Initialize the array content by reading them from the user
    cout << "Enter " << size << " float numbers:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    // Calculate the sum of array elements
    float sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    // Calculate and display the average of array elements
    float average = sum / size;
    cout << "Average of array elements: " << average << endl;

    // Free allocated memory
    delete[] arr;

    return 0;
}
