#include <stdio.h>
#include <stdbool.h>
#define ElemType int
void InsertSort(ElemType a[],int n);//插入排序
void swap(ElemType *a,ElemType *b);//交换两个变量的值
int main(){
    int n;
    printf("input n");
    scanf("%d",&n);
    int a[n+1];
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    InsertSort(a,n);
    for(i=0;i<=n;i++)
        printf("%d  ",a[i]);
}
void InsertSort(ElemType a[],int n){
    int i,j;
    for(i=2;i<=n;i++){
        if(a[i]<a[i-1]){
            a[0]=a[i];           //复制为哨兵
        for(j=i-1;a[0]<a[j];--j)
            a[j+1]=a[j];
        a[j+1]=a[0];
        }
    }
}
void swap(ElemType *a,ElemType *b){
    ElemType temt;
    temt=*a;
    *a=*b;
    *b=temt;
}