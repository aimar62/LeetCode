#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "KillProcess_582.h"

typedef struct {
    int* pre;
    int* weight;
}Dsu;

Dsu g_dsu;

void InitDsu(int n)
{
    g_dsu.pre = (int*)malloc(sizeof(int)*n);
    g_dsu.weight = (int*)malloc(sizeof(int)*n);
    int i;

    for (i = 0; i < n; i++) {
        g_dsu.pre[i] = i;
        g_dsu.weight[i] = 1;
    }
}


int FindRoot(int p)
{
    while (p != g_dsu.pre[p]){
        p = g_dsu.pre[p];
    }
    return p;
}

void Union(int p, int q, int root)
{
    int root_p = FindRoot(p);
    int root_q = FindRoot(q);

    int weight_p = g_dsu.weight[root_p];
    int weight_q = g_dsu.weight[root_q];

    if (root_p == root_p) {
        return;
    }

    if (weight_p < weight_q) {
        g_dsu.pre[root_p] = root_q;
        g_dsu.weight[root_q] += weight_p;
    } else {
        g_dsu.pre[root_q] = root_p;
        g_dsu.weight[root_p] += weight_q;
    }
}

int* killProcess(int* pid, int pidSize, int* ppid, int ppidSize, int kill, int* returnSize)
{

}