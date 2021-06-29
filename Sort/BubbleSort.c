#include <stdio.h>
#include <stdbool.h>
#define ElemType int
void BubbleSort(ElemType a[],int n);//冒泡排序
void swap(ElemType *a,ElemType *b);//交换两个变量的值
int main(){
    int n;
    printf("input n");
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    BubbleSort(a,n);
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}
void BubbleSort(ElemType a[],int n){
    int i,j;
    for(i=0;i<n;i++){
        bool flag=false;
        for(j=n-1;j>i;j--){
            if(a[j-1]>a[j]){
                swap(&a[j-1],&a[j]);
                flag=true;   
            }
        }
        if(flag==false)
            return ;
    }
}
void swap(ElemType *a,ElemType *b){
    ElemType temt;
    temt=*a;
    *a=*b;
    *b=temt;
}