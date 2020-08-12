#include<stdio.h>
void input(int *,int);
void output(int *,int);
void sort(int *,int);
void merge(int *,int,int);
int main(){
  int a[10],m;
  printf("enter number of elements of 1st array:\n");
  scanf("%d",&m);
  input(a,m);
  merge(a,m);
  printf("\n sorted values:\n");
  output(a,m);
  return 0;
}
void input(int *b,int s){
   int i;
   for(i=0;i<s;i++){
    printf("enter values:");
    scanf("%d",(b+i));
   }
}
void output(int *b,int s){
  int i;
  for(i=0;i<s;i++)
    printf(" %d ",*(b+i));
}

void merge(int *a,int m){
   int i,j,k;
   i=0,j=0,k=0;
   while(i<m&&j<n){
    if(a[i]>b[j]){
        c[k]=b[j];
        j++;
        k++;
    }
        else if(a[i]<b[j]){
            c[k]=a[i];
            i++;
            k++;
        }
        else if(a[i]==b[j]){
            c[k]=a[i];
            i++;
            k++;
            c[k]=b[j];
            j++;
            k++;
        }
    }
   if(i==m){
    while(j<n){
        c[k]=a[j];
        j++;
        k++;
    }
   }
   else if(j==n){
    while(i<m){
        c[k]=a[i];
        i++;
        k++;
    }
   }
}
