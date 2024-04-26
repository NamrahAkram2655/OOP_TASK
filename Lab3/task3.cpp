#include <iostream>
#include <string>
using namespace std;

char *UpperCaseFunction(const char *str)
{
    int count = 0;
    char *ptr = new char[40];
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (*(str + i) >= 'a' && *(str + i) <= 'z')
        {
            *(ptr + i) = *(str + i) - 32;
        }
        else if (*(str + i) >= 'A' && *(str + i) <= 'Z')
        {
            *(ptr + i) = *(str + i) + 32;
        }
        else if (*(str + i) == ' ')
        {
            *(ptr + i) = ' ';
        }
        else
        {
            *(ptr + i) = *(str + i);
        }
    }

    return ptr;
}

int main()
{
    string str;
    cout << "Enter any string: ";
    getline(cin, str);

    char *create = UpperCaseFunction(&str[0]);

    for (int i = 0; str[i] != '\0'; i++)
    {
        cout << *(create + i);
    }

    if (create != NULL)
    {
        delete[] create;
    }

    return 0;
}