#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "math.h"
#include "atoi.h"




int IsDigital(char c)
{
    return c >= '0' && c <= '9'; 
}

int GetNum(char c)
{
    return c - '0';
}

int FindFirstDigtalPos(int start, char* in)
{
    int i;
    for (i = start; i < strlen(in); i++) {
        if (IsDigital(in[i])) {
            return i;
        }
    }

    return -1;
}

int FindFirstDigtalNonZeroPos(int start, char* in)
{
    int i;
    for (i = start; i < strlen(in); i++) {
        if (!IsDigital(in[i])) {
            return -1;
        }
        if (IsDigital(in[i]) && (in[i] != '0')) {
            return i;
        }
    }

    return -1;
}

int FindDigitalCnt(int start, char* in)
{
    int i;
    int cnt = 0;
    for (i = start; i < strlen(in); i++) {
        if (IsDigital(in[i])) {
            cnt++;
        } else {
            break;
        }
    }

    return cnt;
}

int FindNoSpacePos(int start, char* in)
{
    int space = 0x20;
    int i;
    for (i = start; i < strlen(in); i++) {
        if (space != in[i]) {
            return i;
        }
    }
    return -1;
}

int FindSpacePos(int start, char* in)
{
    int space = 0x20;
    int i;
    for (i = 0; i < strlen(in); i++) {
        if (space == in[i]) {
            return i;
        }
    }
    return -1;
}

int myAtoi(char * str)
{
    int i;
    int len;
    int firstDigitalPos;
    int firstNoSpacePos;
    int signFlag = 1;
    long long sum = 0;
    int digitalCnt;
    int digital;
    int num = 0;
    if (str == NULL) {
        return 0;
    }

    len = strlen(str);

    if (len == 0) {
        return 0;
    }

    firstNoSpacePos = FindNoSpacePos(0, str);
    if (firstNoSpacePos == -1) {
        return 0;
    }

    if (!IsDigital(str[firstNoSpacePos]) && (str[firstNoSpacePos] != '-') && (str[firstNoSpacePos] != '+')) {
        return 0;
    }

    firstDigitalPos = FindFirstDigtalPos(0, str);
    if (firstDigitalPos == -1) {
        return 0;
    }

    if ((firstDigitalPos - firstNoSpacePos) >= 2) {
        return 0;
    }

    if ((firstDigitalPos != firstNoSpacePos) && (str[firstNoSpacePos] == '-')) {
        signFlag = -1;
    }

    int fisrtNonZeroDigitalPos = FindFirstDigtalNonZeroPos(firstDigitalPos, str);
    if (fisrtNonZeroDigitalPos == -1) {
        return 0;
    }
    digitalCnt = FindDigitalCnt(fisrtNonZeroDigitalPos, str);
    if (digitalCnt == 0) {
        return 0;
    }

    if ((digitalCnt > 10) && (signFlag == 1)) {
        return INT_MAX;
    }

    if ((digitalCnt > 10) && (signFlag == -1)) {
        return INT_MIN;
    }

    long long maxUpper = INT_MAX;
    for (i = 0; i < digitalCnt; i++) {
        digital = GetNum(str[fisrtNonZeroDigitalPos + i]);
        sum += digital * pow(10, digitalCnt - 1 - i);

        if ((signFlag == 1) && (sum >= INT_MAX)) {
            return INT_MAX;
        }

        if ((signFlag == -1) && (sum > (maxUpper + 1))) {
            return INT_MIN;
        }
    }

    return signFlag * sum;
}

