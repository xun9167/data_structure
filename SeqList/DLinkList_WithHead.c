#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DNodeList;

bool InitDLnikList(DNodeList *list);//初始化双链表
bool Empty(DNodeList list);//判断带头节点的双链表是否为空
void CreateDList(DNodeList *list);//尾插法建立带头节点的单链表
void OutPrint(DNodeList list);//输出
int main(){
    DNodeList list;
    CreateDList(&list);
    OutPrint(list);
    return 0;
}
bool InitDLnikList(DNodeList *list){
    *list=(DNode *)malloc(sizeof(DNode));
    if(list==NULL){
        printf("分配内存失败\n");
        return false;
    }
    (*list)->prior=NULL;
    (*list)->next=NULL;
}
bool Empty(DNodeList list){
    if(list->next=NULL){
        printf("双链表是空的\n");
        return true;
    }
    return false;
}
void CreateDList(DNodeList *list){
    InitDLnikList(list);
    ElemType e;
    printf("输入要插入的元素的值(-1结束)\n");
    scanf("%d",&e);
    DNode *dnode,*tail;
    tail=*list;
    while (e!=-1)
    {
        dnode=(DNode *)malloc(sizeof(DNode));
        dnode->next=NULL;
        dnode->data=e;
        dnode->prior=tail;
        tail->next=dnode;
        tail=dnode;
        scanf("%d",&e);
    }
    return ;
}
void OutPrint(DNodeList list){
    DNode *p;
    p=list;
    p=p->next;
    printf("链表的值为：\n");
   /* printf("%d\n",p->data);
    printf("%d\n ",p->next->data);
    printf("%d\n",p->next->next->data);*/
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
    printf("\n");
}