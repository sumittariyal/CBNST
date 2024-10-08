// gauss siedal
#include <stdio.h>
#include <math.h>

float f1(float mat[][4], float x, float y, float z, int n) {  // Change 4 to n + 1 for generality
    return (mat[0][n] - (mat[0][1] * y + mat[0][2] * z)) / mat[0][0];
}

float f2(float mat[][4], float x, float y, float z, int n) {  // Change 4 to n + 1 for generality
    return (mat[1][n] - (mat[1][0] * x + mat[1][2] * z)) / mat[1][1];
}

float f3(float mat[][4], float x, float y, float z, int n) {  // Change 4 to n + 1 for generality
    return (mat[2][n] - (mat[2][0] * x + mat[2][1] * y)) / mat[2][2];
}

int main() {
    int n;
    printf("Enter the order of the matrix (number of equations): ");
    scanf("%d", &n);

    float mat[n][n+1];  // Adjust the matrix declaration
    int validMatrix = 0;

    while (!validMatrix) {
        validMatrix = 1;
        for (int i = 0; i < n; i++) {
            printf("\nEnter the elements in row %d (coefficients and constant): ", i + 1);
            for (int j = 0; j <= n; j++) {
                scanf("%f", &mat[i][j]);
            }
        }

        // Check for diagonal dominance
        for (int i = 0; i < n; i++) {
            float sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    sum += fabs(mat[i][j]);
                }
            }
            if (fabs(mat[i][i]) < sum) {
                validMatrix = 0;
                printf("\nThis is not a diagonally dominant matrix. Try again.\n");
                break;
            }
        }
    }

    printf("\nMatrix is:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%6.2f\t", mat[i][j]);
        }
        printf("\n");
    }

    float x0 = 0, y0 = 0, z0 = 0;
    float x1 = 0, y1 = 0, z1 = 0;
    float e, e1 = 1, e2 = 1, e3 = 1;
    
    printf("Enter the percentage error: ");
    scanf("%f", &e);

    int itr = 1;
    while (e1 > e || e2 > e || e3 > e) {
        printf("\nIteration %d:\n x = %f\n y = %f\n z = %f\n", itr++, x0, y0, z0);
        
        x1 = f1(mat, x0, y0, z0, n);
        y1 = f2(mat, x1, y0, z0, n);
        z1 = f3(mat, x1, y1, z0, n);
        
        e1 = fabs(x1 - x0);
        e2 = fabs(y1 - y0);
        e3 = fabs(z1 - z0);
        
        x0 = x1;
        y0 = y1;
        z0 = z1;
    }


    printf("\nFinal Roots:\n x = %f\n y = %f\n z = %f\n", x0, y0, z0);
    return 0;
}
