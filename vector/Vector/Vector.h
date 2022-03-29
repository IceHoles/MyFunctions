#pragma once

class Vector {
private:
	double* data = 0;
	int n = 0;
public:
	Vector();
	Vector(int n);
	~Vector();

	void resize(int newSize);
	void print();
	void print(int i);
	int getSize();
	double getValue(int i);


	Vector operator=(const Vector& v) const;
	Vector operator+(const Vector& v) const;
	/*
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	Vector& operator*=(double c);

	double dot(const Vector& v) const; // double res = a.dot(b);
	*/
	double& operator[](int i);
	double operator[](int i) const;

};
