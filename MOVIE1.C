#include<graphics.h>
#include<stdlib.h>
void commonobjects();
void common();
void rain();
void message(char []);
void *p,*cl,*t,*s;
int poly[8],area;
int x1=0,y1=50;
void main()
{
int gd=DETECT,gm,i;
//Initialization Of Graphics Driver And Graphics mode
initgraph(&gd,&gm, "C:\\Turboc3\\BGI");
//Clouds
setlinestyle(0,0,3);
ellipse(200,50,60,240,10,15);
ellipse(225,40,345,165,20,15);
ellipse(262,47,340,160,20,15);
ellipse(268,66,230,50,20,15);
ellipse(226,71,163,340,31,15);
ellipse(300,41,20,182,21,19);
ellipse(325,50,290,100,21,15);
ellipse(299,70,228,20,33,15);
area=imagesize(180,20,350,100);
cl=malloc(area);
getimage(180,20,350,100,cl);
//Rain Drops
setlinestyle(0,0,3);
setfillstyle(SOLID_FILL,11);
setcolor(11);
pieslice(220,120,219,250,10);
area=imagesize(210,119,221,129);
p=malloc(area);
getimage(210,119,221,129,p);
//Tree
setfillstyle(SOLID_FILL,BROWN);
setcolor(BROWN);
line(30,200,30,310);
line(30,280,59,230);
line(30,280,10,230);
setcolor(GREEN);
setfillstyle(SOLID_FILL,GREEN);
fillellipse(30,210,10,15);
fillellipse(59,230,10,10);
fillellipse(10,230,9,10);
area=imagesize(0,195,80,310);
t=malloc(area);
getimage(0,195,75,310,t);
//Star
setcolor(WHITE);
line(11,10,16,10);
line(13,8,13,13);
area=imagesize(10,7,17,14);
s=malloc(area);
getimage(10,7,17,14,s);
cleardevice();
//Ground Points
//1st Vertex
poly[0]=0;
poly[1]=300;
//2nd Vertex
poly[2]=getmaxx();
poly[3]=400;
//3rd Vertex
poly[4]=getmaxx();
poly[5]=getmaxy();
//4th Vertex
poly[6]=0;
poly[7]=getmaxy();
while(!kbhit())
{
//Morning Scenery
setbkcolor(LIGHTBLUE);
message("SUNNY DAY");
commonobjects();
//Sun
setcolor(YELLOW);
setfillstyle(SOLID_FILL,YELLOW);
fillellipse(getmaxx()-80,60,45,45);
delay(5000);
cleardevice();
//Rainy Scenery
for(i=0;i<15;i++)
{
setbkcolor(BLACK);
message("RAINY DAY");
commonobjects();
rain();
cleardevice();
}
//Night Scenery
setbkcolor(BLACK);
message("COOL NIGHT");
common();
//Moon
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(getmaxx()-80,60,30,30);
delay(5000);
cleardevice();
}
getch();
closegraph();
}
void message(char msg[15])
{
setcolor(WHITE);
settextstyle(0,0,3);
outtextxy(10,10,msg);
}
void commonobjects()
{
putimage(50,30,cl,COPY_PUT );
putimage(250,30,cl,COPY_PUT);
putimage(getmaxy()-15,30,cl,COPY_PUT);
setfillstyle(SOLID_FILL,BROWN);
setcolor(BROWN);
fillpoly(4,poly);
putimage(0,192,t,COPY_PUT);
putimage(80,200,t,COPY_PUT);
putimage(160,213,t,COPY_PUT);
putimage(240,225,t,COPY_PUT);
putimage(320,238,t,COPY_PUT);
putimage(400,252,t,COPY_PUT);
putimage(480,265,t,COPY_PUT);
putimage(560,275,t,COPY_PUT);
}
void common()
{
int x=10;
setfillstyle(SOLID_FILL,BROWN);
setcolor(BROWN);
fillpoly(4,poly);
putimage(0,192,t,COPY_PUT);
putimage(80,200,t,COPY_PUT);
putimage(160,213,t,COPY_PUT);
putimage(240,225,t,COPY_PUT);
putimage(320,238,t,COPY_PUT);
putimage(400,252,t,COPY_PUT);
putimage(480,265,t,COPY_PUT);
putimage(560,275,t,COPY_PUT);
for(;x<getmaxx();x+=10)
putimage(random(getmaxx()),random(180),s,COPY_PUT);
}
void rain()
{
if((x1>=0)&&(y1<=280))
{
putimage(x1,y1,p,COPY_PUT);
putimage(x1+50,y1,p,COPY_PUT);
putimage(x1+50,y1+30,p,COPY_PUT);
putimage(x1+100,y1+20,p,COPY_PUT);
putimage(x1+150,y1,p,COPY_PUT);
putimage(x1+250,y1+30,p,COPY_PUT);
putimage(x1+550,y1+20,p,COPY_PUT);
putimage(x1+650,y1,p,COPY_PUT);
putimage(x1+210,y1+19,p,COPY_PUT);
putimage(x1+190,y1+25,p,COPY_PUT);
putimage(x1+240,y1+40,p,COPY_PUT);
putimage(x1+500,y1,p,COPY_PUT);
putimage(x1+500,y1+30,p,COPY_PUT);
putimage(x1+600,y1+20,p,COPY_PUT);
putimage(x1+600,y1+20,p,COPY_PUT);
putimage(x1+300,y1,p,COPY_PUT);
putimage(x1+400,y1,p,COPY_PUT);
putimage(x1+100,y1,p,COPY_PUT);
putimage(x1+200,y1+40,p,COPY_PUT);
putimage(x1+300,y1+50,p,COPY_PUT);
putimage(x1+400,y1+40,p,COPY_PUT);
putimage(x1+350,y1+55,p,COPY_PUT);
putimage(x1+450,y1+45,p,COPY_PUT);
putimage(x1+100,y1+50,p,COPY_PUT);
putimage(x1+200,y1+80,p,COPY_PUT);
putimage(x1+300,y1+70,p,COPY_PUT);
putimage(x1+400,y1+80,p,COPY_PUT);
putimage(x1+100,y1+70,p,COPY_PUT);
putimage(x1+500,y1+40,p,COPY_PUT);
putimage(x1+600,y1+50,p,COPY_PUT);
putimage(x1+500,y1+80,p,COPY_PUT);
putimage(x1+600,y1+70,p,COPY_PUT);
putimage(x1+500,y1+80,p,COPY_PUT);
putimage(x1+600,y1+70,p,COPY_PUT);
putimage(x1,y1,p,COPY_PUT);
y1=y1+20;
delay(210);
}
else
{
x1=0;
y1=50;
}
}