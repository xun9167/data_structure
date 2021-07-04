#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
int lengthOfLongestSubstring(char * s);//解法：哈希加滑动窗口  (无重复最长字符串，返回值为整形)
int main(){
    char a[100];
    scanf("%s",&a);
    printf("%d",lengthOfLongestSubstring(a));
    return 0;
}

int lengthOfLongestSubstring(char * s)
{
    int hash[128] = {0};
    int right = 0,left = 0,max=0;
    while(right < strlen(s))
    {
        if(hash[s[right]] > 0 )
        {
            hash[s[left]] = 0;
            left++;
        }
        else
        {
            hash[s[right]] = 1;
            right++;
            max = (right - left) > max ? right-left:max;
        }
    }
    return max;
}