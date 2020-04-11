

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef struct {
    int num;
    int value;
}Result;

typedef struct AvlTreeNode{
    int x;
    int height;
    int cnt;
    struct AvlTreeNode* right;
    struct AvlTreeNode* left;
}AvlTreeNode;

extern AvlTreeNode* AvlTreeInsert(int data, AvlTreeNode* root);
extern int* topKFrequent(int* nums, int numsSize, int k, int* returnSize);
#endif