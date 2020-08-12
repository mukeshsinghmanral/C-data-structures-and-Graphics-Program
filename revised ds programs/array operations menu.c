#include<stdio.h>
#define Max 10
int create(int *,int);
void traverse(int *,int);
void search(int *,int,int);
int insert(int *,int, int);
int del(int *,int,int);
void merge(int *,int,int *,int);
void sort(int *,int);
void exit();
int main(){
 int a[Max],i ,a2[10], choice,item,l,n,p;
 while(1){
    printf("\n1.create array:\n2.traverse array:\n3.search an item:\n4.insert an item:\n5.delete an item:\n6.merge two arrays:\n7.exit:\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : printf("enter number of elements:");
    scanf("%d",&n);
        l=create(a,n);
    break;
    case 2 : traverse(a,l);
    break;
    case 3 : printf("enter item to be searched:");
             scanf("%d",&item);
             search(a,l,item);
    break;
    case 4 : printf("enter item:");
    scanf("%d",&item);
    l=insert(a,l,item);
    break;
    case 5 : printf("enter item:");
    scanf("%d",&item);
    l=del(a,l,item);
    break;
    case 6 :printf("enter number of elements of second array:");
               scanf("%d",&p);
               printf("enter values of 2nd array:");
         for(i=0;i<p;i++){
        scanf("%d",(a2+i));
        }
         merge(a,l,a2,p);
    break;
    case 7 : exit(0);
    break;
    default : printf("invalid choice");
    }
 }
 return 0;
}
int create(int *b,int n){
 int i;
 printf("enter values:");
 for(i=0;i<n;i++){
    scanf("%d",(b+i));
 }
 return n;
}
void traverse(int *b,int l){
 int i;
 printf("values are:");
 for(i=0;i<l;i++){
    printf("%d ",*(b+i));
 }
}
void search(int *b,int l,int item){
  int i,f=0,count=0;
  for(i=0;i<l;i++){
    if(item==*(b+i)){
        f=1;
        break;
    }
    count++;
  }
  if(f==0)
    printf("item is not found");
  else
    printf("%d is found  at %d position",item,count+1);
}
int insert(int *b,int l,int item){
  int i,f=0,pos;
  for(i=0;i<l;i++){
    if(item==*(b+i)){
        f=1;
        break;
    }
  }
  if(f==1){
    printf("item is already present!");
    return l;
  }
  else{
    printf("enter position:");
    scanf("%d",&pos);
    for(i=l-1;i>=pos-1;i--){
        *(b+i+1)=*(b+i);
    }
    *(b+(pos-1))=item;
     }
  return(++l);
}
int del(int *b,int l,int item){
  int i,f=0,pos;
  for(i=0;i<l;i++){
    if(item==*(b+i)){
        f=1;
        pos=i;
        break;
    }
  }
  if(f==1){
    for(i=pos;i<l;i++){
        *(b+i)=*(b+i+1);
    }
    return(--l);
  }
  else{
    printf("item is not found!");
    return l;
  }
}
void merge(int *b,int l,int *a2,int p){
    int a[l+p],i,j,k;
    i=j=k=0;
 sort(b,l);
 sort(a2,p);
 while(i<l&&j<p){
    if(b[i]<a2[j]){
        a[k]=b[i];
        i++;
        k++;
    }
    else if(b[i]>a2[j]){
        a[k]=a2[j];
        j++;
        k++;
    }
    else{
        a[k]=b[i];
        i++;
        k++;
        a[k]=a2[j];
        j++;
        k++;
    }
 }
 if(i==l){
        while(j<p){
    a[k]=a2[j];
    j++;
    k++;
        }
    }
    else{
        while(i<l){
            a[k]=b[i];
            i++;
            k++;
        }
    }
    printf("after sorting arrays\n");
 traverse(a,l);
 printf("\n");
 traverse(a2,p);
 printf("\n");
 printf("merged array:\n");
 traverse(a,l+p);
 }

void sort(int *b,int l){
 int i,j,temp;
 for(i=0;i<l;i++){
    for(j=i+1;j<l;j++){
        if(b[i]>b[j]){
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;
        }
    }
 }
}
