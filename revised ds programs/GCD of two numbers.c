#include<stdio.h>
int gcd_2numbers(int *,int*);
int main()
{
    int a,b,gcd;
    printf("enter two number\n");
    scanf("%d%d",&a,&b);
    gcd=gcd_2numbers(&a,&b);
    printf("gcd of %d and %d is: %d",a,b,gcd);
    return 0;
}
int gcd_2numbers(int *a,int *b){
  int z;
  int c;
  if((*a)==(*b))
    return (*a);
   if((*b)%(*a)==0)
    return (*a);
  if((*a)%(*b)==0)
    return (*b);
  if((*a)>(*b)){
        z=(*a)%(*b);
   c=gcd_2numbers(&z,b);
   return c;
  }
  else{
      z=(*b)%(*a);
    c=gcd_2numbers(a,&z);
    return c;
  }
}
