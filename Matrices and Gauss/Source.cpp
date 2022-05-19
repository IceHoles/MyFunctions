#include "Vector.h"
#include "Matrice.h"
//#include "GaussSolver.h"
#include <vector>
#include <iostream>


int matrice_test() {
	Matrice a(3, 3);
	Matrice b(3, 3);
	Matrice c(4, 5);
	Matrice d(3, 3);
	a.printM();

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cin >> a[i][j];
	}
	std::cout << a;

	b = c;
	std::cout << b;

	b = a;
	std::cout << b;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cin >> b[i][j];
	}
	std::cout << b;
	
	c = a + b;
	
	std::cout << "c = a + b" << c << std::endl;

	c = a - b;
	std::cout << "c = a - b" << c << std::endl;

	c = a * 10;
	std::cout << "c = a * 10" << c << std::endl;

	c = 10 * a;
	std::cout << "c = 10 * a" << c << std::endl;

	c = a * b;
	std::cout << "c = a * b" << c << std::endl;

	d += a;
	std::cout << "d += a" << d <<  std::endl;

	d -= b;
	std::cout << "d -= b" << d <<  std::endl;

	d *= 10;
	std::cout << "d *= 10" << d << std::endl;

	return 0;
}

int main() {
	matrice_test();
	//
	//int m = 3;
	//int n = 3;
	//
	//Matrice A(m, n);
	//
	//for (int i = 0; i < m; i++) {
	//	for (int j = 0; j < n; j++)
	//		std::cin >> A[i][j];
	//}
	//
	//Vector b(n);
	//
	//for (int i = 0; i < n; i++) {
	//	std::cin >> b[i];
	//}
	//
	//GaussSolver solver;
	//
	//std::vector<Vector> res = solver.solve(A, b);
	//
	//for (int i = 0; i < n; i++) {
	//	std::cout << res[i];
	//}
}
