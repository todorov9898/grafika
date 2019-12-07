#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
//2d sinx
void MinMax(int n, double a[],double &Min, double &Max)
{
    Max = a[0]; Min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }
 }

void Points(int n,double VhodX[], double VhodY[],int x0,int y0,double MinX, double MinY,double Sx,double Sy)
{
    for (int i=0;i<n;i++)
    {
        double xp=x0+(VhodX[i]-MinX)/Sx;
        double yp=y0-(VhodY[i]-MinY)/Sy;
        circle(xp,yp,5);
        if(i==0)
            moveto(xp,yp);
        else
            lineto(xp,yp);
    }
}

void axis (int dir,int p,int D,int x0,int y0,double min, double S)
{
    switch(dir)
    {
        case 0:
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
            break;
        }
        case 1:
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
            break;
        }
    }
}

int main()
{
    int n=50;
    int x0=100, y0=500, Px=400, Py=300, Dx=80, Dy=50;
    int a=-180,b=3/4*180;
    double dx=(b-a)/(n-1);
    double VhodX[50],VhodY[50];

    for(int i=0;i<n;i++)
    {
        VhodX[i]=a+i*dx;
        VhodY[i]=sin(VhodX[i]);
    }

    double MinX, MaxX;
    double MinY, MaxY;
    MinMax(n,VhodX,MinX,MaxX);
    MinMax(n,VhodY,MinY,MaxY);
    double Sx=(MaxX-MinX)/Px;
    double Sy=(MaxY-MinY)/Py;

    initwindow(800,600);
    Points(n,VhodX,VhodY,x0,y0,MinX,MinY,Sx,Sy);
    //double xop=x0-MinX/Sx, yop=y0+MinY/Sy;

    axis(0,Px,Dx,x0,y0,MinX,Sx);
    axis(1,Py,Dy,x0,y0,MinY,Sy);
    getch();

}
