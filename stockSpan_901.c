#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stockSpan_901.h"

StackCtrl* g_StackCtrl;



int IsMoneStackEmpty()
{
    return g_StackCtrl->num == 0;
}

int IsMoneStackNotEmpty()
{
    return g_StackCtrl->num != 0;
}

int GetMoneStackTop()
{
    int num = g_StackCtrl->num;
    int ret = 0;
    if (num > 0) {
        ret = g_StackCtrl->Stack[num - 1].price;
    }
    return ret;
}

int GetMoneStackTopPos()
{
    int num = g_StackCtrl->num;
    int ret = 0;
    if (num > 0) {
        ret = g_StackCtrl->Stack[num - 1].posOri;
    }
    return ret;
}

void MoneStackPop()
{
    int num = g_StackCtrl->num;
    if (num >= 1) {
        g_StackCtrl->Stack[num - 1].price = 0;
        g_StackCtrl->Stack[num - 1].posInStack = 0;
        g_StackCtrl->Stack[num - 1].posOri = 0;
        g_StackCtrl->num--;
    }
}

void MoneStackAdd(StackNode* node)
{
    int num = g_StackCtrl->num;
    if (num < (MAX_NUM - 1)) {
        g_StackCtrl->Stack[num ].price = node->price;
        g_StackCtrl->Stack[num].posInStack = num;
        g_StackCtrl->Stack[num].posOri = node->posOri;
        node->posInStack = num;
        g_StackCtrl->num++;
    }
}

int MoneStackPush(StackNode* node)
{
    while (IsMoneStackNotEmpty() && (node->price > GetMoneStackTop())) {
        MoneStackPop();
    }
    int preOPos;
    if (IsMoneStackEmpty()) {
        preOPos = -1;
    } else {
        preOPos = GetMoneStackTopPos();
    }
    MoneStackAdd(node);
    return node->posOri - preOPos;
    
}

void addPrice2Obj(StockSpanner* obj, int price, int* posOrigin)
{
    int num = obj->num;
    if (num < (MAX_NUM - 1)) {
        obj->price[num] = price;
        *posOrigin = num;
        obj->num++;
    }
}


StockSpanner* stockSpannerCreate() 
{
    StockSpanner* obj = (StockSpanner*)malloc(sizeof(StockSpanner));
    obj->num = 0;
    g_StackCtrl = (StackCtrl*)malloc(sizeof(StackCtrl));
    g_StackCtrl->num = 0;
    return obj;
}

int stockSpannerNext(StockSpanner* obj, int price) 
{
    int posOrin = 0;
    int distance;
    addPrice2Obj(obj, price, &posOrin);

    StackNode stackNode = {0};
    stackNode.price = price;
    stackNode.posOri = posOrin;
    distance = MoneStackPush(&stackNode);
    return distance;

}

void stockSpannerFree(StockSpanner* obj) 
{
    free(obj);
    free(g_StackCtrl);
}

#if 0
int main()
{
    int ret[] = {0,0,0,0,0,0,0};
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int len = sizeof(price)/sizeof(price[0]);
    StockSpanner* obj = stockSpannerCreate();
    for (int i = 0; i < len; i++) {
        ret[i] = stockSpannerNext(obj, price[i]);
    }
    return 0;
}
#endif
