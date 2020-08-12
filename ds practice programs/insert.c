#include<stdio.h>
#define Max 10
void input(int *,int);
void output(int *,int);
int insert(int *,int,int,int);
int main(){
  int a[Max],n,item,position;
  printf("enter number of elements:\n");
  scanf("%d",&n);
  input(a,n);
  output(a,n);
  printf("\nenter number to be inserted:\n");
  scanf("%d",&item);
  printf("\nenter position:\n");
  scanf("%d",&position);
  n=insert(a,n,item,position);
  output(a,n);
  return 0;
}
void input(int *b,int n){
  int i;
  for(i=0;i<n;i++){
    printf("enter values:\n");
    scanf("%d",(b+i));
  }
}
void output(int *b,int n){
  int i;
  printf("values are:\n");
  for(i=0;i<n;i++){
    printf(" %d ",*(b+i));
  }
}
int insert(int *b,int n,int item,int pos){
  int i;
  for(i=n-1;i>=pos-1;i--){
    b[i+1]=b[i];
  }
  b[pos-1]=item;
  n++;
  return n;
}
