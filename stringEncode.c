#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stringEncode.h"


TrieNode g_root;

void InitTrieTree()
{
    memset(&g_root, 0, sizeof(g_root));
}

void CreateNode(char* in, int start, TrieNode* root)
{
    if (start < 0) {
        return;
    }

    int num = root->nextNodeNum;
    int i;

    for (i = 0; i < num; i++) {
        if (root->next[i]->c == in[start]) {
            break;
        }
    }

    if (i == num) {
        TrieNode* p = malloc(sizeof(TrieNode));
        memset(p, 0, sizeof(TrieNode));
        p->c = in[start];
        p->isLeafNode = 1;
        root->isLeafNode = 0;
        root->next[num] = p;
        root->nextNodeNum ++;
        p->currNodeDepth = root->currNodeDepth + 1;
        if (start == 0) {
            root->next[num]->strExist = 1;
        }
        CreateNode(in, start - 1, root->next[num]);
    } else {
        if (start == 0) {
            root->next[i]->strExist = 1;
        }
        CreateNode(in, start - 1, root->next[i]);
    }
}

void CalcAllNodeNum(TrieNode* root, int* num)
{
    int i;
    int nodeNum = root->nextNodeNum;
    for (i = 0; i < nodeNum; i++) {
        if (root->next[i]->isLeafNode == 1) {
            *num = *num + (root->next[i]->currNodeDepth + 1);
        }
        CalcAllNodeNum(root->next[i], num);
    }
}

int CalcResult()
{
    int num = 0;
    CalcAllNodeNum(&g_root, &num);
    return num;
}

int minimumLengthEncoding(char ** words, int wordsSize)
{
    int i;
    int num;
    InitTrieTree();
    for (i = 0; i < wordsSize; i++) {
        if (strlen(words[i]) < 1) {
            continue;
        }
        CreateNode(words[i], strlen(words[i]) - 1, &g_root);
    }
    
    num = CalcResult();
    return num;
}  