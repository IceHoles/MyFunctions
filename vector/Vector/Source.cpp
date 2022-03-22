#include "Vector.h"
#include <iostream>

int main() {
	Vector a(3);
	Vector b(3);
	Vector c;

	a[0] = 1.;
	b[1] = 2.;

	b += a;
	b.print();

}

