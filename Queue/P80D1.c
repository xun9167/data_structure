#include <stdio.h>
#include <stdbool.h>
#define MaxSize 5
#define ElemType int
typedef struct squeue{
    ElemType data[MaxSize];
    int front,rear; 
    int tag;   //front 队头，rear 队尾
}SqQueue;
void InitQueue(SqQueue *Q);//初始化
bool EnQueue(SqQueue *Q,ElemType x);//入队
bool DeQueue(SqQueue *Q,ElemType *x);//出队
int main(){
    SqQueue q;
    InitQueue(&q);
    int n=0,x;
    while (n!=-1)
    {
        scanf("%d",&n);
        switch (n)
        {
        case 1:
        printf("输入入队值\n");
        scanf("%d",&x);
        EnQueue(&q,x);
        printf("rear=%d,front=%d\n",q.rear,q.front);
            break;
        
        case 2:
        DeQueue(&q,&x);
        printf("出队元素为=%d",x);
            break;
        }
    }
    
    return 0;
}
void InitQueue(SqQueue *Q){
    Q->rear=Q->front=0;
    Q->tag=0;
}
bool EnQueue(SqQueue *Q,ElemType x){
    if(Q->rear==Q->front&&Q->tag==1){
        printf("此队已满，无法入队\n");
        return false;
    }
    Q->data[Q->rear]=x;
    Q->rear=(Q->rear+1)%MaxSize;
    Q->tag=1;
    return true;
}
bool DeQueue(SqQueue *Q,ElemType *x){
    if(Q->rear==Q->front&&Q->tag==0){
        printf("此队已空，无法出队\n");
        return false;
    }
    *x=Q->data[Q->front];
    Q->front=(Q->front+1)%MaxSize;
    Q->tag=0;
    return true;
}