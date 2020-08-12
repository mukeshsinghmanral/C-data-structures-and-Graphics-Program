#define Max 5
#include<stdio.h>
int push(int *,int,int);
int pop(int *,int);
void display(int *,int);
void exit();
int main(){
  int stack[Max],item,choice,top=-1;
  printf("\t\t\t\t\t\t  STACK IMPLEMENTATION    ");
  while(1){
  printf("\n1.push\n2.pop\n3.display\n4.exit\n");
  printf("\nenter your choice:\n");
  scanf("%d",&choice);

    switch(choice){
      case 1 : printf("\nenter item to be push:\n");
              scanf("%d",&item);
              top=push(stack,top,item);
               break;
      case 2 : top=pop(stack,top);
                break;
    case 3  : display(stack,top);
              break;
      case 4 : exit(0);
               break;
      default : printf("\nwrong input\n");
    }

  }
  return 0;
}
int push(int *s,int top,int item){
    if(top==Max-1){
        printf("\nstack is overflow!\n");
    }
    else if(top<Max-1) {
            top++;
        s[top]=item;
    }
    return(top);
}
int pop(int *s,int top){
   int temp;
   if(top==-1){
    printf("\nstack is underflow!\n");

   }
   else{
   temp=s[top];
    printf("\nnumber popped:\n");
    printf("%d",temp);
    top--;

   }
   return(top);
}
void display(int *s,int top){
    int i;
    if(top==-1){
        printf("\nstack is empty\n");
    }
    else{
        printf("\nstack is:\n");
    for(i=top;i>=0;i--){
     printf("%d\n",*(s+i));
       }
    }
}
