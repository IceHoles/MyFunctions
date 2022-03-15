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

	Vector operator=(const Vector& v) const;
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double c) const;
	Vector& operator*=(double c);

	double dot(const Vector& v) const; // double res = a.dot(b);

	double& operator[](int i);
	double operator[](int i) const;

};