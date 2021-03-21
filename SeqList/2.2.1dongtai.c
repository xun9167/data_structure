#include<stdio.h>
#include <stdbool.h>
#define InitSize 5  //初始大小
#define ElemType int
typedef struct sqllist{
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;

bool InitList(SeqList *list);
bool ListInsert(SeqList *list,int i,ElemType e);
bool Increase(SeqList *list,int len);
bool DeleteList(SeqList *List,int i,ElemType *e);//按下标位置删除元素
int main(){
    SeqList list;
    InitList(&list);
    int i;
    for(i=1;i<10;i++)
     ListInsert(&list,i,i);
    for(i=0;i<list.length;i++){
        printf("%d\n",list.data[i]);
    }
    int e;
    DeleteList(&list,1,&e);
    printf("删除的元素是%d\n",e);
    DeleteList(&list,2,&e);
    printf("删除的元素是%d\n",e);
     for(i=0;i<list.length;i++){
        printf("%d\n",list.data[i]);
    }
    return 0;
}
bool InitList(SeqList *list){
    list->data=(ElemType *)malloc(InitSize *sizeof(ElemType));
    list->length=0;
    list->MaxSize=InitSize;
}
bool ListInsert(SeqList *list,int i,ElemType e){
    if(i<1||i>list->length+1)
        return false;
    if(i>list->MaxSize)
        return false;
        int j;
    for(j=list->length;j>=i;j--){
        list->data[j]=list->data[j-1];
    }
    list->data[i-1]=e;
    list->length++;
    return true;
}
bool Increase(SeqList *list,int len){
    ElemType *p=list->data;
    list->data=(ElemType *)malloc((list->MaxSize+len)*sizeof(ElemType));
    int i;
    for(i=0;i<list->length;i++){
        list->data[i]=p[i];
    }
    list->MaxSize=list->MaxSize+len;
    free(p);
    return true;
}
bool DeleteList(SeqList *list,int i,ElemType *e){
    if(i>list->length||i<1)
        return false;
    *e=list->data[i-1];
    int j;
    for(j=i;j<list->length;j++){
        list->data[j-1]=list->data[j];
    }
    list->length--;
    return true;
}
