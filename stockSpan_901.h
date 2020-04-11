#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#ifndef _STOCK_SPAN_H_
#define _STOCK_SPAN_H_


#define MAX_NUM 100010

typedef struct {
    int num;
    int price[MAX_NUM];
} StockSpanner;

typedef struct {
    int posOri;
    int posInStack;
    int price;
}StackNode;

typedef struct {
    int num;
    StackNode Stack[MAX_NUM];
}StackCtrl;

extern StockSpanner* stockSpannerCreate();
extern int stockSpannerNext(StockSpanner* obj, int price);
extern void stockSpannerFree(StockSpanner* obj);


#endif