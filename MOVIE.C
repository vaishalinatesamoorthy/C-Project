#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<math.h>
void clip(int,int,int,int,int,int,int,int);
int round(float a)
{
return (int)a+0.5;
}
enum { TOP=0x1, BOTTOM=0x2, RIGHT=0x4, LEFT=0x8 };
//Code to draw the left leg and left hand using DDA line drawing algorithm
void line1(int x0,int y0,int xend,int yend)
{
int dx=xend-x0,dy=yend-y0,steps,k;
float xinc,yinc,x=x0,y=y0;
if(fabs(dx)>fabs(dy))
steps=fabs(dx);
else
steps=fabs(dy);
xinc=(float)dx/(float)steps;
yinc=(float)dy/(float)steps;
putpixel(round(x),round(y),RED);
	for(k=0;k<steps;k++)
	{
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),25);
	}
}
//Code to draw the face of the stick man using Bresenham’s circle drawing algorithm
 void circlemidpoint(int h,int k,int radius)
{
	int p,x,y;
	x=0;
	y=radius;
	p=3-2*radius;
	do
	{
	      if(p<0)
		{
			p+=4*x+6;
			putpixel(h+x,k+y,25);
			putpixel(y+h,x+k,25);
			putpixel(-y+h,x+k,25);
			putpixel(-x+h,y+k,25);
			putpixel(-x+h,-y+k,25);
			putpixel(-y+h,-x+k,25);
			putpixel(y+h,-x+k,25);
			putpixel(x+h,-y+k,25);
			x++;
		}
		else
		{
			p+=4*(x-y)+10;
			putpixel(h+x,k+y,25);
			putpixel(y+h,x+k,25);
			putpixel(-y+h,x+k,25);
			putpixel(-x+h,y+k,25);
			putpixel(-x+h,-y+k,25);
			putpixel(-y+h,-x+k,25);
			putpixel(y+h,-x+k,25);
			putpixel(x+h,-y+k,25);
			 x++;
			 y--;
		   }
		}while(x<=y);
}
//Code to draw the centre line, right hand and right leg using Bresenham’s line drawing algorithm
void linebres(int xa,int ya,int xb,int yb)
{
	int dx,dy,x,y,xend,yend,p;
	dx=abs(xa-xb);
	dy=abs(ya-yb);
	if(dx==0)
	p=0;
	else
	p=2*dy-dx;
	if(xa>xb)
	{
		x=xb;
		y=yb;
		xend=xa;
		yend=ya;
	}
	else
	{
	x=xa;
	y=ya;
	xend=xb;
	yend=yb;
	}
	while(x<xend || y<yend)
	{
		x=x+1;
		if(p<0)
		{
			p=p+(2*dy);
		}
		else
		{
		y+=1;
		if(dx!=0)
		{
		p=p+2*dy-2*dx;
		putpixel(x,y,25);
		}
		else
		{
		p=0;
		putpixel(xa,y,25);
		}
		}
	}
}
//main function
void main()
{
int hcen,xcen,ycen,loop_var,ccenx=50,cceny=300,st_st=ccenx+20,st_end;
int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"C:\\turboc3\\BGI");
//code to draw the stick man
while(st_st<(getmaxx()-20))
{
cleardevice();
st_end=st_st+40;
circlemidpoint(ccenx,cceny,20);
linebres(ccenx,cceny+20,ccenx,cceny+80);
linebres(ccenx,cceny+30,ccenx+20,cceny+55);
linebres(ccenx,cceny+80,ccenx+20,cceny+100);
line1(ccenx,cceny+30,ccenx-20,cceny+55);
line1(ccenx,cceny+80,ccenx-20,cceny+100);
if(st_end<=ccenx+260)
{
circlemidpoint(ccenx+200,cceny+20,10);
circlemidpoint(ccenx+200,cceny+20,30);
circlemidpoint(ccenx+500,cceny+20,10);
circlemidpoint(ccenx+500,cceny+20,30);
clip(st_st,cceny+20,st_end,cceny+20,ccenx,cceny+20,ccenx+210,cceny+25);
}
else if(st_end>=ccenx+230)
{
circlemidpoint(ccenx+500,cceny+20,10);
circlemidpoint(ccenx+500,cceny+20,30);
circlemidpoint(ccenx+500,cceny+20,50);
clip(st_st,cceny+20,st_end+40,cceny+20,ccenx+230,cceny+20,ccenx+510,cceny+25);
}
st_st+=5;
delay(80);
}
getch();
closegraph();
}
/*
void translation(int x1,int y1,int tx,int ty,int radius)
{
	int newx,newy;
	newx=x1-tx;
	newy=y1+ty;
	circle(newx,newy,radius);
	line(newx,newy,newx,newy-radius);
	//delay(1000);
       //	cleardevice();
	//Rotation of line
     //	rotation(newx,newy,radius);
}
//Rotation of line by rotation angle(theta) with respect to the reference point i.e.centre of the circle
void rotation(int xc,int yc,int radius)
{
int loop,theta=360,xr=0,yr=0;
for(loop=0;loop<3;loop++)
{
		circle(xc,yc,radius);
		xr=floor(xc+(radius*(cos(theta*3.14/180))));
		if(theta!=270)
		yr=floor(yc+(radius*(sin(theta*3.14/180))));
		else
		yr=floor(yc+(radius*(-1*sin(theta*3.14/180))));
		line(xc,yc,xr,yr);
		delay(1000);
		cleardevice();
		theta=theta-90;
}
}*/
//Cohen-Sutherland Line Clipping Algorithm
void clip(int x0, int y0,int x1,int y1,int xwmin,int ywmin,int xwmax,int ywmax)
{
	unsigned int code0,code1,codeout;
	int accept=0,done=0,x,y;
	//Calculation of code for endpoints of line
	code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
	code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
	do
	{
		if(!(code0 | code1))
		{
			accept=1;
			done=1;
		}
		else if(code0 & code1)
			done = 1;
		else
		{
			codeout=code0?code0:code1;
			if(codeout & TOP)
			{
				x=x0+(x1-x0)*(ywmax-y0)/(y1-y0);
				y=ywmax;
			}
			else if( codeout & BOTTOM)
			{
				x=x0+(x1-x0)*(ywmin-y0)/(y1-y0);
				y=ywmin;
			}
			else if ( codeout & RIGHT)
			{
				y=y0+(y1-y0)*(xwmax-x0)/(x1-x0);
				x=xwmax;
			}
			else
			{
				y=y0+(y1-y0)*(xwmin-x0)/(x1-x0);
				x=xwmin;
			}
			if(codeout==code0)
			{
				x0=x;
				y0=y;
				code0=calcode(x0,y0,xwmin,ywmin,xwmax,ywmax);
			}
			else
			{
				x1=x;
				y1=y;
				code1=calcode(x1,y1,xwmin,ywmin,xwmax,ywmax);
			}
		}
	} while(done==0);
	if(accept)
	line(x0,y0,x1,y1);
}
//Calculation of code for the endpoints of line with respect to clipping window
int calcode (int x,int y,int xwmin,int ywmin,int xwmax,int ywmax)
{
	int code =0;
	if(y> ywmax)
		code|=TOP;
	else if( y<ywmin)
		code|=BOTTOM;
	else if(x > xwmax)
		code|=RIGHT;
	else if ( x< xwmin)
		code|=LEFT;
	return(code);
}
