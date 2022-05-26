#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrix.h"
#include "GaussSolver.h"



std::vector<Vector> GaussSolver::solve(const Matrix& M, const Vector& v) {
    std::vector<Vector> a;
    a.reserve(1);
    double eps = 1e-6;

    Matrix M1(M.getLines(), M.getColumns()+1);
    for (int i = 0; i < M.getLines(); i++) {
        for (int j = 0; j < M.getColumns(); j++) {
            M1[i][j] = M[i][j];
        }
        M1[i][M.getColumns()] = v[i];
    }
    //M1.printM();
    
    for (int j = 0; j < M1.getLines(); j++){
        if (M1[j].isNull()) {
            if (j == M1.getLines() - 1) {
                M1.popBack();
                //M1.printM();
                break;
            } 
            else {
                M1.swapLines(j, M1.getLines() - 1);
                //M1.printM();
                M1.popBack();
                //M1.printM();
                j--;
                continue;
            }
        } 
        if (M1[j].isConjoint() == 0) {
            std::cout << "sys has no solutions" << std::endl;
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
        if (abs(maxElement) < eps) {
            M1.swapColumns(j, M1.getColumns() - 2);
            j--;
            continue;
        }
        M1.swapLines(j, line);
        //M1.printM();
        M1[j] *= (1 / maxElement);                 
        //M1.printM();
        for (int k = 0; k < j; k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        for (int k = j+1; k < M1.getLines(); k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        //M1.printM();        
    }

    Vector offset(M1.getLines());
    for (int i = 0; i < M1.getLines(); i++)
        offset[i] = M1[i][M.getColumns()];

    a.push_back(offset);

    
    if (M1.getLines() != M1.getColumns() - 1) {
        Matrix result(M1.getColumns() - M1.getLines() - 1, M1.getLines());
        for (int i = 0; i < result.getLines(); i++) {
            for (int j = 0; j < result.getColumns(); j++) {
                result[i][j] = M1[j][M1.getColumns() - M1.getLines() + i - 1];
            }
            a.push_back(result[i]);
        }
    }  
    return a;
}