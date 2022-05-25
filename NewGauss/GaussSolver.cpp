#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrice.h"
#include "GaussSolver.h"



std::vector<Vector> GaussSolver::solve(const Matrice& M, const Vector& v) {
    std::vector<Vector> a;
    a.reserve(1);
    int l = M.getLines();
    int c = M.getColumns();
    double eps = 1e-6;

    Matrice Copy(l, c + 1);
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            Copy[i][j] = M[i][j];
        }
        Copy[i][c] = v[i];
    }
    Copy.printM();

    Matrice M1(Copy);
    
    for (int j = 0; j < M1.getLines() + 1; j++){
        std::cout << "next cycle" << std::endl; 
        if (M1[j].isNull()) {
            M1.swapLines(j, l);
            M1.popBack();      
        } 
        if (M1[j].isConjoint()) {
            return a;
        }
        double maxElement = 0;
        int line = j;
        for (int k = j; k < M1.getLines(); k++) {
            if (abs(M1[k][j]) > abs(maxElement)) {
                maxElement = M1[k][j];
                line = k;
            }
        }
        M1.swapLines(j, line);
        M1.printM();
        M1[j] *= (1 / maxElement);                 
        M1.printM();
        for (int k = 0; k < j; k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        for (int k = j+1; k < l; k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        M1.printM();        
    }

    Vector res(l);
    for (int i = 0; i < l; i++)
        res[i] = M1[i][M.getColumns()];
    
    a.push_back(res);
    
    return a;
}