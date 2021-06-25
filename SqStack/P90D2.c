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
void Train_Arrange(int train[],int n);//火车调度 0表示硬座 1表示软座要求 软座在硬座前（1在0前）
void OutPrint(SqStack *s);//输出栈中元素
void InitStack(SqStack *s);//初始化栈
bool StackEmpty(SqStack *s);//判栈空
bool push(SqStack *s,ElemType x);//元素x进栈
bool pop(SqStack *s,ElemType *x);//出栈，x记录出栈元素的值
bool GetTop(SqStack *s,ElemType *x);//读栈顶元素，用x记录
int main(){
    int n;
    scanf("%d",&n);
    int i;
    int train[n];
    for(i=0;i<n;i++){
        scanf("%d",&train[i]);
    }
    Train_Arrange(train,n);
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
void Train_Arrange(int train[],int n){
    SqStack s;
    InitStack(&s);
    int i=0;
    int k=0;
    for(i=0;i<n;i++){
        if(train[i]==0){
            printf("%d",train[i]);
            push(&s,train[i]);
            printf("第%d号车厢进入调度",i);
        }
        else{
            train[k]=1;
            k++;
        }
    }
    while (!StackEmpty(&s))
    {
        int ret;
        pop(&s,&ret);
        printf("11\n");
        train[k]=0;
        printf("%d",k);
        k++;
    }
    for(i=0;i<n;i++){
        printf("%d",train[i]);
    }
}

