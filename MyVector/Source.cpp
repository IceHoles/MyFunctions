#include "MyVector.h"
#include <iostream>


int main()
{
	myVector a(9);
	myVector b(6);

	a[4] = 1;
	a[8] = 5;
	b[3] = 7;

	b.print();

	b.resize(15);
	b[8] = 2;
	b.print();				  

	b = a;
	a.print();
	b.print();

	a.push_back(13.2);
	a.print();

	a.pop_back();
	a.print();

	for (int i = 0; i < a.getSize(); i++) {
		a[i] = i * 2;
	}
	a.print();
	a.erase(4);
	a.print();

	a.erase(4, 7);
	a.print();

	a.insert(1, 1);	 
	a.insert(3, 3);
	a.insert(5, 5);
	a.insert(7, 7);
	a.print();
	return 0;
}