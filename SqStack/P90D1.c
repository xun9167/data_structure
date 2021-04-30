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
int isLegal(char str[]);//判断表达式括号是否匹配
void OutPrint(SqStack *s);//输出栈中元素
void InitStack(SqStack *s);//初始化栈
bool StackEmpty(SqStack *s);//判栈空
bool push(SqStack *s,ElemType x);//元素x进栈
bool pop(SqStack *s,ElemType *x);//出栈，x记录出栈元素的值
bool GetTop(SqStack *s,ElemType *x);//读栈顶元素，用x记录
int main(){
    char str[100];
    scanf("%s",&str);
    isLegal(str);
    //printf("%s",str);
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
int isLegal(char str[]){
    SqStack s;
    InitStack(&s);
    int i=0;
    char x;
    while (str[i]!='\0')
    {
        switch (str[i])
        {
        case '(':
            push(&s,str[i]);
            break;
        case '{':
            push(&s,str[i]);
            break;
        case '[':
            push(&s,str[i]);
            break;
        case ')':
            if(StackEmpty(&s)){
                printf("不匹配\n");
                return -1;
            }
            pop(&s,&x);
            if(x!='('){
                printf("不匹配\n");
                return -1;
            }
            break;
        case '}':
             if(StackEmpty(&s)){
                printf("不匹配\n");
                return -1;
            }
            pop(&s,&x);
            if(x!='{'){
                 printf("不匹配\n");
                return -1;
            }
            break;
        case ']':
         if(StackEmpty(&s)){
                printf("不匹配\n");
                return -1;
            }
            pop(&s,&x);
            if(x!='['){
                printf("不匹配\n");
                return -1;
            }
            break;
        default:
            break;
        }
        i++;
    }
    if(!StackEmpty(&s)){
        printf("不匹配\n");
                return -1;
    }
    else{
        printf("匹配了\n");
        return 1;
    }
}


