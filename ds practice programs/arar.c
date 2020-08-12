#define max 7
#include<stdio.h>
void arraypass(int *,int);
int main()
{
    int a[max],i;
    printf("enter values:");
    for(i=0;i<max;i++)
    scanf("%d",&a[i]);
    arraypass(a,max);
}
void arraypass(int *p,int s)
{
    int i;
    printf("values:");
    for(i=0;i<s;i++){
    printf(" %d ",*(p+i));
    }
}
