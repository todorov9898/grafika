#include <iostream>
#include<graphics.h>
#include<string>
using namespace std;
//histo 2 neshta
void MinMax(int n, double a[],double &Min, double &Max)
{
    Max = a[0]; Min = a[0];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > Max) Max = a[i];
        if (a[i] < Min) Min = a[i];
    }
 }

void Histo(int dir,int x0, int y0,double a[],double b[],double s,int ds,int dc,double amin,int n)
{
    if(dir==0)
        for(int i=0;i<n;i++)
    {
        setfillstyle(3,3+i);
         bar(x0+(i+1)*(ds+dc)-dc,y0-a[i]/s,x0+(i+1)*(dc+ds),y0);
         setfillstyle(1,3+i);
         bar(x0+(i+1)*(ds+dc)-dc,y0+b[i]/s,x0+(i+1)*(dc+ds),y0);
    }
    if(dir==1)
        for(int i=0;i<n;i++)
    {
        setfillstyle(3,3+i);
        bar(x0,y0-(i+1)*(ds+dc),x0+a[i]/s,y0-(i+1)*(ds+dc)+dc);
                 setfillstyle(1,3+i);
         bar(x0,y0-(i+1)*(ds+dc),x0-b[i]/s,y0-(i+1)*(ds+dc)+dc);
    }
}

int main()
{

  int n=6;
  double a[6]={0.3,1.1,0.5,0.9,0.7,1.2};
  double b[6]={0.6,0.4,0.5,0.9,0.8,0.1};

  char char1[6][10]={"hrana","transport","stoki","kola","tok","voda"};
  int x0=100,y0=600, p=50, Ds=40, Dc=40;


  double amin, amax;
  double bmin, bmax;
  MinMax(n,a,amin,amax);
  MinMax(n,b,bmin,bmax);
  cout<<amax<<" "<<bmax;
  if(amin>0) amin=0;
  if(amax<0) amax=0;
  if(bmin>0) bmin=0;
  if(bmax<0) bmax=0;
  double S=(amax-bmax)/p;


  double yop=y0-(bmax/S);
  double xop=x0+(bmax/S);

initwindow(800,700);
Histo(1,xop,y0,a,b,S,Ds,Dc,amin,n);
getch();

}
