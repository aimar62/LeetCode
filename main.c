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





int BinarySearchLeft(int* in, int size, int target) 
{
    int left = 0;
    int right = size;
    int mid;
    int pos;
    while (left < right) {
        mid = (left + right) / 2;
        if (in[mid] == target) {
            right = mid;
        } else if (in[mid] > target){
            right = mid;
        } else if(in[mid] < target) {
            left = mid + 1;
        }
    }
    if (left == size) {
        return -1;
    }
    pos = (in[left] == target) ? left : -1;
    return pos;
}


int BinarySearchRight(int* in, int size, int target) 
{
    int left = 0;
    int right = size;
    int mid;
    int pos;
    while (left < right) {
        
        mid = (left + right) / 2;
        if (in[mid] == target) {
            left = mid + 1;
        } else if (in[mid] > target){
            right = mid;
        } else if(in[mid] < target) {
            left = mid + 1;
        }
    }
    if (left > size) {
        return -1;
    }
    if (left == 0) {
        pos = (in[left] == target) ? (left) : (-1);
        return pos;
    }
    pos = (in[left - 1] == target) ? (left - 1) : (-1);
    return pos;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int* out = (int*)malloc(sizeof(int)*2);
    if ((nums == NULL) || (numsSize == 0)) {
        out[0] = -1;
        out[1] = -1;
        *returnSize = 2;
        return out;
    }
    int left = BinarySearchLeft(nums, numsSize, target);
    int right = BinarySearchRight(nums, numsSize, target);
    
    out[0] = left;
    out[1] = right;
    *returnSize = 2;
    return out;
}

int main()
{
    int a[] = {5,7,7,8,8,10};
    int len = sizeof(a)/sizeof(a[0]);
    int k = 0;
    int ret;
    int* minLen = searchRange(a, len, k, &ret);
    return 0;
}
