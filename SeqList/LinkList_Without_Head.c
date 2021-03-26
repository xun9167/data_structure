#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList *list);//链表初始化(无头节点)
bool ListInsert(LinkList *list,int loc,ElemType e);//插入元素(无头节点)
void OutPrintf(LinkList *list);//遍历输出链表的值
int main(){
    LinkList list;
    InitList(&list);
    ListInsert(&list,1,1);
    ListInsert(&list,0,1);
    ListInsert(&list,2,20);
    ListInsert(&list,3,30);
    ListInsert(&list,5,1);
    ListInsert(&list,4,1);
    OutPrintf(&list);
    return 0;
}
bool InitList(LinkList *list){
    list=NULL;
    return true;
}
bool ListInsert(LinkList *list,int loc,ElemType e){
    if(loc<1)
    return false;
    if(loc==1){
        LNode *node=(LNode *)malloc(sizeof(LNode));
        node->data=e;
        node->next=list;
        list=node;
        return true;
    }
    LNode *node;
    int j=1;
    node=list;
    while (node!=NULL&&j<loc-1)
    {
        node=node->next;
        j++;
    }
    if(node==NULL)return false;
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=node->next;
    node->next=s;
    return true;
}
void OutPrintf(LinkList *list){
    LNode *p;
    while (p!=NULL)
    {
        printf("%d   ",p->data);
        p=p->next;
    }
    printf("\n");
    
}
