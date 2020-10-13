//--------------------------------Shearing--------------------------------
//Souravraj Maitra, 13, B1

#include<stdio.h>
#include<graphics.h>

void sh_x(int *c,int shx)       //X-shear
{
    for(int i=0;i<3;i++)
        c[i*2]+=shx*c[i*2+1];
}

void sh_y(int *c,int shy)       //Y-shear
{
    for(int i=0;i<3;i++)
        c[i*2+1]+=shy*c[i*2];
}

void shearing(int *c,int *sv)   //Both X and Y shear
{
    sh_x(c,sv[0]);
    sh_y(c,sv[1]);
}

int main()
{
    int gm,gd=DETECT,coordinates[8],i,shear_v[2];

    printf("Enter the coordinates:\n");
    for(i=0;i<3;i++)
        scanf("%d%d",coordinates+i*2,coordinates+i*2+1);
    coordinates[i*2]=coordinates[0];coordinates[i*2+1]=coordinates[1];

    printf("Enter the shear vector:");
    scanf("%d%d",shear_v,shear_v+1);
    
    initgraph(&gd,&gm,NULL);
    drawpoly(4,coordinates);                                        //Triangle before shearing
    shearing(coordinates,shear_v);
    coordinates[i*2]=coordinates[0];coordinates[i*2+1]=coordinates[1];
    drawpoly(4,coordinates);                                          //Triangle after shearing
    getch();
    closegraph();
    return 0;
}