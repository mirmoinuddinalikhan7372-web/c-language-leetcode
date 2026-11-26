// LeetCode 1480 - Running Sum of 1d Array
#include <stdlib.h>

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(numsSize * sizeof(int));
    if (result == NULL && numsSize > 0) {
        *returnSize = 0;
        return NULL;
    }

    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        result[i] = sum;
    }

    *returnSize = numsSize;
    return result;
}
