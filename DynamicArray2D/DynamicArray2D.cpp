#include <stdio.h>
#include <stdlib.h>


int main()
{  
    int n, m;
    printf("Enter size of matrix (n and m): ");
    scanf_s("%d %d", &n, &m);


    // Allocation    
    double** arr = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        arr[i] = (double*)malloc(m * sizeof(double));
    }


    // Initialization
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = 1 + i*m+j;
        }
    }

    // Input
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < m; j++) 
    //    {
    //        printf("x%d y%d: ", i, j);
    //        scanf_s("%lf", &arr[i][j]);
    //    }
    //}
    
    // Output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%.3lf ", arr[i][j]);
        printf("\n");
    }

    // Free
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);
    return 0;
}