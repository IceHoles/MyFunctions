#include "Matrix_Devided.h"

Matrix_Devided::Matrix_Devided() :Vector(), lines(0){};

Matrix_Devided::Matrix_Devided(int m, int n):Vector(m * n) {
	this->lines = m;
}

Matrix_Devided::~Matrix_Devided(){
}

Matrix_Devided::Matrix_Devided(const Matrix_Devided& M):Vector(M){
	this->lines = M.lines;
}
Matrix_Devided::Matrix_Devided(const Vector& V) : Vector(V) {
	this->lines = 1;	 
}

int Matrix_Devided::get_lines(){
	return lines;
}

int Matrix_Devided::get_col(){
	return this->n/lines;
}

Matrix_Devided& Matrix_Devided::operator=(const Matrix_Devided& M){
	Vector::operator=(M);
	this->lines = M.lines;
	return *this;
}

Matrix_Devided& Matrix_Devided::operator+=(const Matrix_Devided& M){
	Vector::operator+=(M);
	return *this;
}

Matrix_Devided Matrix_Devided::operator+(const Matrix_Devided& M) const{
	Matrix_Devided copy(M);
	copy = Vector::operator+(M);
	return copy;
}