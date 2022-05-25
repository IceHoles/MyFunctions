#pragma once
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrice.h"

class GaussSolver {
private:
	std::vector<Vector> a;
public:
	GaussSolver();
	std::vector<Vector> solve(const Matrice& A, const Vector& b);

};