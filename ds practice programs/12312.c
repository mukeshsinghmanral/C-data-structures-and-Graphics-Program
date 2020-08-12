#include<stdio.h>
#define Max 5
int push(int *,int,int);
int pop(int *,int,int);
void display(int *,int);
int main(){
    int stack[Max],top=-1,choice,temp_var,item;
    while(1){
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("\nenter your choice");
        scanf("%d",&choice);
        switch(choice){
        case 1 : printf("enter an element to be pushed into stack:");
        scanf("%d",&item);
        top = push(stack,top,item);
        break;
        case 2 : top=pop(stack,top,temp_var);
        break;
        case 3 : display(stack,top);
        break;
        case 4 : exit(0);
        default : printf("\n wrong input");
        }
    }
    return 0;
}
int push(int *s,int top,int item){
   if(top==Max-1){
    printf("\nstack is overflow");
   }
   else{
    top++;
    s[top]=item;
   }
   return top;
}
int pop(int *s,int top,int temp_var){
   if(top==-1){
    printf("\nstack is underflow");
   }
   else{
    temp_var=s[top];
    printf("\ndeleted element is %d",temp_var);
    top--;
   }
   return top;
 }
 void display(int *s,int top){
   int i;
   if(top==-1){
    printf("\nstack is empty");
   }
   else{
        printf("\nstack is as follows\n");
        for(i=top;i>=0;--i){
            printf("%d\n",*(s+i));

        }

   }
 }
