#include <iostream>
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "I did it now!" << endl;
    Solution sln;
    sln.Say();
    
    cout << "begin our cmake debug" << endl;
    int a = 10;
    int b = a+1;
    int c = b*b;
    cout << a << b << c << endl;

    for(int i=0; i<100; i++)
    {
        a = i + i;
        cout << a << endl;
    }

    return 0;
}