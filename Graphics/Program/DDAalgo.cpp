#include<stdio.h>
#include<graphics.h>

#define ROUND(a) (int)(a+0.5)

int absolute(int x)
{
    if(x<0)
        return -x;
    else
        return x;
}

void check(int *x0,int *y0,int *x1,int *y1)
{
    int t;
    if(*x0>*y0)
    {
        t=*x0;
        *x0=*x1;
        *x1=t;
        t=*y0;
        *y0=*y1;
        *y1=t;
    }
}

void dda(int x0,int y0,int x1,int y1)
{
    int dy=y1-y0,dx=x1-x0,step,x,y;
    check(&x0,&y0,&x1,&y1);
    x=x0;
    y=y0;
    if(abs(dx)<abs(dy))
        step=dy;
    else
        step=dx;
    putpixel(ROUND(x),ROUND(y),7);
    while(x<=x1)
    {
        x+=dy/(float)step;
        y+=dx/(float)step;
        putpixel(ROUND(x),ROUND(y),7);
    }
}

int main()
{
    int gm,gd=DETECT,x[2],y[2];
    printf("Enter the coordinates:\n");
    scanf("%d%d",x,y);
    scanf("%d%d",x+1,y+1);
    initgraph(&gd,&gm,NULL);
    dda(x[0],y[0],x[1],y[1]);
    getch();
    closegraph();
    return 0;
}