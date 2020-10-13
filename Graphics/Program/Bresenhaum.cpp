#include<stdio.h>
#include<graphics.h>

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

void bresenhaum(int x0,int y0,int x1,int y1)
{
    check(&x0,&y0,&x1,&y1);
    int dy=y1-y0,dx=x1-x0,inc_1=2*dy,inc_2=2*(dy-dx),p=2*dy-dx,x,y;
    x=x0,y=y0;
    putpixel(x,y,7);
    while(!(x>x1))
    {
        x++;
        if(p<0)
            p+=inc_1;
        else
        {
            p+=inc_2;
            ++y;
        }
        putpixel(x,y,7);
    }
}

int main()
{
    int gm,gd=DETECT,x[2],y[2];
    printf("Enter the 2 coordinates:\n");
    scanf("%d%d",x,y);
    scanf("%d%d",x+1,y+1);
    initgraph(&gd,&gm,NULL);
    bresenhaum(x[0],y[0],x[1],y[1]);
    getch();
    closegraph();
    return 0;
}