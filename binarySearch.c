#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "binarySearch.h"

/*
二分查找练习
1: 查找左边界
2: 查找右边界
*/

/*
查找左边界的思想是，查找区间为[left,right)
故起始位置为0，len
在每一轮查找的过程中，右边界都是保持开区间
目标找到后，不返回，因为不知道是左界还是右界
区间要向左缩小，逼近左区间的时候，为了保持右区间
的开放性，故 right = mid。而不是right = mid - 1.这样就是
*/



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

#if 0

int main()
{
    int left = 0;
    int right = 0;
    int a[] = {1,2,2,4,6,6,6,6,6,7,9,10,11,14,17};
    int len = sizeof(a)/sizeof(a[0]);
    int target = 18;
    left = findLeftSpace(a, len, target);
    right = findRightSpace(a, len, target);

    return 0;
}
#endif