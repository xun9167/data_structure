#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
void InOreder(BiTree *T);//中序遍历
void PreOrder(BiTree *T);//先序遍历
void visit(BiTNode * T);//访问一个节点
void insert(BiTree tree);//创建一棵树
int main(){
    BiTree root=NULL;
    root=(BiTree)malloc(sizeof(BiTNode));
    root->data=1;
    root->lchild=NULL;
    root->rchild=NULL;
    BiTNode *p1=(BiTNode *)malloc(sizeof(BiTNode));
    p1->data=2;
    p1->lchild=NULL;
    p1->rchild=NULL;
    root->lchild=p1;
    BiTNode *p2=(BiTNode *)malloc(sizeof(BiTNode));
    p2->data=3;
    p2->lchild=NULL;
    p2->rchild=NULL;
    root->rchild=p2;
    BiTNode *p3=(BiTNode *)malloc(sizeof(BiTNode));
    p3->data=4;
    p3->lchild=NULL;
    p3->rchild=NULL;
    p1->lchild=p3;
    BiTNode *p4=(BiTNode *)malloc(sizeof(BiTNode));
    p4->data=5;
    p4->lchild=NULL;
    p4->rchild=NULL;
    p1->rchild=p4;
    BiTNode *p5=(BiTNode *)malloc(sizeof(BiTNode));
    p5->data=6;
    p5->lchild=NULL;
    p5->rchild=NULL;
    p2->lchild=p5;
    BiTNode *p6=(BiTNode *)malloc(sizeof(BiTNode));
    p6->data=7;
    p6->lchild=NULL;
    p6->rchild=NULL;
    p2->rchild=p6;
    PreOrder(&root);
}
void visit(BiTNode * T){
    printf("%d",T->data);
}
void PreOrder(BiTree *T){
    if((*T)!=NULL){
        visit(*T);
        PreOrder(&((*T)->lchild));
        PreOrder(&((*T)->rchild));
    }
}

