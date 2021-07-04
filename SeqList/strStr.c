#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ElemType int
int i;
int j;
int strStr(char* haystack, char* needle);//模拟的str算法 非暴力法 (思路；利用的经典的KMP算法实现)
int main(){
    char a[100];
    char b[100];
    printf("输入字符串1：\n");
    scanf("%s",&a);
    printf("输入字符串2：\n");
    scanf("%s",&b);
    printf("pos=");
    int pos=strStr(a,b);
    printf("%d\n",pos);
    return 0;
}
int strStr(char* haystack, char* needle) {
    int n = strlen(haystack), m = strlen(needle);
    if (m == 0) {
        return 0;
    }
    int pi[m];
    pi[0] = 0;
    for (i = 1, j = 0; i < m; i++) {
        while (j > 0 && needle[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (needle[i] == needle[j]) {
            j++;
        }
        pi[i] = j;
    }
    for ( i = 0, j = 0; i < n; i++) {
        while (j > 0 && haystack[i] != needle[j]) {
            j = pi[j - 1];
        }
        if (haystack[i] == needle[j]) {
            j++;
        }
        if (j == m) {
            return i - m + 1;
        }
    }
    return -1;
}