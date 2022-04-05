#include "Vector.h"
#include <iostream>

Vector::Vector()
{
	data = 0;
	n = 0;
}

Vector::Vector(int n)
{
	this->n = n;
	this->data = new double[n];
	for (int i = 0; i < n; i++)
		this->data[i] = 0.0;
}

Vector::Vector(const Vector& v)
{
	this->n = v.n;
	this->data = new double[n];
	memcpy(this->data, v.data, n);
}

Vector::~Vector()
{
	delete[]data;
	data = 0;
	n = 0;
}

int Vector::getSize()
{
	return n;
}

double Vector::getValue(int i)
{
	return data[i];
}

void Vector::print()
{
	for (int i = 0; i < this->n; i++)
	{
		std::cout << this->data[i] << " ";
	}
	std::cout << std::endl;
}

void Vector::print(int i)
{
	std::cout << this->data[i] << std::endl;
}

void Vector::resize(int newSize)
{
	data = new double[newSize];
}


Vector Vector::operator=(const Vector& v) {
	if (this != &v) 
	{
		return *this;
	}
	this->n = v.n;
	memcpy(this->data, v.data, n);
	return *this;
}


Vector Vector::operator+(const Vector& v) const
{
	for (int i = 0; i < n; i++)
		this->data[i] = data[i] + v.data[i];
	return *this;
}
/*
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
double& Vector::operator[](int i)
{
	return this->data[i];
}
double Vector::operator[](int i) const
{
	return this->data[i];
}
