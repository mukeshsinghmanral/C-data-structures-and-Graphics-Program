#include<stdio.h>
#define MAX 5
int push(int *,int,int);
int pop(int *,int);
void display(int *,int);
void exit();
int main(){
  int stack[MAX],TOP=-1,item,choice;
  while(1){
    printf("\n1.push\n2.pop\n3.display\n4.exit\n");
    printf("enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("\nenter item to be push:\n");
             scanf("%d",&item);
             TOP=push(stack,TOP,item);
             break;
    case 2 : TOP=pop(stack,TOP);
                 break;
    case 3 : display(stack,TOP);
                        break;
    case 4 : exit(0);
                break;
    default : printf("invalid input");

    }
  }
  return 0;
}
int push(int *s,int top,int item){
    if(top<MAX-1){
             top++;
        *(s+top)=item;
    }
    else{

        printf("stack is overflow!");
    }
    return top;
}
int pop(int *s,int top){
  int temp;
 if(top==-1){
    printf("underflow condition!");
 }
 else{
    temp=*(s+top);
    top--;
    printf("%d is popped recently",temp);
 }
 return top;
}
void display(int *s,int top){
  int i;
  if(top==-1){
    printf("stack is empty!");
  }
  else{
        printf("stack:\n");
    for(i=top;i>=0;i--){
        printf("%d\n",*(s+i));
    }
  }
}
