#include <iostream>
#include <graphics.h>
#include <dos.h>
#include <math.h>

using namespace std;

int main()
{
    int xc = 100, yc = 150, r = 50;
    initwindow(600,600,"Caitlyn Jenner");

    for (int i = 0; i < (getmaxx()/3); i++)
    {
        delay(5);
        setcolor(0);
        circle(xc-1,yc,r);
        setcolor(15);
        xc++;
        circle(xc,yc,r);
    }

    int xf, yf;
    xf = xc;
    yf = yc - r;
    double ny = r;

    for (int i = 0; i < 5; i++)
    {
        delay(300);
        ny = ny*1.3;
        circle(xf, yf + ny, ny);
    }

    delay(500);
    setfillstyle(0, 0);
    bar(0, 0, getmaxx(), getmaxy());
    circle(xc, yc, r);
    circle(xc, yf + ny, ny);
    int xg = xc, yg = yf + ny, rg = ny;
    setcolor(0);
    circle(xc, yc, r);

    for(int i = 0; i <= 360; i++)
    {
        int x, y;
        x = xg + (xc - xg) * cos(i* 3.14 / 180) - (yc - yg) * sin(i * 3.14 / 180);
        y = yg + (yc - yg) * cos(i* 3.14 / 180) + (xc - xg) * sin(i * 3.14 / 180);
        delay(40);
        int oldx = xg + (xc - xg)*cos((i+1) * 3.14 / 180) - (yc -yg)*sin((i+1) * 3.14 / 180);
		int oldy = yg + (xc - xg)*sin((i+1) * 3.14 / 180) + (yc -yg)*cos((i+1) * 3.14 / 180);
		setcolor(0);
		circle(x, y, r-1);
		setcolor(15);
		circle(oldx, oldy, r-1);
		circle(xc, yf + ny, ny+1);
    }

    getch();
    return 0;
}
