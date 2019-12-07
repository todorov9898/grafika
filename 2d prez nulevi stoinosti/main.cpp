#include <iostream>
#include <graphics.h>
using namespace std;
//2d prez nulevi stoinosti
void MinMax(int n, double a[],double &Min, double &Max)
{
    Max = a[0]; Min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }
 }

void axis (int dir,int p,int D,int x0,int y0,double min, double S)
{
    if(dir == 0)
    {
        line(x0,y0,x0+p,y0);
        int ip=p/D;
        settextjustify(1,2);

        for(int i=1;i<ip;i++)
        {
            line(x0+i*D,y0,x0+i*D,y0+3);
            char num[10];
            float value=min+i*D*S;
            gcvt(value,6,num);
            outtextxy(x0+i*D,y0+3,num);
        }
    }
    else
    {
        line(x0,y0,x0,y0-p);
        int jp=p/D;
        settextjustify(2,1);

        for(int i=1;i<jp;i++)
        {
            line(x0,y0-i*D,x0-3,y0-i*D);
            char num[10];
            float value=min+i*D*S;
            gcvt(value,6,num);
            outtextxy(x0-3,y0-i*D,num);
        }
    }
}

int main()
{
    int n=8;
    double VhodX[8]={-1.4,-0.5,1.9,2.4,2.8,3.4,4.1,5};
    double VhodY[8]={-1.6,-0.9,2.3,2.7,3.6,4.2,4.3,4.7};
    int x0=200;
    int y0=450, Px=500, Py=400, Dx=50, Dy=40;

    double MinX, MaxX;
    double MinY, MaxY;
    MinMax(n,VhodX,MinX,MaxX);
    MinMax(n,VhodY,MinY,MaxY);
    double Sx=(MaxX-MinX)/Px;
    double Sy=(MaxY-MinY)/Py;

    initwindow(800,600);

    for (int i=0;i<n;i++)
    {
        double xp=x0+(VhodX[i]-MinX)/Sx;
        double yp=y0-(VhodY[i]-MinY)/Sy;
        circle(xp,yp,5);
    }

    double xop=x0-MinX/Sx;
    double yop=y0+MinY/Sy;

    axis(0,Px,Dx,x0,yop,MinX,Sx);
    axis(1,Py,Dy,xop,y0,MinY,Sy);
    getch();
}
