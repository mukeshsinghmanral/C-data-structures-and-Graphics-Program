#include<Stdio.h>
#define max 10
void create(int *,int);
int insert(int *,int,int,int);
void del(int *,int *,int,int);
int search(int *,int,int);
void sort(int *,int);
void merge(int *,int *,int *,int,int);
void display(int *,int);
void exit();
int main(){
  int a[max],choice,n,i,a2[max],a3[2*max],l,m,item,position;
  printf("\n1.create\n2.insert\n3.delete\n4.search\n5.sort array\n6.merge array\n7.display\n8.exit\n");
  printf("enter your choice");
  scanf("%d",&choice);
  while(1){
    switch(choice){
     case 1 : printf("enter number of elements:");
     scanf("%d",&n);
     create(a,n);
     break;
     case 2 : printf("enter the item and position:");
     scanf("%d%d",&item,&position);
     insert(a,n,item,position);
     break;
     case 3 : printf("the item and it's position:");
     scanf("%d%d",&item,&position);
     del(a,&n,item,position);
     break;
     case 4 : printf("enter the element to be search:");
     scanf("%d",&item);
     position=search(a,n,item);
     case 5 : sort(a,n);
     if(position==n){
        printf("\nitem is not present");
     }
     else {
        printf("\n %d is present at %d position",item,position);
     }
     break;
     break;
     case 6 :printf("enter second array number of elements:");
     scanf("%d",&l);
     printf("enter values in sorted form:");
     for(i=0;i<m;i++)
      scanf("%d",(a2+i));
        merge(a,a2,a3,l,m);
        break;
    case 7 : display(a,n);
       break;
       case 8 : exit(0);
       break;
       default: printf("wrong input");
       break;
    }

  }
  return 0;
}
void create(int *a,int n){
  int i;
  for(i=0;i<n;i++)
    scanf(" %d ",(a+i));
}
int insert(int *a,int n,int item,int pos){
    int c;
    for(c=n-1;c>=pos-1;c--){
        a[c+1]=a[c];
    }
    a[pos-1]=item;
    n++;
    return(n);
}
void del(int *a,int *l,int item,int pos){
    int temp,c;
    temp=item;
   for(c=pos-1;c<*(l-1);c++){
    a[c]=a[c+1];
   }
   (*l)--;
}
int search(int *a,int n,int item)
 int i,pos;
 for(i=0;i<n;i++){
    if(item==a[i])
    {
        pos=i+1;
        return(pos);
    }
}
void merge(int *a,int *b,int *c,int l,int m){
        int i,j,k;
        i=j=k;
        while(i<l&&j<m){
            if(a[i]<b[j]){
                c[k]=a[i];
                k++;
                i++;
            }
            else if(a[i]>b[j]){
                c[k]=b[j];
                k++;
                j++;
            }
            else if(a[i]==b[j]){
                c[k]=a[i];
                k++;
                i++;
                c[k]=b[j];
                k++;
                j++;
            }
        }
        if(i==l){
            while(j<m){
                c[k]=b[j];
                k++;
                j++;
            }
        }
        else if(j==m){
            while(i<l){
                c[k]=a[i];
                k++;
                i++;
            }
        }
}
void sort(int *a,int l){
      int i,j,temp;
      for(i=0;i<l;i++){
        for(j=i+1;j<l;j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
      }
}
void display(int *a,int n){
int i;
for(i=0;i<n;i++)
printf(" %d ",*(a+i));
}
