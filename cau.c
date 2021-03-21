#include "stdio.h"
int main(){
    char ac[]={0,1,2,3,4,5,6,7,8,9};
    char *p=ac;
    char *p1=&ac[5];
    int i;
    for(i=0;i<sizeof(ac)/sizeof(ac[0]);i++){
        printf("a[%d]=%d\n",i,ac[i]);
    }
    printf("p1-p=%d\n",p1-p);
    printf("p=%p\n",p);
    printf("p+1=%p\n",p+1);
    printf("p+1=% d\n",*(p+1));
    return 0;
}