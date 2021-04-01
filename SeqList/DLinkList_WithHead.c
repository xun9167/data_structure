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
DNode *GetElem(DNodeList list,int loc);//对应下标元素
bool InsertNextDNode(DNode *dnode,DNode *p);//在dnode元素后添加元素
bool DeleteNextDNode(DNode *dnode);//删除指定节点
int main(){
    DNodeList list;
    CreateDList(&list);
    OutPrint(list);
    int loc;
    printf("输入值(位置)\n");
    scanf("%d",&loc);
    DNode *dnode=GetElem(list,loc);
    DeleteNextDNode(dnode);
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
    while(p!=NULL){
        printf("%d     ",p->data);
        p=p->next;
    }
    printf("\n");
}
DNode *GetElem(DNodeList list,int loc){
    if(loc<1){
        printf("输入i值不合法（太小了）\n");
        return NULL;
    }
    DNode *dnode;
    dnode=list->next;
    int j=1;
    while(dnode!=NULL&&j<loc){
        dnode=dnode->next;
        j++;
    }
    if(dnode==NULL){
        printf("输入i值不合法（太大了）\n");
        return NULL;
    }
    return dnode;
}
bool InsertNextDNode(DNode *dnode,DNode *p){
    if(dnode==NULL&&p==NULL){
        printf("传入节点不合法\n");
        return false;
    }
    
    if(dnode->next!=NULL)//判断dnode是否为最后一个节点，最后一个节点需要特殊处理
        dnode->next->prior=p;
    p->prior=dnode;
    p->next=dnode->next;
    dnode->next=p;
    return true;
}
bool DeleteNextDNode(DNode *dnode){
    if(dnode==NULL){
        printf("给定节点为空\n");
        return false;
    }
    if(dnode->next==NULL){
        printf("p为最后一个元素\n");
        return false;
    }
    DNode *p=dnode->next;
    p->prior=dnode->prior;
    dnode->prior->next=p;
    free(dnode);
    return true;
}