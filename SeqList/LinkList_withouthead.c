#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define ElemType int
typedef struct LNode{  //定义单链表结点类型 
	ElemType data;     //每个结点存放一个数据元素 
	struct LNode* next; //指针指向下一个结点 
}LNode,*LinkList;

//初始化一个空白的单链表 
bool InitList(LinkList *L)
{
	L=NULL;    //空表，暂时还没有存放任何结点（防止脏数据） 
	return true;
}

//在第i个位置插入元素e:
bool ListInsert(LinkList *L,int i,ElemType e)
{
	if(i<1)return false;
	if(i==1)   //插入第一个结点的操作与其他结点不同。 
	{ 
		LNode* s=(LNode*)malloc(sizeof(LNode));
		s->data=e;
        printf("%d",s->data);
		s->next=L;
		L=s;        //头指针指向新结点 
		return true;
	}
	LNode *p;      //指针p指向当前扫描到的结点 
	int j=1;       //当前p指向的是第几个结点 
	p=L;           //p指向第一个结点（不是头结点） 
	while(p!=NULL&&j<i-1)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)return false;   //i值不合法 
	LNode* s=(LNode*)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}

void OutputList(LinkList L)
{   printf("链表的值为\n");
	LinkList p=L;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{   //声明一个指向单链表的指针 
	LinkList L;
	//初始化一个空表 
	InitList(L);
    int i;
    printf("插入元素");
	//在单链表的第i个位置插入元素i: 
	ListInsert(&L,1,1);
    ListInsert(&L,2,1);
    ListInsert(&L,3,1);
	//输出单链表中的所有元素： 
	OutputList(&L);
	
	return 0;
}