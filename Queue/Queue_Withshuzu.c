#include <stdio.h>
#include <stdbool.h>
#define MaxSize 20
#define ElemType int
typedef struct squeue{
    ElemType data[MaxSize];
    int front,rear;    //front 队头，rear 队尾
}SqQueue;
void InitQueue(SqQueue *Q);//初始化
bool isEmpty(SqQueue Q);//判断对列是否为空
bool EnQueue(SqQueue *Q,ElemType x);//入队
bool DeQueue(SqQueue *Q,ElemType *x);//出队
void menu();//交互
int main(){
    SqQueue sq;
    int n=0;int x;
    InitQueue(&sq);
    
    while (n!=-1)
    {   menu();
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            isEmpty(sq);
            break;
        case 2:
            scanf("%d",&x);
            EnQueue(&sq,x);
            break;
        case 3:
            DeQueue(&sq,&x);
            printf("x=%d  ",x);
            break;
        }
    }
    
    return 0;
}
void menu(){
    printf("1.判空    ");
    printf("2.入队    ");
    printf("3,出队    ");
    printf("-1,结束   ");
}
void InitQueue(SqQueue *Q){
    Q->rear=Q->front=0;
}
bool isEmpty(SqQueue Q){
    if(Q.rear==Q.front){
        printf("队列为空!\n");
        return true;
    }
    else
        return false;
}
bool EnQueue(SqQueue *Q,ElemType x){
    if(((Q->rear+1)%MaxSize)==Q->front){
        printf("队列已满，无法入队\n");
        return false;
    }
    Q->data[Q->rear]=x;
    Q->rear=((Q->rear)+1)%MaxSize;
    return true;
}
bool DeQueue(SqQueue *Q,ElemType *x){
    if(Q->rear==Q->front){
        printf("队列为空，无法入队\n");
        return false;
    }
    *x=Q->data[Q->front];
    Q->front=(Q->front+1)%MaxSize;
    return true;
}

