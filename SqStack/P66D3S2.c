#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MaxSize  50
#define ElemType int
typedef struct sqStack
{
    ElemType data[MaxSize];
    int top;
}SqStack;
int Judge(int a[]);//1进栈，0出栈,-1结束
void OutPrint(SqStack *s);//输出栈中元素
void InitStack(SqStack *s);//初始化栈
bool StackEmpty(SqStack *s);//判栈空
bool push(SqStack *s,ElemType x);//元素x进栈
bool pop(SqStack *s,ElemType *x);//出栈，x记录出栈元素的值
bool GetTop(SqStack *s,ElemType *x);//读栈顶元素，用x记录
int main(){
    int a[100];
    int n,i;
    i=0;
    while (n!=-1)
    {
        scanf("%d",&n);
        a[i]=n;
        i++;
    }
    a[i+1]=-1;
    printf("Judge=%d",Judge(a));
    return 0;
}
void InitStack(SqStack *s){
    s->top=-1;
}
bool StackEmpty(SqStack *s){
    if(s->top==-1){
        printf("该栈为空\n");
        return true;
    }
    else
        return false;
}
bool push(SqStack *s,ElemType x){
    if(s->top==MaxSize-1){
        printf("%d",s->top);
        printf("此栈已满，无法添加\n");
        return false;
    }
    s->data[++s->top]=x;
    return true;
}
bool pop(SqStack *s,ElemType *x){
    if(s->top==-1){
        printf("此栈为空，无法出栈\n");
        return false;
    }
    *x=s->data[s->top--];
    return true;
}
bool GetTop(SqStack *s,ElemType *x){
    if(s->top==-1){
        printf("此栈为空，栈顶无元素\n");
        return false;
    }
    else{
        *x=s->data[s->top];
        return true;
    }
}
void OutPrint(SqStack *s){
    if(s->top==-1){
        printf("此栈为空，无法打印\n");
        return ;
    }
    int i;
    printf("栈中的元素为：\n");
    for(i=0;i<=s->top;i++)
        printf("%d  ",s->data[i]);
}
int Judge(int a[]){//1进栈，0出栈,-1结束
    int i=0;
    int jingCount,chuCount;
    jingCount=chuCount=0;
    while (a[i]!=-1)
    {
        if(a[i]==1) jingCount++;
        if(a[i]==0) chuCount++;
        if(jingCount<chuCount){
            printf("序列非法\n");
            return -1;
        }
        i++;
    }
    if(jingCount!=chuCount){
        printf("序列非法！\n");
        return -1;
    }
    return 1;
}


