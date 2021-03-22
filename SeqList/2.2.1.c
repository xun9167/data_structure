#include <stdio.h>
#include <stdbool.h>
#define MaxSize 20
#define ElemType int
typedef struct sqlList{
    ElemType data[MaxSize];
    int length;
}SqlList;
bool DeleteRep(SqlList *list);//P17D6删除重复元素
bool Delete_From_s_to_t(SqlList *list,ElemType s,ElemType t);//P17D4D5删除值在s和t之间的元素
bool DeleteX(SqlList *list,ElemType e);//P17D3删除顺序表中值为x的元素
bool ReverseList(SqlList *list);//P17D2逆转顺序表
bool DeleteMin(SqlList *list,ElemType *e);//P17D1删除最小值元素
bool Empty(SqlList *list);//判断是否为空  
void InitList(SqlList *list);
bool ListInsert(SqlList *list,int i,ElemType e);
bool ListDelete(SqlList *list,int i,ElemType *e);
ElemType GetElem(SqlList *list,int i);
int LocateElem(SqlList *list,ElemType e);//按值查找元素，并返回元素的下标
int main(){
    int i;
    SqlList list;
    InitList(&list);
    int loac,num,ret,s,t;
    while(loac!=-1){
        scanf("%d%d",&loac,&num);
        ListInsert(&list,loac,num);
    }
    printf("输入的顺序表为\n");
    for(i=1;i<=list.length;i++){
        printf("%d     ",GetElem(&list,i));
    }
    printf("输入s和t的值\n");
    scanf("%d%d",&s,&t);
    Delete_From_s_to_t(&list,s,t);
    for(i=1;i<=list.length;i++){
        printf("%d   ",GetElem(&list,i));
    }
    return 0;
}
void InitList(SqlList *list){
    int i;
    for(i=0;i<MaxSize;i++){
        list->data[i]=0;
    }
    list->length=0;
}
bool ListInsert(SqlList *list,int i,ElemType e){
    if(i<1||i>list->length+1)
        return false;
    if(i>MaxSize)
        return false;
    int j;
    for(j=list->length;j>=i;j--){
        list->data[j]=list->data[j-1];
    }
    list->data[i-1]=e;
    list->length++;
    return true;
}
bool ListDelete(SqlList *list,int i,ElemType *e){
    if(i<0||i>list->length)
        return false;
    *e=list->data[i-1];
    int j;
    for(j=i;j<list->length;j++){
        list->data[j-1]=list->data[j];
    }
    list->length--;
    return true;
}
ElemType GetElem(SqlList *list,int i){
    if(i<1||i>list->length)
        return -1;
    return list->data[i-1];
}
int LocateElem(SqlList *list,ElemType e){
    int i;
    for(i=0;i<list->length;i++){
        if(list->data[i]==e)
            return i+1;
    }
    return -1;
}
bool Empty(SqlList *list){
    if(list->length==0){
        printf("顺序表为空\n");
        return false;
    }
}
bool DeleteMin(SqlList *list,ElemType *e){
    if(list->length==0){
        return false;
    }
    *e=list->data[0];
    int i,postion;
    for(i=1;i<list->length;i++){
        if(list->data[i]<list->data[i-1]){
            *e=list->data[i];
            postion=i;
        }
    }
    list->data[postion]=list->data[list->length-1];
    list->length--;
    return true;
}
bool ReverseList(SqlList *list){
    ElemType ret;
    int i;
    for(i=0;i<list->length;i++){
        ret=list->data[i];
        list->data[i]=list->data[list->length-i-1];
        list->data[list->length-i-1]=list->data[i];
    }
    return true;
}
bool DeleteX(SqlList *list,ElemType e){
    if(list->length<1)
        return false;
    int count; //顺序表中值不为x的个数
    int i;
    for(i=0;i<list->length;i++){
        if(list->data[i]!=e){
            list->data[count]=list->data[i];
            count++;
        }
    }
    list->length=count;
    return true;
}
bool Delete_From_s_to_t(SqlList *list,ElemType s,ElemType t){
    if(s>=t||list->length==0)
        return false;
    int count=0;
    int i;
    for(i=0;i<list->length;i++){
        if(list->data[i]<s||list->data[i]>t){
            list->data[count]=list->data[i];
            count++;
        }
    }
    list->length=count;
    return true;
}
bool DeleteRep(SqlList *list){
    
}