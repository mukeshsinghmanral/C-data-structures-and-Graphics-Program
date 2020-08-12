#define max 8
#include<stdio.h>
void create();
void display(int [],int);
void sum(int [],int);
void exit();
int main()
{
    int a[max];
   int choice;
   printf("\t\t\t    ----------------ARRAY OPERATIONS---------------");
   while(1){
   printf("\n1.Create:\n2.Display\n3.Sum of elements\n4.Exit:\n");
   printf("enter choice:");
   scanf("%d",&choice);
   switch(choice)
   {
       case 1  :create(a,max);
                 break;
       case 2  : display(a,max);
                break;
       case 3  : sum(a,max);
                break;
       case 4  : printf("GOOD BYE");
                 exit(0);
                break;
       default : printf("\nwrong input");
                 break;
   }
   }
   return 0;
}
void create(int b[max],int s){
    int i;
    printf("enter values:");
    for(i=0;i<s;i++)
        scanf("%d",&b[i]);
}
void display(int b[max],int s){
    int i;
    for(i=0;i<s;i++)
        printf(" %d ",b[i]);
}
void sum(int b[max],int s){
   int i,sum=0;
   for(i=0;i<s;i++){
    sum=sum+b[i];
   }
   printf("sum:%d",sum);
}


