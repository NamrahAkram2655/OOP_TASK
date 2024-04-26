#include <iostream>

using namespace std;

int main()
{
    int *ptrX = NULL;
    int *ptrY = NULL;

    int *a = new int(2);
    int *b = new int(8);

    ptrX = a;
    ptrY = b;

    cout << "The address at ptrX is : " << ptrX << " " << *a << " and value is : " << *ptrX << " and it points to memory location : " << a << endl;

    cout << "The address at ptrY is : " << ptrY << " " << *b << " and value is : " << *ptrY << " and it points to memory location : " << b << endl;

    delete (a);
    delete (b);

    return 0;
}