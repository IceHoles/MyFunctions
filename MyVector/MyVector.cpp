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
	int min = this->size < newSize ? this->size : newSize;
	if (newSize < this->capacity) 
	{
		this->size = newSize;
	}
	else 
	{
		double* copy = new double[newSize];
		memcpy(copy, this->data, min * sizeof(double));
		for (int i = min; i < newSize; i++) 
		{
			copy[i] = 0;
		}
		delete[] this->data;
		this->data = copy;
		this->size = newSize;
		this->capacity = constant * newSize;
	}
}

myVector& myVector::operator=(const myVector& v) 
{
	if (this == &v)
	{
		return *this;
	}
	delete[] this->data;
	this->data = new double[v.size];
	memcpy(this->data, v.data, v.size * sizeof(double));
	this->size = v.size;
	this->capacity = constant * size;
	return *this;
}

void myVector::push_back(double a) 
{
	this->data[size] = a;
	this->resize(size + 1);
}

int myVector::getSize()
{
	return size;
}

void myVector::print(int i)
{
	std::cout << this->data[i] << ' ';
}

double& myVector::operator[](int i)
{
	return this->data[i];
}

double myVector::operator[](int i) const
{
	return this->data[i];
}