#include "stdio.h"
#include "stdlib.h"
int main(){
   int n,i;
    int *a;
    printf("number\n");
    scanf("%d",&n);
    a=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("number\n");
        scanf("%d",&a[i]);
    }
     for(i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
    return 0;
}