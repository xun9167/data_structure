#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct LNode{
  ElemType data;
  struct LNode* next;
}LNode,*LinkList;
bool InitLinkList(LinkList *node);
bool ListInsert(LinkList *node,int loc,ElemType data);
int main(){
  LinkList node;
  InitLinkList(&node);
  printf("1=%d\n",ListInsert(&node,1,10));
  printf("1=%d\n",ListInsert(&node,2,10));
  printf("1=%d\n",ListInsert(&node,3,10));
  printf("0=%d\n",ListInsert(&node,5,10));
  printf("0=%d\n",ListInsert(&node,0,10));
  system("pause");
}
bool InitLinkList(LinkList *node){
  *node = NULL;
  return true;
}
bool ListInsert(LinkList *node,int loc,ElemType data){
  if(loc<1){
    return false;
  }
  if(loc==2 && node==NULL){
    return false;
  }
  LNode *q;
  q = *node;
  int j = 0;

  while(j<loc-2){
    if(q==NULL){
      return false;
    }
    j++;
    q=q->next;
  }
  
  LNode* p = (LNode*)malloc(sizeof(LNode));
  p->data = data;
  p->next = NULL;

  //头插
  if(loc==1){
   p->next = *node;
   *node = p; 
   return true;
  }

  if(q==NULL){
    return false;
  }
  q->next = p;
  return true;
}