#include<stdio.h>
#include<graphics.h>

void plotpt(int x,int y,int xc,int yc,int color)
{
    putpixel(x+xc,y+yc,color);
    putpixel(y+xc,x+yc,color);
    putpixel(-x+xc,y+yc,color);
    putpixel(-y+xc,x+yc,color);
    putpixel(x+xc,-y+yc,color);
    putpixel(y+xc,-x+yc,color);
    putpixel(-x+xc,-y+yc,color);
    putpixel(-y+xc,-x+yc,color);
}

void B_Circle(int *c,int r,int color)
{
    int p,x,y;
    x=0;y=r;
    p=1-r;
    plotpt(x,y,c[0],c[1],color);
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
        plotpt(x,y,c[0],c[1],color);
    }
}

int main()
{
    int gm,gd=DETECT,r,c[2],i,color=1,limit;
    printf("Enter the radius:");
    scanf("%d",&r);
    printf("Enter the center coordinates:");
    scanf("%d%d",c,c+1);
    printf("Enter your boundary limit:");
    scanf("%d",&limit);
    initgraph(&gd,&gm,NULL);
    for(i=0;i<limit+1;i++)
    {
        B_Circle(c,r+i,color);
        if(!(i%50))
        ++color;
    }
    getch();
    closegraph();
    return 0;
}