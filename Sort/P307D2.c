#include <stdio.h>
#include <stdbool.h>
#define ElemType int
void DoubleBubbleSort2(int a[],int n);//书上的方法，较为简便
void BubbleSort(ElemType a[],int n);//冒泡排序
void DoubleBubbleSort(int a[],int n);//双向冒泡排序，第一趟把关键字最大的放最后，第二趟把关键字最小的放最前
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
    DoubleBubbleSort(a,n);
    for(i=0;i<n;i++)
        printf("%d  ",a[i]);
    return 0;
}
void DoubleBubbleSort(int a[],int n){
    int low,hight,i,j,k;
    low=0;
    hight=n-1;
    bool flag=true;
    while(low<hight&&flag==true){
        for(i=low;i<=hight-1;i++){
            flag=false;
            for(j=hight;j>i;j--){
                if(a[j-1]>a[j]){
                    swap(&a[j-1],&a[j]);
                    flag=true;
                }

            }
        }
        hight--;
        for(i=hight;i>low;i--){
            flag=false;
            for(j=low;j<i;j++){
                if(a[j+1]<a[j]){
                    swap(&a[j+1],&a[j]);
                    flag=true;
                }
            }
        }
        low++;
    }
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
void DoubleBubbleSort2(int a[],int n){
    
}