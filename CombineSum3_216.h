#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#ifndef _COMBINE_SUM_III_H_
#define _COMBINE_SUM_III_H_



#define MAX_NUM 10
#define MAX_RESULT_NUM 1000
typedef struct Stack
{
    int num;
    int sum;
    int val[MAX_NUM];
}Stack;

typedef struct Result
{
    int num;
    int** out;
}Result;

Result g_result;
Stack g_stack;

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes);
#endif