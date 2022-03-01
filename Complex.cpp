#include "Complex.h"

Complex::Complex(double real_ = 0, double img_ = 0)
{
	real = real_;
	img = img_;
}

Complex Complex::operator+(Complex b)
{
	Complex t;
	t.real = this->real + b.real;
	t.img = this->img + b.img;
	return t;
}

Complex Complex::operator*(Complex b)
{
	Complex t;
	t.real = this->real * b.real - this->img * b.img;
	t.img = this->real * b.img + this->img * b.real;
	return t;
}

void print(Complex a) 
{
	std::cout << a.getReal() << " ," << a.getImg() << 'i' << std::endl;
}