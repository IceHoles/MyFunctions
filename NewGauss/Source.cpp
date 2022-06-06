#include "Vector.h"
#include "Matrix.h"
#include "GaussSolver.h"
#include <vector>
#include <iostream>


int main() {

	int m, n;
	std::cout << "enter dimensions of the Matrix ";
	std::cin >> m >> n;
	std::cout << std::endl;

	// 4 3 0 0 0 8 7 3 -7 -4 -4 -6 5 -4 0 18 -11 -15
	// 3 3 8 7 3 -7 -4 -4 -6 5 -4 18 -11 -15
	// 3 4 4 -3 2 -1 3 -2 1 -3 5 -3 1 -8 8 7 1	  not conjoint sys	  
	// 3 4 1 2 0 0 2 3 0 0 3 4 0 0 1 2 3  
	// 3 5 -1 2 1 -4 3 2 -1 -3 1 -1 3 2 -1 -2 -5 1 -4 1
	// 4 4 2 3 -1 1 8 12 -9 8 4 6 3 -2 2 3 9 -7 1 3 3 3
	// 4 4 1 3 -2 -2 -1 -2 1 2 -2 -1 3 1 -3 -2 3 3 -3 2 -2 -1
	// 4 4 1 -2 -1 3 -2 1 3 -2 2 -1 -2 1 3 -3 -2 3 2 -3 2 3
	// 5 5 1 0 2 1 3 4 1 3 2 5 3 2 4 5 7 2 3 19 5 8 5 3 5 1 4 0 0 0 0 0

	Matrix A(m, n);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			std::cin >> A[i][j];
	}
	std::cout << "matrix a:" << std::endl;
	A.printM();

	Vector b(m);
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::cout << "vector b:" << std::endl;
	b.print();
	std::cout << std::endl;


	GaussSolver solver;

	
	std::vector<Vector> res = solver.solve(A, b);

	std::cout << "result:" << std::endl;
	for (int i = 0; i < res.size(); i++) {
		std::cout << res[i] << std::endl;
	}									
}
