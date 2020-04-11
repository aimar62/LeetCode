#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "AvlTree.h"


int CalHeight(AvlTreeNode* x)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (x == NULL) {
        return 0;
    }
    leftHeight = CalHeight(x->left);
    rightHeight = CalHeight(x->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}



/* 左左，需要向右旋转 */
AvlTreeNode* AvlTreeSingleLLRotateR(AvlTreeNode* x)
{
    AvlTreeNode* w = x->left;
    AvlTreeNode* b = w->right;
    x->left = b;
    w->right = x;
    x->height = CalHeight(x);
    w->height = CalHeight(w);
    return w;

}

/* 右右，需要向左旋转 */
AvlTreeNode* AvlTreeSingleRRRotateL(AvlTreeNode* w)
{
    AvlTreeNode* x = w->right;
    AvlTreeNode* b = x->left;
    x->left = w;
    w->right = b;

    x->height = CalHeight(x);
    w->height = CalHeight(w);
    return x;
}



/* 左右，需要两步，先 */
AvlTreeNode* AvlTreeDoubleLRRotateLR(AvlTreeNode* x)
{
    AvlTreeNode* w = x->left;
    AvlTreeNode* y = w->right;
    AvlTreeNode* yNew; 
    x->left = AvlTreeSingleRRRotateL(w);
    yNew = AvlTreeSingleLLRotateR(x);
    return yNew;
}


/* 右左，需要两步，先 */
AvlTreeNode* AvlTreeDoubleRLRotateRL(AvlTreeNode* x)
{
    AvlTreeNode* w = x->right;
    AvlTreeNode* y = w->left;
    AvlTreeNode* yNew; 
    x->right = AvlTreeSingleLLRotateR(w);
    yNew = AvlTreeSingleRRRotateL(x);
    return yNew;
}

AvlTreeNode* g_root = NULL;

AvlTreeNode* AvlTreeInsert(int data, AvlTreeNode* root)
{
    int leftHeight = 0;
    int rightHeight = 0;
    if (root == NULL) {
        root = (AvlTreeNode*)malloc(sizeof(AvlTreeNode));
        root->x = data;
        root->cnt = 1;
        root->left = NULL;
        root->right = NULL;
    } else if (data < root->x) {
        root->left = AvlTreeInsert(data, root->left);
        leftHeight = CalHeight(root->left);
        rightHeight = CalHeight(root->right);
        if ((leftHeight - rightHeight) >= 2){
            if (data < root->left->x) {
                root = AvlTreeSingleLLRotateR(root);
            } else {
                root = AvlTreeDoubleLRRotateLR(root);
            }
        }
    } else if (data > root->x){
        root->right = AvlTreeInsert(data, root->right);
        leftHeight = CalHeight(root->left);
        rightHeight = CalHeight(root->right);
        if ((rightHeight - leftHeight) >= 2){
            if (data > root->right->x) {
                root = AvlTreeSingleRRRotateL(root);
            } else {
                root = AvlTreeDoubleRLRotateRL(root);
            }
        }
    } else {
        root->cnt++;
    }
    root->height = CalHeight(root);
    return root;
}


void InitTree()
{
    g_root = NULL;
}

void PreOrder(AvlTreeNode* root, int* cnt, Result* result)
{
    int num = *cnt;
    if (root) {
        result[num].num = root->cnt;
        result[num].value = root->x;
        //printf("cnt = %d, value = %d", result[num].num, result[num].value);
        //printf("\n");
        num++;
        *cnt = num;
        PreOrder(root->left, cnt, result);
        PreOrder(root->right, cnt, result);
    }
}

int Cmp(const void* a, const void* b)
{
    Result* resulta = (Result*)a;
    Result* resultb = (Result*)b;

    return resultb->num - resulta->num;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int i;
    int cnt = 0;
    AvlTreeNode* node;
    InitTree();
    int* out = (int*)malloc(sizeof(int)*numsSize);
    memset(out, 0, sizeof(int)*numsSize);
    for (i = 0; i < numsSize; i++) {
        g_root = AvlTreeInsert(nums[i], g_root);
    }
    Result* result = malloc(sizeof(Result)*numsSize);
    memset(result, 0, sizeof(Result)*numsSize);
    PreOrder(g_root, &cnt, result);
    qsort(result, cnt, sizeof(Result),Cmp);
    for (i = 0; i < k; i++) {
        out[i] = result[i].value;
    }
    *returnSize = k;
    return out;
}

#if 0

int main()
{
    int in[] = {1,1,1,2,2,3};
    int len = sizeof(in)/sizeof(in[0]);
    int k = 2;
    int retursize;
    int* a;
    a = topKFrequent(in, len, k, &retursize);
    return 0;
}
#endif