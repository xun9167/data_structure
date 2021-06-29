#include <stdio.h>
#include <stdbool.h>
#define ElemType int
void QuickSort(ElemType a[],int low,int hight);//快速排序
void swap(ElemType *a,ElemType *b);//交换两个变量的值
int Partition(ElemType a[],int low,int hight);//划分操作
int main(){
    int n;
    printf("input n");
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    QuickSort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
}
void QuickSort(ElemType a[],int low,int hight){
    if(low<hight){
         int pov=Partition(a,low,hight);
         QuickSort(a,low,pov-1);
         QuickSort(a,low+1,hight);
    }
}
int Partition(ElemType a[],int low,int hight){
    ElemType pivot=a[low];
    while(low<hight){
        while (low<hight&&a[hight]>=pivot)
            --hight;
        a[low]=a[hight];
        while (low<hight&&a[low]<=pivot)
            low++;   
        a[hight]=a[low]; 
    }
    a[low]=pivot;
    return low;
}