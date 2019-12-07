#include <iostream>
#include <graphics.h>
#include<math.h>
using namespace std;
//2d dve funkcii
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
    int n1=20,n2=30;
    int x0=100, y0=400, Px=400, Py=300, Dx=80, Dy=50;
    double a1=-1,b1=2;
    double a2=-3,b2=0;

    double x1[20],y1[20];
    double x2[30],y2[30];

    double dx1 = (b1-a1)/(n1-1);
    double dx2 = (b2-a2)/(n2-1);

    for(int i=0;i<n1;i++)
    {
        x1[i]=a1+i*dx1;
        y1[i]=x1[i]*x1[i];
    }

    for(int i=0;i<n2;i++)
    {
        x2[i]=a2+i*dx2;
        y2[i]=cos(x2[i]);
    }


    double Xmin1, Xmax1;
    double Ymin1, Ymax1;

    double Xmin2, Xmax2;
    double Ymin2, Ymax2;

    MinMax(n1,x1,Xmin1,Xmax1);
    MinMax(n1,y1,Ymin1,Ymax1);

    MinMax(n2,x2,Xmin2,Xmax2);
    MinMax(n2,y2,Ymin2,Ymax2);

    double Sx1=(Xmax1-Xmin1)/Px;
    double Sy1=(Ymax1-Ymin1)/Py;

    double Sx2=(Xmax2-Xmin2)/Px;
    double Sy2=(Ymax2-Ymin2)/Py;

    initwindow(800 ,600);

    setcolor(14);
    Points(n1,x1,y1,x0,y0,Xmin1,Ymin1,Sx1,Sy1);

    setcolor(7);
    Points(n2,x2,y2,x0,y0,Xmin2,Ymin2,Sx2,Sy2);

    setcolor(15);
    axis(0,Px,Dx,x0,y0,Xmin2,Sx1);
    axis(1,Py,Dy,x0,y0,Ymin1,Sy2);

    getch();

}
