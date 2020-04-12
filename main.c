#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "binarySearch.h"
#include "atoi.h"
#include "binarySearch.h"
#include "stringEncode.h"
#include "AvlTree.h"
#include "stockSpan_901.h"
#include "CombineSum3_216.h"



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
