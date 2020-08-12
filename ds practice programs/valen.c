#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void drawheart();
void drawtext();
void basebox();
void man();
void girl();
void twinkle();
int main(){
init(600,500,"windows BGI",490,180);
drawheart();
//
man();
girl();
basebox();
drawtext();
twinkle();
getch();
closegraph();
}
void drawtext(){
settextstyle(1,0,3);
setcolor(LIGHTMAGENTA);
outtextxy(200,360,"Happy");
outtextxy(250,400,"Valentine\ 's");
outtextxy(300,450,"Day");
setcolor(WHITE);
}
void drawheart(){
line(50,349,550,349);
ellipse(245,250,60,250,120,200);
ellipse(355,250,280,480,120,200);
setfillstyle(240,250,WHITE);
}
void basebox(){
setfillstyle(9,LIGHTBLUE);
setcolor(YELLOW);
rectangle(50,350,550,500);
floodfill(100,400,YELLOW);
setcolor(WHITE);
}
void man(){
circle(250,230,20);
line(250,250,250,348);
line(250,348,200,320);
line(200,320,195,348);
line(250,290,300,280);
line(295,270,295,285);
circle(295,265,5);
}
void girl(){
circle(350,180,20);
line(350,200,350,348);
line(350,240,310,250);
line(350,280,370,340);
}
void twinkle(){
int x=300,y=250,c=0,i=1;
while(!kbhit()){
putpixel(x+rand()%300,y+rand()%240,c+rand()%16);
putpixel(x-rand()%300,y+rand()%240,c+rand()%16);
putpixel(x+rand()%300,y-rand()%240,c+rand()%16);
putpixel(x-rand()%300,y-rand()%240,c+rand()%16);
man();
girl();
drawtext();
}
}
