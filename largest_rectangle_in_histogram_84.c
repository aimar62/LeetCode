#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "largest_rectangle_in_histogram_84.h"


Stack g_stack;

void InitStack()
{
    g_stack.num = 0;
}

void StackAdd(Item *item)
{
    if (g_stack.num < (MAX_STACK_SIZE - 1)) {
        g_stack.val[g_stack.num].height = item->height;
        g_stack.val[g_stack.num].pos = item->pos;
        g_stack.num ++;
    }
}

int StackDel(Item *item)
{
    if (g_stack.num >= 1) {
        g_stack.num--;
        item->pos = g_stack.val[g_stack.num].pos;
        item->height = g_stack.val[g_stack.num].height;
        return 0;
    }
    return -1;
}

int GetStackTopHeight()
{
    if (g_stack.num <= 0) {
        return -1;
    }
    return g_stack.val[g_stack.num - 1].height;
}

int GetStackTopPos()
{
    if (g_stack.num <= 0) {
        return -1;
    }
    return g_stack.val[g_stack.num - 1].pos;
}


int CalcArea(int h, int d)
{
    return h * d;
}


int IsStackNotEmpty()
{
    return g_stack.num != 0;
}

int IsStackEmpty()
{
    return g_stack.num == 0;
}
int largestRectangleArea(int* heights, int heightsSize)
{
    int i;
    Item itemDel;
    Item itemIn;
    int currArea;
    int maxArea = 0;
    int len;
    int prePos;
    itemIn.height = 0;
    itemIn.pos = -1;
    InitStack();
    StackAdd(&itemIn);
    for (i = 0; i < heightsSize; i++) {
        while ((GetStackTopPos() != -1) && (heights[GetStackTopPos()] >= heights[i])) {
            StackDel(&itemDel);
            len = i - GetStackTopPos() - 1;
            currArea = itemDel.height * len;
            maxArea = maxArea < currArea ? currArea : maxArea;
        }
        itemIn.height = heights[i];
        itemIn.pos = i;
        StackAdd(&itemIn);
    }
    int lastNodePos = heightsSize;
    while (GetStackTopPos() != -1) {
        StackDel(&itemDel);
        prePos = GetStackTopPos();
        currArea = itemDel.height * (lastNodePos - prePos - 1);
        maxArea = maxArea < currArea ? currArea : maxArea;
    }

    return maxArea;
}

