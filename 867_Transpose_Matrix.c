// LeetCode 867 - Transpose Matrix
#include <stdlib.h>

int** transpose(int** matrix, int matrixSize, int* matrixColSize,
                int* returnSize, int** returnColumnSizes) {
    int rows = matrixSize;
    int cols = matrixColSize[0];

    int** result = (int**)malloc(cols * sizeof(int*));
    *returnColumnSizes = (int*)malloc(cols * sizeof(int));

    if (result == NULL || *returnColumnSizes == NULL) {
        free(result);
        free(*returnColumnSizes);
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    for (int i = 0; i < cols; i++) {
        result[i] = (int*)malloc(rows * sizeof(int));
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
        (*returnColumnSizes)[i] = rows;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    *returnSize = cols;
    return result;
}
