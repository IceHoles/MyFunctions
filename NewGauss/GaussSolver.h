#pragma once
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrix.h"

class GaussSolver {
public:
	std::vector<Vector> solve(const Matrix& A, const Vector& b);	  
	std::vector<Vector> solveWrong(const Matrix& A, const Vector& b);
};