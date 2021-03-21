#include "stdio.h"
void minmax(int a[],int len,int *max,int *min){
    printf("minmax sizeof(a)=%lu\n",sizeof(a));
    int i;
    *min =a[0];
    *max=a[0];
    for(i=1;i<len;i++){
        if(a[i]<*min)
            *min=a[i];
        if(a[i]>*max)
            *max=a[i];
    }

}
int main()
{
    
    int min,max;
    int a[]={1,2,3,4,5,6,7,8,9,10};
    printf("a_location=%p\n",a);
    minmax(a,10,&max,&min);
    printf("max=%d\nmin=%d",max,min);
    return 0;
}
