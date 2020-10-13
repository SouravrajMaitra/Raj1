#include<stdio.h>
#include<graphics.h>

#define ROUND(a) (int)(a+0.5)

void ellipspt(int x,int y,int xc,int yc)
{
    putpixel(x+xc,y+yc,7);
    putpixel(-x+xc,y+yc,7);
    putpixel(x+xc,-y+yc,7);
    putpixel(-x+xc,-y+yc,7);
}

void ellips(int Rx,int Ry,int xc,int yc)
{
    int Rx2,Ry2,twoRx2,twoRy2,p,px,py,x,y;
    Rx2=Rx*Rx;
    Ry2=Ry*Ry;
    twoRx2=2*Rx2;
    twoRy2=2*Ry2;
    px=0;py=twoRx2*Ry;
    x=0;y=Ry;
    ellipspt(x,y,xc,yc);
    p=ROUND(Ry2-Ry*Rx2+0.25*Rx2);
    while(px<py)
    {
        x++;
        px+=twoRy2;
        if(p<0)
            p+=Ry2+px;
        else
        {
            py-=twoRx2;
            p+=Ry2+px-py;
            --y;
        }
        ellipspt(x,y,xc,yc);
    }
    p=ROUND(Ry2*(x+0.5)*(x+0.5)+Rx2*(y-1)*(y-1)-Rx2*Ry2);
    while(y>0)
    {
        y--;
        py-=twoRx2;
        if(p>0)
            p+=Rx2-py;
        else
        {
            ++x;
            px+=twoRy2;
            p+=Rx2-py+px;
        }
        ellipspt(x,y,xc,yc);
    }
}

int main()
{
    int gm,gd=DETECT,r[2],c[2];
    printf("Enter the center coordinate:");
    scanf("%d%d",c,c+1);
    printf("Enter the radii of the ellipse:");
    scanf("%d%d",r,r+1);
    initgraph(&gd,&gm,NULL);
    ellips(r[0],r[1],c[0],c[1]);
    getch();
    closegraph();
    return 0;
}