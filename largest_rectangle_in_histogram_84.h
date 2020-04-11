#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#ifndef _LARGEST_RECTANGLE_IN_HISTOGRAM_H_
#define _LARGEST_RECTANGLE_IN_HISTOGRAM_H_

#define MAX_STACK_SIZE 30000
typedef struct {
    int height;
    int pos;
}Item;

typedef struct {
    int num;
    Item val[MAX_STACK_SIZE];
}Stack;

extern int largestRectangleArea(int* heights, int heightsSize);

#endif