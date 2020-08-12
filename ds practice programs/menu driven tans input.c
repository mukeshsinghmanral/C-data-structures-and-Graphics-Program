#define max 10
#include<stdio.h>
void input(int *,int);
void traverse(int *,int);
void exit();
int main()
{
   int a[max],n;
   char choice;
   while(1)
   {
       printf("\nInput:i");
       printf("\nTraverse:t");
       printf("\nWant to quit?:q");
       printf("\nEnter your choice:");

   choice=getche();
   switch(choice){
     case 'i':
     case 'I':
    printf("\nenter the size:");
    scanf("%d",&n);
    input(a,n);
    break;
     case 't' :
     case 'T' :
        traverse(a,n);
        break;
     case 'q' :
     case 'Q' :
        quit ();
        default : printf("\nYou have given the wrong choice");
     }
   }
   return 0;
}
void input(int *a,int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("\nenter the item:");
        scanf("%d",(a+i));
    }
}
void traverse(int *b,int n){
  int i;
  printf("\nthe elements are as follows:\n");
  for(i=0;i<n;i++){
    printf(" %d ",*(b+i));
  }
}
void quit(){
  char choice;
  printf("\ndo you want to quit?(y/n):");
  choice=getche();
  if(choice=='y'||choice=='Y'){
    exit(0);
  }
}
