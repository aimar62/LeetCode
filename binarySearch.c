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
int findLeftSpace(int* in, int len, int target)
{
    int left = 0;
    int right = len;
    int mid;
    if (len <= 1) {
        return 0;
    }
    while (left < right) {
        mid = (left + right) / 2;
        if (in[mid] == target) {
            right = mid; //右的开放性，找到第一个目标，则需要将左移动
        } else if (in[mid] < target) {
            left = mid + 1;
        } else if (in[mid] > target) {
            right = mid; //比目标大，
        }
    }
    return left;
}

int findRightSpace(int* in, int len, int target)
{
    int left = 0;
    int right = len - 1;
    int mid;
    if (len <= 1) {
        return 0;
    } 

    while (left < right) {
        mid = (left + right) / 2;
        if (in[mid] == target) {
            left = mid + 1;
        } else if (in[mid] < target) {
            left = mid +1;
        } else if (in[mid] > target) {
            right = mid;
        }
    }
    return right - 1;
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