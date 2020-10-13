#include<stdio.h>
#include<graphics.h>

void plotpt(int x,int y,int xc,int yc)
{
    putpixel(x+xc,y+yc,7);
    putpixel(y+xc,x+yc,7);
    putpixel(-x+xc,y+yc,7);
    putpixel(-y+xc,x+yc,7);
    putpixel(x+xc,-y+yc,7);
    putpixel(y+xc,-x+yc,7);
    putpixel(-x+xc,-y+yc,7);
    putpixel(-y+xc,-x+yc,7);
}

void B_Circle(int *c,int r)
{
    int p,x,y;
    x=0;y=r;
    p=1-r;
    plotpt(x,y,c[0],c[1]);
    while(!(x>y))
    {
        ++x;
        if(p<0)
            p+=2*x+1;
        else
        {
            p+=2*(x-y)+1;
            y--;
        }
        plotpt(x,y,c[0],c[1]);
    }
}

int main()
{
    int gm,gd=DETECT,r,c[2];
    printf("Enter the radius:");
    scanf("%d",&r);
    printf("Enter the center coordinates:");
    scanf("%d%d",c,c+1);
    initgraph(&gd,&gm,NULL);
    B_Circle(c,r);
    getch();
    closegraph();
    return 0;
}