#pragma once
#include "Vector.h"

class Matrix_Devided: public Vector {
	int lines;  
public:
	Matrix_Devided();
	Matrix_Devided(int m, int n);
	~Matrix_Devided();
	Matrix_Devided(const Matrix_Devided& M);
	Matrix_Devided(const Vector& V);
	int get_lines();
	int get_col();
	Matrix_Devided& operator=(const Matrix_Devided& M);
	Matrix_Devided& operator+=(const Matrix_Devided& M);
	Matrix_Devided operator+(const Matrix_Devided& M) const;
};