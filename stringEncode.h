#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

#ifndef _STRING_ENDCODING_TREE_H_
#define _STRING_ENDCODING_TREE_H_

#define MAX_CHAR_NUM 26
typedef struct TrieNode{
    char c;
    int nextNodeNum;
    int currNodeDepth;
    int strExist;
    int isLeafNode;
    struct TrieNode*next[MAX_CHAR_NUM];
}TrieNode;

extern int minimumLengthEncoding(char ** words, int wordsSize);
#endif