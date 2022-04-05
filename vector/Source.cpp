#include "Vector.h"
#include <iostream>

int main() {
	Vector a(3);
	Vector b(3);
	Vector c;

	a[0] = 1.;
	b[1] = 2.;

	b.print(1);

	c = b + a;
	std::cout << "a ";
	a.print();
	std::cout << "b ";
	b.print();
	std::cout << "c ";
	c.print();

	return 0;
}