#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;
bool InitList(LinkList *list);//初始化链表
bool ListInsert(LinkList *list,int loc,ElemType e);//插入元素
void OutPrintf(LinkList list);//遍历输出链表的值
bool ListDelete(LinkList *list,int loc,ElemType e);//删除指定元素
int main(){
    LinkList list;
    InitList(&list);
    ListInsert(&list,1,1);
    ListInsert(&list,0,1);
    ListInsert(&list,10,1);
    ListInsert(&list,2,5);
    ListInsert(&list,3,20);
    OutPrintf(list);
    return 0;
}
bool InitList(LinkList *list){
    *list =(LNode *)malloc(sizeof (LNode));
    if(*list==NULL){
        printf("分配内存失败\n");
        return false;
    }
    (*list)->next=NULL;
    return true;
}
bool ListInsert(LinkList *list,int loc,ElemType e){
    if(loc<1){
        printf("输入不合法(i<1)\n");
        return false;
    }
    LNode *p;
    int j=0;
    p=*list;
    while(p!=NULL&&j<loc-1){
        p=p->next;
        j++;
    }
    if(p==NULL){
        printf("输入位置不合法(太大了)\n");
        return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    s->next=p->next;
    p->next=s;
    return true;
}
void OutPrintf(LinkList list){
    LNode *node=list->next;   //链表带有头节点，跳过第一个节点
    printf("链表的值为\n");
    while (node!=NULL)
    {
        printf("%d    ",node->data);
        node=node->next;
    }
    printf("\n");
    
}
bool ListDelete(LinkList *list,int loc,ElemType e){
    if(loc<1){
        printf("输入位置不合法(太小了)\n");
        return false;
    }
    int j=0;
    LNode *p=*list;
    while (p!=NULL&&j<loc-1)
    {
        p=p->next;
        j++;
    }
    if(p==NULL){
        printf("输入位置不合法(太大了)\n");
        return false;
    }
    
}