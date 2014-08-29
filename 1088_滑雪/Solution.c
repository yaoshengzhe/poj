#include <stdio.h>

#define MAX_LEN 101

int max(int a, int b) {
    return a > b ? a : b;
}

int search(int path[][MAX_LEN], int mat[][MAX_LEN], int i, int j, int row, int col) {
    if (path[i][j] == 0) {
        if (j > 0 && mat[i][j] < mat[i][j-1]) { // left
            path[i][j] = max(path[i][j], search(path, mat, i, j-1, row, col));
        }
        if (j < col - 1 && mat[i][j] < mat[i][j+1]) { // right
            path[i][j] = max(path[i][j], search(path, mat, i, j+1, row, col));
        }
        if (i > 0 && mat[i][j] < mat[i-1][j]) { // up
            path[i][j] = max(path[i][j], search(path, mat, i-1, j, row, col));
        }
        if (i < row-1 && mat[i][j] < mat[i+1][j]) { // down
            path[i][j] = max(path[i][j], search(path, mat, i+1, j, row, col));
        }
        path[i][j]++;
    }
    return path[i][j];
}

int main() {
    int mat[MAX_LEN][MAX_LEN] = {0};
    int path[MAX_LEN][MAX_LEN] = {0};
    int row, col;
    scanf("%d %d", &row, &col);

    for (int i=0; i < row; ++i) {
        for (int j=0; j < col; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    int sum = 0;
    for (int i=0; i < row; ++i) {
        for (int j=0; j < col; ++j) {
            sum = max(sum, search(path, mat, i, j, row, col));
        }
    }
    printf("%d\n", sum);

    return 0;
}
