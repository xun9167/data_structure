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
double p_digui(int n,double x);//原版递归算法
double p(int n,double x);//把一个递归的算法改为用栈实现
void OutPrint(SqStack *s);//输出栈中元素
void InitStack(SqStack *s);//初始化栈
bool StackEmpty(SqStack *s);//判栈空
bool push(SqStack *s,ElemType x);//元素x进栈
bool pop(SqStack *s,ElemType *x);//出栈，x记录出栈元素的值
bool GetTop(SqStack *s,ElemType *x);//读栈顶元素，用x记录
int main(){
    int n;
    double x;
    scanf("%d",&n);
    scanf("%lf",&x);
    printf("%lf",p_digui(n,x));
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
double p(int n,double x){

}
double p_digui(int n,double x){
    if(n==0)
        return 1;
    if(n==1)
        return 2*x;
    else
        return 2*x*p_digui(n-1,x)-2*(n-1)*p_digui(n-2,x);
}


