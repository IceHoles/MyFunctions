#include <iostream>
#include "Matrix_Devided.h"
#include "Vector.h"

int main() {
	Vector a(25);
	for (int i = 0; i < 25; i++) {
		a[i] = i;
	}
	Vector b(25);
	for (int i = 0; i < 25; i++) {
		b[i] = 2 * i;
	}
	Matrix_Devided A(a);
	Matrix_Devided B(b);
	Matrix_Devided c;
	c = a + b;
	std::cout << a << std::endl << b << std::endl << c << std::endl;
	return 0;
}
