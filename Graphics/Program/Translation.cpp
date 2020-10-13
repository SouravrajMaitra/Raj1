#include<graphics.h>
#include<stdio.h>

int main()
{
    int gm,gd=DETECT,x[2],y[2],t[2];
    printf("Enter the top-left and bottom-right coordinates:\n");    
    scanf("%d%d",x,y);
    scanf("%d%d",x+1,y+1);
    printf("Enter the translation vector:");
    scanf("%d%d",t,t+1);
    initgraph(&gd,&gm,NULL);
    setcolor(MAGENTA);
    rectangle(x[0],y[0],x[1],y[1]);
    setcolor(RED);
    rectangle(x[0]+t[0],y[0]+t[1],x[1]+t[0],y[1]+t[1]);
    getch();
    closegraph();
    return 0;
}