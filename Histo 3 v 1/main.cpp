#include <iostream>
#include<graphics.h>
#include<string>
using namespace std;
//histo 3v1
void MinMax(int n, double a[],double &Min, double &Max)
{
    Max = a[0]; Min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }
 }

void Histo(int dir,int x0, int y0,double s,int ds,int dc,int n,double a[],double b[],double c[])
{
    if(dir==0)
        for(int i=0;i<n;i++)
        {
            setfillstyle(11,2+i);
            bar(x0+(i+1)*(ds+dc)-dc,y0-a[i]/s,x0+(i+1)*(ds+dc),y0);

            setfillstyle(11,3+i);
            bar(x0+(i+1)*(ds+dc)-dc,y0-a[i]/s-b[i]/s,x0+(i+1)*(ds+dc),y0-a[i]/s);

            setfillstyle(11,4+i);
            bar(x0+(i+1)*(ds+dc)-dc,y0-a[i]/s-b[i]/s-c[i]/s,x0+(i+1)*(ds+dc),y0-a[i]/s-b[i]/s);
        }
    if(dir==1)
        for(int i=0;i<n;i++)
        {
            setfillstyle(1,3+i);
            bar(x0,y0-(i+1)*(ds+dc),x0+a[i]/s,y0-(i+1)*(ds+dc)+dc);

            setfillstyle(1,5+i);
            bar(x0+a[i]/s,y0-(i+1)*(ds+dc),x0+a[i]/s+b[i]/s,y0-(i+1)*(ds+dc)+dc);

            setfillstyle(1,7+i);
            bar(x0+a[i]/s+b[i]/s,y0-(i+1)*(ds+dc),x0+a[i]/s+b[i]/s+c[i]/s,y0-(i+1)*(ds+dc)+dc);
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

  int n=2;
  double a[2]={0.3,1.1};
  double b[2]={0.5,1.3};
  double c[2]={0.9,1.8};
  int x0=100,y0=600, p=500, ds=40, dc=40;
  double Sum[2];

  for(int i=0;i<n;i++)
  {
      Sum[i]=a[i]+b[i]+c[i];
  }

  double maxSum=Sum[0];
  if(Sum[1]>Sum[0])
    maxSum=Sum[1];

  double s=maxSum/p;

initwindow(800,700);


axis(1,p,dc,x0,y0,0,s);
//axis(0,p,dc,x0,y0,0,s);

Histo(0,x0,y0,s,ds,dc,n,a,b,c);


getch();

}
