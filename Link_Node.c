#include "stdio.h"
#include "stdlib.h"
#ifndef _NODE_H
#define _NODE_H

typedef struct _node{
    int value;
    struct _node *next;
}Node;
typedef struct _list{
    Node * head;
}List;
#endif
 void add(List *plist,int n);
 void printLink(List *plist);
 void findvalue(List *plist);
 void deletevalue(List *plist);
int main(){
    Node *head=NULL;
    List list;
    list.head=NULL;
    int n;
    do{
        printf("输入链表元素(-1结束)\n");
        scanf("%d",&n);
        if(n!=-1){
            add(&list,n);
        }
    }while (n!=-1);    
    printLink(&list);
    Node *p,*q;
    for(p=head;p;p=q){
        q=p->next;
        free(p);
    }
    printf("free之后的链表:\n");
    printLink(&list);
    return 0;
}
//遍历--打印
 void printLink(List *plist){
      Node *p;
    for(p=plist->head;p;p=p->next){
        printf("%d\n",p->value);
    }
 }
//添加元素
 void add(List *plist,int n){
        Node *p=(Node *)malloc(sizeof(Node));
                p->value=n;
                p->next=NULL;
                //找到最后的元素
                Node *last=plist->head;
                if(last){ 
                        while (last->next)
                    {
                        //找到最后一个
                        last=last->next;
                    }
                    last->next=p;
                }else
                   plist->head=p;
}
//删除元素
void deletevalue(List *plist){
     printf("输入删除的值：\n");
    int find_n;
    scanf("%d",&find_n);
    Node *q,*p;
    for(q=NULL,p=(*plist).head;p;q=p,p=p->next){
        if(find_n==p->value){
            printf("找到了，值为%d\n",p->value);
            if(q){
                q->next=p->next;
            }else{
                (*plist).head=p->next;
            }
            free(p);
            break;
        } 
}
}
//查找元素
void findvalue(List* plist){
    printf("输入查找的值：\n");
    int find_n;
    scanf("%d",&find_n);
    Node *p;
    for(p=(*plist).head;p;p=p->next){
        if(find_n==p->value){
            printf("找到了，值为%d\n",p->value);
            break;
        } 
    }
}
