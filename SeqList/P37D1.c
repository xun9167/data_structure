#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
void DeleteX(LinkList list,ElemType x);//递归算法删除所有值为x的节点
bool InitList(LinkList *list);//链表初始化(无头节点)
bool ListInsert(LinkList *list,int loc,ElemType e);//插入元素(无头节点)
void OutPrintf(LinkList list);//遍历输出链表的值
bool DeleteList(LinkList *list,int loc,ElemType *e);//删除指定位置的值
int main(){
    LinkList list;
    InitList(&list);
    ListInsert(&list,1,1);
    ListInsert(&list,2,1);
    ListInsert(&list,3,1);
    ListInsert(&list,4,5);
    ListInsert(&list,5,10);
    ListInsert(&list,6,7);
    ListInsert(&list,7,6);
    ListInsert(&list,8,4);
    ListInsert(&list,9,3);
    ListInsert(&list,10,2);
    OutPrintf(list);
    int i=0;
    printf("输入删除的值\n");
    scanf("%d",&i);
    printf("删除后链表的值为");
    DeleteX(list,i);
    //printf("i=%d\n",i);
    OutPrintf(list);
}
bool InitList(LinkList *list){
    *list=NULL;
    return true;
}
bool ListInsert(LinkList *list,int loc,ElemType e){
    if(loc<1)
    return false;
    if(loc==1){
        LNode *node=(LNode *)malloc(sizeof(LNode));
        node->data=e;
        node->next=*list;
        *list=node;
        return true;
    }
    LNode *node;
    int j=1;
    node=*list;
    while (node!=NULL&&j<loc-1)
    {
        node=node->next;
        j++;
    }
    if(node==NULL){
      return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=node->next;
    node->next=s;
    return true;
}
void OutPrintf(LinkList list){
    LNode *p;
    p=list;
    while (p!=NULL)
    {
        printf("%d   ",p->data);
        p=p->next;
    }  
    printf("\n");
}
 bool DeleteList(LinkList *list,int loc,ElemType *e){
     if(loc<1) return false;
     if(loc==1){
         printf("1\n");
         LNode *p,*q;
         p=*list;
         *e=p->data;
         q=p->next;
         free(p);
         *list=q;
         return true;
     }
     else{
         LNode *node=*list;
         int j=1;
         while(node!=NULL&&j<loc-1){
         node=node->next;
         j++;
         }
         if(node==NULL) return false;
         if(node->next==NULL) return false;
         LNode *q=node->next;
         *e=q->data;
         node->next=q->next;
         free(q);
         return true;
     }  
 }
 void DeleteX(LinkList list,ElemType x){
     LNode *p;
     if(list==NULL){
         return ;
     }
     if(list->data==x){
         p=list;
         list=list->next;
         free(p);
         DeleteX(list,x);
     }
     else{
         DeleteX(list->next,x);
     }
}
 