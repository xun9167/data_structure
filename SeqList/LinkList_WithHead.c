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
bool ListDelete(LinkList *list,int loc,ElemType *e);//删除指定元素
LNode *GetElem(LinkList list,int loc);//根据位置取元素
bool InsertNextNode(LNode *p,ElemType e);//指定节点的后插操作，其中p应为链表中的元素
bool InsertPriorLNode(LNode *p,ElemType e);//指定节点的前插操作，其中p应为链表中的元素
bool DeleteNode(LNode *p);//指定节点的删除.其中p应为链表中的元素
int main(){
    LinkList list;
    InitList(&list);
    ListInsert(&list,1,1);
    ListInsert(&list,0,1);
    ListInsert(&list,10,1);
    ListInsert(&list,2,5);
    ListInsert(&list,3,20);
     ListInsert(&list,4,20);
    OutPrintf(list);
    int e;
    LNode *p;
    scanf("%d",&e);
    p=GetElem(list,e);
    DeleteNode(p);
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
bool ListDelete(LinkList *list,int loc,ElemType *e){
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
    if(p->next==NULL){
        printf("后面没有元素了\n");
        return false;
    }
    LNode *q=p->next;
    *e=q->data;
    p->next=q->next;
    free(q);
    return true;
}
LNode *GetElem(LinkList list,int loc){
    if(loc<1){
        printf("输入i值不合法（太小了）\n");
        return NULL;
    }
    int j=0;
    LNode *p=list;
    while(p!=NULL&&j<loc){
        p=p->next;
        j++;
    }
    if(p==NULL){
        printf("输入i值不合法（太大了）\n");
        return NULL;
    }
    return p;
}
bool InsertNextNode(LNode *p,ElemType e){
    if(p==NULL){
        printf("传入元素为空\n");
        return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->data=e;
    printf("s的%d",s->data);
    s->next=p->next;
    printf("%d",p->data);
    p->next=s;
    return true;
}
bool InsertPriorLNode(LNode *p,ElemType e){
    if(p==NULL){
        printf("传入的元素不合法（为空）");
        return false;
    }
    LNode *s=(LNode *)malloc(sizeof(LNode));
    s->next=p->next;                //前插操作依旧按照后插的思路来，只不过在进行后插之后，对换s，p的值
    p->next=s;
    s->data=p->data;
    p->data=e;
    return true;
}
bool DeleteNode(LNode *p){
    if(p==NULL){
        printf("元素p为空，无法删除\n");
        return false;
    }
    LNode *s=p->next;
    p->data=p->next->data;
    p->next=s->next;       //换元素值实现删除，存在小bug，如果时最后一个会出问题
    free(s);
    return true;
}