#pragma once
#include <iostream>

class Complex
{
private:
	double real;
	double img;
public:
	double getReal() {
		return real;
	}

	double getImg() {
		return img;
	}

	void setReal(double real_) {
		real = real_;
	}

	Complex(double real_ = 0, double img_ = 0);

	Complex operator+(Complex b);

	Complex operator*(Complex b);

};