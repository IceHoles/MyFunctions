#include <iostream>
#include "MyVector.h"
#define constant 2


myVector::myVector(int n) 
{
	data = new double[constant * n];
	for (int i = 0; i < constant * n; i++)
	{
		data[i] = 0;
	}
	capacity = constant * n;
	size = n;
}

myVector::~myVector()
{
	delete[] data;
}

myVector::myVector(const myVector& v) 
{
	resize(v.size);
	memcpy(this->data, v.data, size * sizeof(double));
}

void myVector::resize(int newSize) 
{
	if (newSize < this->capacity) 
	{
		this->size = newSize;
	}
	else 
	{
		double* copy = new double[constant * newSize];
		for (int i = 0; i < this->size; i++)
			copy[i] = data[i];
		for (int i = this->size; i < newSize; i++)
			copy[i] = 0;
		delete[] this->data;
		this->data = copy;
		this->size = newSize;
		this->capacity = constant * newSize;
	}
}

myVector& myVector::operator=(const myVector& v) 
{
	if (this == &v) return *this;
	this->resize(v.size);
	for (int i = 0; i < v.size; i++) 
		this->data[i] = v.data[i];
	return *this;
}

void myVector::push_back(double a) 
{
	this->resize(size + 1);	
	this->data[size - 1] = a;
}

void myVector::pop_back()
{
	this->resize(size - 1);
}

void myVector::erase(int a)
{	
	if (a < this->size) {
		this->resize(size - 1);
		for (int i = a; i < size; i++)
			this->data[i] = this->data[i + 1];
	}
	else {
		for (int i = a; i < size; i++)
			this->data[i] = this->data[i + 1];
	}
}

void myVector::erase(int a, int b)
{
	if (b < this->size)
	{
		this->resize(size + a - b - 1);
		for (int i = a; i < b; i++)
			this->data[i] = this->data[i + b + 1];
	}
	else {
		this->resize(a);
	}
}

void myVector::insert(int i, double a)
{
	if (i < size) {
		this->resize(size + 1);
		for (int e = size; e > i; e--) {
			this->data[e] = data[e - 1];
		}
		this->data[i] = a;
	}
	else this->push_back(a);
}

double& myVector::operator[](int i)
{
	if(i < this->size)
		return this->data[i];
}

double myVector::operator[](int i) const
{		
	if (i < this->size)
		return this->data[i];
}

int myVector::getSize()
{
	return size;
}

void myVector::print()
{
	std::cout << getSize() << std::endl;
	for (int i = 0; i < size; i++)
		std::cout << this->data[i] << ' ';
	std::cout << std::endl;
}

void myVector::print(int i)
{
	std::cout << this->data[i] << ' ';
}