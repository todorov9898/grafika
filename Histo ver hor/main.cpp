#include <iostream>
#include<graphics.h>
#include<string>
using namespace std;
//histo ver hor
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

void taxis (int dir,int x0,int y0,int Ds,int Dc,int n, char a[][10] ,int p)
{
    if(dir == 0)
    {
        line(x0,y0,x0+n*(Ds+Dc),y0);
        for(int i=1;i<=n;i++)
        {
            settextjustify(1,2);
            outtextxy((x0+i*(Ds+Dc)-Ds/2),y0,a[i-1]);
        }
    }
    else
    {
        line(x0,y0,x0,y0-n*(Ds+Dc));
        for(int i=1;i<=n;i++)
        {
            settextjustify(2,1);
            outtextxy(x0,y0-i*(Ds+Dc)+Ds/2,a[i-1]);
        }
    }
}


void Histo(int dir,int x0, int y0,double a[],double s,int ds,int dc,double amin,int n)
{
    if(dir==0)
        for(int i=0;i<n;i++)
        {
            setfillstyle(1,3+i);
            bar(x0+(ds+dc)*(i+1)-dc,y0-a[i]/s,x0+(ds+dc)*(i+1),y0);
        }
    else
        for(int i=0;i<n;i++)
        {
            setfillstyle(11,3+i);
            bar(x0,y0-(ds+dc)*(i+1),x0+a[i]/s,y0-(ds+dc)*(i+1)+dc);
        }
}

int main()
{

  int n=6;
  double VhodX[6]={-0.3,1.1,3.5,-4.9,2.5,3};

  char char1[6][10]={"hrana","transport","stoki","kola","tok","voda"};
  int x0=100,y0=600, p=500, Ds=40, Dc=40;


  double amin, amax;
  MinMax(n,VhodX,amin,amax);
  if(amin>0) amin=0;
  if(amax<0) amax=0;
  double S=(amax-amin)/p;


  double yop=y0+amin/S;
  double xop=x0-amin/S;

initwindow(800,700);

line(x0,yop,x0+n*(Ds+Dc),yop);
Histo(0,x0,yop,VhodX,S,Ds,Dc,amin,n);
axis(1,p,Dc,x0,y0,amin,S);
taxis(0,x0,y0,Ds,Dc,n,char1,p);
getch();

}
