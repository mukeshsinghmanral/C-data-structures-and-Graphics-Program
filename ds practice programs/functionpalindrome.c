#include<stdio.h>
void palindromecheck(int,int,int,int);
int main(){
    int n,m,r,x;
printf("enter any natural number=");
scanf("%d",&n);
x=n;
while(n>0){
m=n%10;
r=r*10+m;
n=n/10;
}
palindromecheck(x,m,r,x);
return 0;
}
void palindromecheck(int n,int m,int r,int x){
if(r==x){
printf("number is palindrome");
}
else
printf("number is not palindrome");
}
