#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrice.h"
#include "GaussSolver.h"



std::vector<Vector> GaussSolver::solve(const Matrice& M, const Vector& v) {
    std::vector<Vector> a;
    a.reserve(1);
    double eps = 1e-6;

    Matrice M1(M.getLines(), M.getColumns()+1);
    for (int i = 0; i < M.getLines(); i++) {
        for (int j = 0; j < M.getColumns(); j++) {
            M1[i][j] = M[i][j];
        }
        M1[i][M.getColumns()] = v[i];
    }
    M1.printM();
    
    for (int j = 0; j < M1.getLines(); j++){
        std::cout << "next cycle" << std::endl; 
        if (M1[j].isNull()) {
            M1.swapLines(j, M1.getLines()-1);
            M1.printM();
            M1.popBack();
            M1.printM();
        } 
        if (M1[j].isConjoint() == 0) {
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
        for (int k = j+1; k < M1.getLines(); k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        M1.printM();        
    }

    Vector res(M1.getLines());
    for (int i = 0; i < M1.getLines(); i++)
        res[i] = M1[i][M.getColumns()];
    
    a.push_back(res);
    
    return a;
}