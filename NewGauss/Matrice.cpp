#include "Vector.h"
#include "Matrice.h"
#include <iostream>

Matrice::Matrice()
{
}

Matrice::Matrice(const Matrice& m)
{
	this->data = new Vector[m.l];
	for (int i = 0; i < m.l; i++)
		this->data[i] = m.data[i];
	this->l = m.l;
	this->c= m.c;
}

Matrice::Matrice(int lines, int columns)
{
	l = lines;
	c = columns;
	data = new Vector[l];
	for (int i = 0; i < l; i++)
		data[i] = Vector(c);
}

Matrice::~Matrice()
{
	delete[] data;
}

Matrice& Matrice::operator=(const Matrice& m)
{
	if (this != &m)
	{
		this->l = m.l;
		this->c = m.c;
		delete[] this->data;
		this->data = new Vector[l];
		for (int i = 0; i < l; i++)
			this->data[i] = m.data[i];
	}
	return *this;
}

Matrice& Matrice::operator+=(const Matrice& m)
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else 
	{
		for (int i = 0; i < l; i++)
			this->data[i] += m.data[i];
	}
	return *this;
}

Matrice& Matrice::operator-=(const Matrice& m)
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		for (int i = 0; i < l; i++)
			this->data[i] -= m.data[i];
	}
	return *this;
}

Matrice Matrice::operator+(const Matrice& m) const
{	
	Matrice result(l, c);
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else 
	{
		for (int i = 0; i < this->l; ++i)
			result.data[i] = this->data[i] + m.data[i];
	}
	return result;
}

Matrice Matrice::operator-(const Matrice& m) const
{
	if ((this->l != m.l) || (this->c != m.c))
		std::cout << "Err" << std::endl;
	else
	{
		Matrice result(l, c);
		for (int i = 0; i < this->l; i++)
			result.data[i] = this->data[i] - m.data[i];
		return result;
	}
}

Matrice Matrice::operator*(double d) const
{
	Matrice result(l, c);
	for (int i = 0; i < l; i++)
		result.data[i] = this->data[i] * d;
	return result;
}

Matrice& Matrice::operator*=(double d)
{
	for (int i = 0; i < l; i++)
		data[i] *= d;
	return *this;
}

Vector& Matrice::operator[](int i)
{
	return data[i];
}

Vector Matrice::operator[](int i) const
{
	return data[i];
}

Matrice Matrice::operator*(const Matrice& m)
{
	if (this->c != m.l) {
		std::cout << "Err" << std::endl;
	}
	else
	{
		Matrice result(this->l, m.c);
		for (int i = 0; i < this->l; i++)
		{
			for (int j = 0; j < m.l; j++)
			{
				for (int k = 0; k < m.l; k++)
				{
					result[i][j] += this->data[i][k] * m.data[k][j];
				}
			}
		}
		return result;
	}
}

void Matrice::swapLines(int a, int b) {
	Vector tmp = this->data[a];
	this->data[a] = this->data[b];
	this->data[b] = tmp;
}

void Matrice::printM()
{
	for (int i = 0; i < this->l; i++)
		data[i].print();
	std::cout << std::endl;
}

int Matrice::getLines() const 
{
	return this->l;
}
int Matrice::getColumns() const 
{
	return  this->c;
}

Matrice operator*(double d, const Matrice& m)
{
	return m * d;
}

std::ostream& operator<<(std::ostream& out, const Matrice& m)
{
	out << std::endl;
	for (int i = 0; i < m.l; i++)
		out << m.data[i] << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, const Matrice& m)
{
	for (int i = 0; i < m.l; i++)
		in >> m.data[i];
	return in;
}