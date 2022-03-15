#include "Vetcor.h"
#include <iostream>

class Vector {

	double* data = 0;
	int n = 0;

public:

	Vector(){
		data = 0;
		n = 0;
	}


	Vector(int n) {
		data = new double[n];
		for (int i = 0; i < n; i++)
			data[i] = 0.0;
	}


	~Vector() {
		delete[]data;
		data = 0;
		n = 0;
	}

	void print()
	{
		std::cout << 'a' << std::endl;
	}

	void resize(int newSize) {

	}

	Vector operator=(const Vector& v) const;
	Vector operator+(const Vector& v);
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	Vector& operator*=(double c);

	double dot(const Vector& v) const; // double res = a.dot(b);

	double& operator[](int i);
	double operator[](int i) const;

};