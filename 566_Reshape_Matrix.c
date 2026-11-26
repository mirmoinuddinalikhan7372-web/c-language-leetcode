// LeetCode 566 - Reshape the Matrix
#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize,
                    int r, int c, int* returnSize,
                    int** returnColumnSizes) {
    int rows = matSize;
    int cols = matColSize[0];

    // If the number of elements does not match, return the original matrix.
    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** result = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));

    if (result == NULL || *returnColumnSizes == NULL) {
        free(result);
        free(*returnColumnSizes);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        if (result[i] == NULL) {
            for (int k = 0; k < i; k++) {
                free(result[k]);
            }
            free(result);
            free(*returnColumnSizes);
            *returnSize = 0;
            *returnColumnSizes = NULL;
            return NULL;
        }
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    *returnSize = r;
    return result;
}
