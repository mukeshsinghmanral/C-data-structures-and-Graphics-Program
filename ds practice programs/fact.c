#include<stdio.h>
int fact(int);
int main(){
 int n;
 printf("enter natural no.");
 scanf("%d",&n);
 fact(n);
 printf("factorial=%d",fact(n));
 return 0;
}
int fact(int n){
  int result;
  if(n==0){
    return 1;
  }
  else{
    result=n*fact(n-1);
    return result;
  }
}
