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
    }
    int r = m;
    for (int i = r - 1; i > 0; i--) {
        if (M[i].isNull()) {
            r -= 1;
        }
    }
    // r = rank A|b


    if (r == n - 1) {
        Vector solution(r);
        for (int i = 0; i < r; i++) {
            solution[i] = M[i][r];
            if (abs(solution[i]) < 1e-10) {
                solution[i] = 0.0;
            }
        }
        a.push_back(solution);


    } else if (r != n - 1) {
        Matrix result(n - r - 1, n - 1);
        std::vector<int> leadElem;
        std::vector<int> t;
        int ind = 0;

        for (int j = 0; j < n - 1; j++) {
            if (ind < r) {
                if (M[ind][j] == 1) {
                    leadElem.push_back(j);
                    ind++;
                    continue;
                } else t.push_back(j);
            } else t.push_back(j);
        }

        Vector newSolution(n - 1);
        for (int i = 0; i < r; i++) {
            newSolution[leadElem[i]] = M[i][n - 1];
            if (abs(newSolution[i]) < 1e-10) {
                newSolution[i] = 0.0;
            }
        } 
        a.push_back(newSolution);

        for (int k = 0; k < n - r - 1; k++) {
            for (int l = 0; l < r; l++) {
                result[k][leadElem[l]] = -M[l][t[k]];
            } 
            result[k][t[k]] = 1;
            a.push_back(result[k]);
        }
    }    
    return a;
}