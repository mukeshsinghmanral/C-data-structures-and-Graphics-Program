#include<stdio.h>
int power(int **);
int main(){
  int a=5,*ptr;
  ptr=&a;
  a=power(&ptr);
  printf("%d\n",a);
  return 0;
}
int power(int **ptr){
  int p;
  p=**ptr * **ptr;
  return (p);
}
