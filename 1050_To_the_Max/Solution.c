#include <stdio.h>

#define MAX_LEN 200

int max(int a, int b) {
    return a > b ? a : b;
}

int compute(int mat[][MAX_LEN], int n) {
    int result = 0;
    for (int i=1; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            mat[i+1][j] += mat[i][j];
        }
    }

    for (int i=1; i < n+1; ++i) {
        for (int j=i; j < n+1; ++j) {
            // compute [i, j]
            int sum = 0;
            int max_sum = 0;
            for (int k=0; k < n; ++k) {
                int val = mat[j][k] - mat[i-1][k];
                sum = max(0, sum + val);
                max_sum = max(max_sum, sum);
            }
            result = max(result, max_sum);
        }
    }
    return result;
}

int main() {
    int n;
    scanf("%d", &n);
    int matrix[MAX_LEN][MAX_LEN] = {0};
    // note: matrix[0][...] are 0, the first row starts with index 1
    for (int i=0; i < n; ++i) {
        for (int j=0; j < n; ++j) {
            scanf("%d", &matrix[i+1][j]);
        }
    }
    printf("%d\n", compute(matrix, n));
}
