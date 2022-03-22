#include "Vector.h"
#include <iostream>

Vector::Vector()
{
	data = 0;
	n = 0;
}

Vector::Vector(int n)
{
	data = new double[n];
	for (int i = 0; i < n; i++)
		data[i] = 0.0;
}


Vector::~Vector() {
	delete[]data;
	data = 0;
	n = 0;
}

int Vector::getSize() {
	return n;
}

void Vector::print()
{
	for (int i = 0; i < n; i++) {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void Vector::resize(int newSize)
{
	data = new double[newSize];
}


Vector Vector::operator=(const Vector& v) const {
	if (this != &v) {
		return *this;
	}
	for (int i = 0; i < n; i++)
		data[i] = v[i];
	return *this;
}

/*
Vector Vector::operator+(const Vector& v) const {

}
Vector Vector::operator-(const Vector& v) const {

}
Vector& Vector::operator+=(const Vector& v) {

}
Vector& Vector::operator-=(const Vector& v) {

}
Vector Vector::operator*(double c) const {

}
Vector& Vector::operator*=(double c) {

}
double Vector::dot(const Vector& v) const { // double res = a.dot(b);

}
*/
double& Vector::operator[](int i) {
	return data[i];
}
double Vector::operator[](int i) const {
	return data[i];
}
