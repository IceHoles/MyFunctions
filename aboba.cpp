#include <iostream>
#include "Complex.h"
#include "Complex.cpp"
using namespace std;

int main()
{
    Complex c;
    //c.setReal(2);
    cout << c.getReal() << endl;
    Complex c1(1.2, 4.2), c2(3.6, 7.2);
    Complex c3 = c1 * c2;

    print(c3);
    return 0;
}