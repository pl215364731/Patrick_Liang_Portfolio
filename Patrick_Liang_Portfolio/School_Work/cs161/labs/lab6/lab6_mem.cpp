#include <iostream>

using namespace std;

int* create_int()
{
   int* ptr = new int;
    return ptr;
}

void create_int(int*& ptr)
{
    ptr = new int;
}
void create_int2(int** ptr)
{
    *ptr = new int;
}
void assign(int*& ptr)
{
    *ptr = 6;
}

int main()
{
   int* ptr2 = NULL;
    int* ptr = NULL;
    create_int(ptr);
    create_int2(&ptr2);
    assign(ptr);
    cout << *ptr << endl;

    delete ptr2;
    ptr2 = NULL;

    delete ptr;
    ptr = NULL;
    return 0;
}

