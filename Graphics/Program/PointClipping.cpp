//SOURAVRAJ MAITRA,13,B1
//POINT CLIPPING

#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>

void clip(int **p,int n,int Xmax,int Ymax,int Xmin,int Ymin)
{
    rectangle(Xmin,Ymin,Xmax,Ymax);
    for(int i=0;i<n;i++)
    {
        if((p[i][0]>=Xmin) && (p[i][0]<=Xmax))
        {
            if((p[i][1]>=Ymin) && (p[i][1]<=Ymax))
                putpixel(p[i][0],p[i][1],YELLOW);
        }
    }
}

void nonclip(int **p,int n,int Xmax,int Ymax,int Xmin,int Ymin)
{
    rectangle(Xmin,Ymin,Xmax,Ymax);
    for(int i=0;i<n;i++)
        putpixel(p[i][0],p[i][1],YELLOW);  
}

int main()
{
    int gm,gd=DETECT,max[2],min[2],**p,n;
    
    printf("Enter the max coordinates:");
    scanf("%d%d",max,max+1);
    printf("Enter the min coordinates:");
    scanf("%d%d",min,min+1);
    printf("Enter the no. of points you want to enter:");
    scanf("%d",&n);
    
    p=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<n;i++)
        p[i]=(int*)calloc(2,sizeof(int));
    
    printf("Enter the points:\n");
    for(int i=0;i<n;i++)
        scanf("%d%d",p[i],p[i]+1);
    
    initgraph(&gd,&gm,NULL);
    nonclip(p,n,max[0],max[1],min[0],min[1]);
    initgraph(&gd,&gm,NULL);
    clip(p,n,max[0],max[1],min[0],min[1]);
    getch();
    closegraph();
    for(int i=0;i<n;i++)
        free(p[i]);
    return 0;
}