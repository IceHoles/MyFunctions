#include "MyVector.h"
#include <iostream>


int main()
{
	myVector a(9);
	myVector b(6);

	a[4] = 1;
	a[8] = 5;
	b[3] = 7;

	for (int i = 0; i < b.getSize(); i++) {
		b.print(i);
	}
	std::cout << std::endl;

	b.resize(15);

	b[8] = 2;

	for (int i = 0; i < b.getSize(); i++) {
		b.print(i);
	}
	std::cout << std::endl;

	b = a;

	for (int i = 0; i < a.getSize(); i++) {
		a.print(i);
	}
	std::cout << std::endl;

	for (int i = 0; i < b.getSize(); i++) {
		b.print(i);
	}
	std::cout << std::endl;

	std::cout << a.getSize() << std::endl;

	for (int i = 0; i < a.getSize(); i++) {
		a.print(i);
	}
	std::cout << std::endl;

	a.push_back(3.);

	std::cout << a.getSize() << std::endl;

	for (int i = 0; i < a.getSize(); i++) {
		a.print(i);
	}
	std::cout << std::endl;
	
	return 0;
}