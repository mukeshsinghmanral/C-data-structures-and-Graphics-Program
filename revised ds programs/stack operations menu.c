#include<stdio.h>
#define Max 10
int push(int *,int ,int,int);
int pop(int *,int,int);
void traverse(int *,int);
void exit();
int main(){
  int s[Max],choice,n,item,top=-1;
  printf("enter number of items in stacks:");
  scanf("%d",&n);
  while(1){
    printf("\n1.push an item\n2.pop an item\n3.traverse\n4.exit\n");
    printf("enter your choice");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter item to be inserted:");
    scanf("%d",&item);
    top=push(s,n,top,item);
    break;
    case 2 :
    top=pop(s,n,top);
    break;
    case 3 : traverse(s,top);
    break;
    case 4 : exit(0);
    break;
    default : printf("invalid choice");
    }

  }
  return 0;
}
int push(int *s,int n,int top ,int item){
  if(top<n-1){
    top++;
    *(s+top)=item;
  }
  else {
    printf("stack overflow!");
  }
  return top;
}
int pop(int *s,int n,int top){
  int temp;
  if(top==-1){
    printf("stack underflow!");
  }
  else{
    temp=s[top];
    top--;
    printf("popped item: %d",temp);
        }
return top;
}
void traverse(int *s,int top){
  int i;
if(top==-1){
    printf("stack is empty");
}
else{
    printf("stack is:\n");
    for(i=top;i>=0;i--){
        printf("%d\n",*(s+i));
    }
}
}
