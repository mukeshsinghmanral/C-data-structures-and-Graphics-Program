#include<stdio.h>
#include<math.h>
float square(float);
float cube(float);
float squareroot(float);
void exit();
int main(){
  int choice;
  float sqrt,sqr,cub,a;
  printf("enter number:");
  scanf("%f",&a);
  while(1){
    printf("\n1.square:\n2.cube:\n3.square root:\n4.exit:\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 :  sqr=square(a);
    printf("square of %f is %f",a,sqr);
    break;
    case 2 : cub=cube(a);
    printf("cube of %f is %f",a,cub);
    break;
    case 3 :sqrt=squareroot(a);
    printf("square root of %f is %f",a,sqrt);
    break;
    case 4 : exit(0);
    break;
    default : printf("invalid choice");
    }
  }
return 0;
}
float square(float a){
  a=pow(a,2);
  return a;
}
float cube(float a){
    a=pow(a,3);
    return a;
}
float squareroot(float a){
   a=sqrt(a);
   return a;
}
