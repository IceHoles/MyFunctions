#include <iostream>
#include <vector>
#include "Vector.h"
#include "Matrix.h"
#include "GaussSolver.h"


std::vector<Vector> GaussSolver::solve(const Matrix& A, const Vector& b)
{
    std::vector<Vector> a;
    a.reserve(1);

    Matrix M(A.getLines(), A.getColumns() + 1);
    for (int i = 0; i < A.getLines(); i++) {
        for (int j = 0; j < A.getColumns(); j++) {
            M[i][j] = A[i][j];
        }
        M[i][A.getColumns()] = b[i];
    }
    
    int i = 0;   
    int n = M.getColumns();
    int m = M.getLines();   
    for (int j = 0; j < n; j++) {
        if (i > m - 1) break;
        if (M[i].isConjoint() == 0) {
            std::cout << "sys has no solutions" << std::endl;
            return a;
        }
        //int line = -1;
        //for (int k = i; k < m; k++) {
        //    if (abs(M[k][j]) > 1e-6) {
        //        line = k;
        //        break;
        //    }
        //}
        double maxElement = 0;
        int line = i;
        for (int k = i; k < m; k++) {
            if (abs(M[k][j]) > abs(maxElement)) {
                maxElement = M[k][j];
                line = k;
            }
        }
        if (abs(maxElement) < 1e-10) {
            continue;
        }
        Vector tmp = M[i];
        M[i] = M[line];
        M[line] = tmp;
        M[i] *= (1 / M[i][j]);
        for (int l = 0; l < i; l++) {
            M[l] -= M[i] * M[l][j];
        }
        for (int l = i + 1; l < m; l++) {
            M[l] -= M[i] * M[l][j];
        }
        i++;
        //M.printM();
    }
    int r = m;
    for (int i = r - 1; i > 0; i--) {
        if (M[i].isNull()) {
            r -= 1;   
        }
    }
    // r = rank A|b
    
    for (int i = 0; i < r; i++) {
        int j = i;
        while (M[i][i] != 1) {
            M.swapColumns(i, j + 1);
            //M.printM();
            j++;
        }
    }
    //M.printM();
    Vector solution(m);
    for (int i = 0; i < m; i++) {
        solution[i] = M[i][n - 1];
        if (abs(solution[i]) < 1e-10) {
            solution[i] = 0.0;
        }
    }

    a.push_back(solution);

    if (n - 1 != r) {
        Matrix result(n - r - 1, m);
        for (int i = 0; i < n - r - 1; i++) {
            for (int j = 0; j < m; j++) {
                result[i][j] = -M[j][r + i];
                if (abs(result[i][j]) < 1e-10) {
                    result[i][j] = 0.0;
                }
            }
            if (m != r) {
                result[i][r + i] = 1;
            } 
            a.push_back(result[i]);
        }
        //result.printM();
    }
    
    return a;
}


std::vector<Vector> GaussSolver::solveWrong(const Matrix& M, const Vector& v) {
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
    M1.printM();
    
    for (int j = 0; j < M1.getLines(); j++){
        //if (M1[j].isNull()) {
        //    if (j == M1.getLines() - 1) {
        //        M1.popBackLine();
        //        break;
        //    } 
        //    else {
        //        M1.swapLines(j, M1.getLines() - 1);
        //        M1.printM();
        //        M1.popBackLine();
        //        M1.printM();
        //        j--;
        //        continue;
        //    }
        //} 
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
            M1.swapColumns(j, j + 1);
            j--;
            continue;
        }
        
        M1.swapLines(j, line);
        M1[j] *= (1 / maxElement);                 
        
        for (int k = 0; k < j; k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
        for (int k = j+1; k < M1.getLines(); k++) {
            M1[k] -= M1[j] * M1[k][j];
        }
    }

    //for (int j = M1.getLines(); j < M1.getColumns()+1; j++) {
    //    double maxElement = 0.0;
    //    for (int i = 0; i < M1.getLines(); i++) {
    //        if (abs(M1[i][j]) > abs(maxElement))
    //            maxElement = M1[i][j];
    //    }
    //    if (abs(maxElement) < eps) {
    //        M1.swapColumns(j, M1.getColumns() - 1); 
    //        M1.popBackColumn();
    //    }
    //}

    M1.printM();
    Vector offset(M1.getLines());
    for (int i = 0; i < M1.getLines(); i++)
        offset[i] = M1[i][M.getColumns()];

    a.push_back(offset);

    
    if (M1.getLines() != M1.getColumns() - 1) {
        Matrix result(M1.getColumns() - M1.getLines() - 1, M1.getLines());
        for (int i = 0; i <result.getLines(); i++) {
            for (int j = 0; j < result.getColumns(); j++) {
                result[i][j] = -M1[j][M1.getLines() + i];
            }
            a.push_back(result[i]);
        }
        result.printM();
    }  
    return a;
}
