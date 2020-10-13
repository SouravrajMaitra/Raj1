#include<stdio.h>
#include<graphics.h>

void reflection(int *coordinates)
{
    int i;
    for(i=0;i<3;i++)
        coordinates[2*i]-=400;
    coordinates[2*i]=coordinates[0];
}

int main()
{
    int gm,gd=DETECT,coordinates[8],i;
    printf("Enter the coordinates:\n");
    for(i=0;i<3;i++)
        scanf("%d%d",coordinates+i*2,coordinates+i*2+1);
    coordinates[2*i]=coordinates[0];coordinates[2*i+1]=coordinates[1];
    initgraph(&gd,&gm,NULL);
    drawpoly(4,coordinates);
    reflection(coordinates);
    drawpoly(4,coordinates);
    getch();
    closegraph();
    return 0;
}