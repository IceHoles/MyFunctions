#pragma once
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrice.h"

class GaussSolver {
public:
	std::vector<Vector> solve(const Matrice& A, const Vector& b);

};