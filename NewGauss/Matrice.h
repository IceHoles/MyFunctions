#pragma once
#include "Vector.h"
#include <iostream>

class Matrice {
private:
	Vector* data = 0;
	int l = 0;
	int c = 0;
public:
	Matrice();
	Matrice(const Matrice& m);
	Matrice(int lines, int columns);
	~Matrice();

	Matrice& operator=(const Matrice& m);
	Matrice& operator+=(const Matrice& m);
	Matrice& operator-=(const Matrice& m);
	Matrice operator+(const Matrice& m) const;
	Matrice operator-(const Matrice& m) const;
	Matrice operator*(double d) const;
	Matrice& operator*=(double d);
	Vector& operator[](int i);
	Vector operator[](int i) const;
	Matrice operator*(const Matrice& m);

	friend Matrice operator*(double d, const Matrice& m);
	friend std::ostream& operator<<(std::ostream& out, const Matrice& m);
	friend std::istream& operator>>(std::istream& in, const Matrice& m);

	void swapLines(int a, int b);
	void printM();
	int getLines() const;
	int getColumns() const;
};