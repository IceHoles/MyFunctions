#include "Vector.h"
#include <iostream>

int main() {
	Vector a(3);
	Vector b(3);
	Vector c;

	a[0] = 1.;
	b[1] = 2.;

	c = b + a;
	a.print();
	b.print();
	c.print();

	return 0;
}