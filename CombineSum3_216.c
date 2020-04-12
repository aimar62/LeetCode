#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "CombineSum3_216.h"


void InitResult()
{
    g_result.num = 0;
    g_result.out = (int**)malloc(sizeof(int*)*MAX_RESULT_NUM);
}

void AddResult()
{
    int size = g_stack.num;
    int* tmp = (int*)malloc(sizeof(int)*size);
    if (g_result.num < (MAX_RESULT_NUM - 1)) {
        memcpy(tmp, g_stack.val, sizeof(int)*size);
        g_result.out[g_result.num] = tmp;
        g_result.num++;
    }
}

void InitStack1()
{
    g_stack.num = 0;
    g_stack.sum = 0;
}

void AddStack(int v){
    if (g_stack.num < (MAX_NUM - 1)) {
        g_stack.val[g_stack.num] = v;
        g_stack.sum += v;
        g_stack.num++;
    }
}

int DelStack()
{
    int v = 0;
    if (g_stack.num > 0) {
        v = g_stack.val[g_stack.num - 1];
        g_stack.val[g_stack.num - 1] = 0;
        g_stack.num --;
        g_stack.sum -= v;
    }
    return v;
}


int GetSum()
{
    return g_stack.sum;
}

void Dfs(int k, int n, int start, int currLen, int* visited, int left)
{
    int sum = GetSum();
    if ((currLen >= k) && (sum == n)) {
        AddResult();
        return;
    }
    int i;
    for (i = start; i <= 9; i++) {
        if (visited[i] != 1) {
            if (((currLen + 1) == k) && ((sum + i) != n)) {
               continue;
            }
            visited[i] = 1;
            AddStack(i);
            Dfs(k, n, i + 1, currLen + 1, visited, left - 1);
            visited[i] = 0;
            DelStack();
        }
    }
}



int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes)
{
    int visisted[10] = {0};
    int left = 9;
    InitStack1();
    InitResult();
    Dfs(k, n, 1, 0, visisted, left);
    *returnSize = g_result.num;
    int* colsize = (int*)malloc(sizeof(int)*g_result.num);
    for (int i = 0; i < g_result.num; i++) {
        colsize[i] = k;
    }
    *returnColumnSizes = colsize;
    return g_result.out;
}

#if 0
int main()
{
    int** out = NULL;
    int* complsize = NULL;
    int num = 0;
    out = combinationSum3(3, 22, &num, &complsize);
    int i;
    int j;

    for (i = 0; i < num; i++) {
        for (j = 0; j < complsize[i]; j++) {
            printf("%3d", out[i][j]);
        }
        printf("\n");
    }
    return 0;
}

#endif