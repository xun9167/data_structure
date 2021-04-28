#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#define MaxSize  50
#define ElemType char
typedef struct sqStack
{
    ElemType data[MaxSize];
    int top;
}SqStack;
bool bracketCheck(char str[],int length);//括号比较
void OutPrint(SqStack *s);//输出栈中元素
void InitStack(SqStack *s);//初始化栈
bool StackEmpty(SqStack *s);//判栈空
bool push(SqStack *s,ElemType x);//元素x进栈
bool pop(SqStack *s,ElemType *x);//出栈，x记录出栈元素的值
bool GetTop(SqStack *s,ElemType *x);//读栈顶元素，用x记录
int main(){
    char  str[]= {'{','[','[','}',']','}'};
    if(bracketCheck(str,6))
        printf("1");
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
bool bracketCheck(char str[],int length){
    SqStack s;
    InitStack(&s);
    int i;
    for(i=0;i<length;i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push(&s,str[i]);
        else{
            if(StackEmpty(&s))
                return false;
        char topElem;
        pop(&s,&topElem);
        if(str[i]==')'&&topElem!='(')
            return false;
        if(str[i]==']'&&topElem!='[')
            return false;
        if(str[i]=='}'&&topElem!='{')
            return false;
        }
    }
        return StackEmpty(&s);
}


