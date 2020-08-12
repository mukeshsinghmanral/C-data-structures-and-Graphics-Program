#include<stdio.h>
void array(int[],int,int);
int main(){
int a[20],n,i;
printf("enter number of elements=");
scanf("%d",&n);
printf("enter values=");
for(i=0;i<n;i++)
scanf("%d",(a+i));
array(a,n,i);
}
void array(int b[],int p,int i){
printf("values=");
for(i=0;i<p;i++)
printf(" %d ",*(b+i));
}
