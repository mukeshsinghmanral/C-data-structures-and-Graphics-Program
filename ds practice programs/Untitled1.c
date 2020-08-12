#include<stdio.h>
int main() {
    char ch='w';
    char *c=&ch;
    char **p=&c;
    printf("%c\t%c\t%c",**p,*c,ch);
    return 0;
}

