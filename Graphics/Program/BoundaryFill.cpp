#include<graphics.h>

void BFill4(int x,int y,int bk_c,int n_c,int b_c)
{
    if(getpixel(x,y)!=b_c && getpixel(x,y)!=n_c)
    {
        putpixel(x,y,n_c);
        BFill4(x-1,y,bk_c,n_c,b_c);
        BFill4(x+1,y,bk_c,n_c,b_c);
        BFill4(x,y+1,bk_c,n_c,b_c);
        BFill4(x,y-1,bk_c,n_c,b_c);
    }
}

void BFill8(int x,int y,int bk_c,int n_c,int b_c)
{
    if(getpixel(x,y)!=b_c && getpixel(x,y)!=n_c)
    {
        putpixel(x,y,n_c);
        BFill8(x-1,y,bk_c,n_c,b_c);
        BFill8(x+1,y,bk_c,n_c,b_c);
        BFill8(x,y+1,bk_c,n_c,b_c);
        BFill8(x,y-1,bk_c,n_c,b_c);
        BFill8(x-1,y+1,bk_c,n_c,b_c);
        BFill8(x-1,y-1,bk_c,n_c,b_c);
        BFill8(x+1,y+1,bk_c,n_c,b_c);
        BFill8(x+1,y-1,bk_c,n_c,b_c);
    }
}

int main()
{
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    rectangle(100,50,400,200);
    delay(2000);
    BFill4(250,125,BLACK,MAGENTA,WHITE);
    //BFill4(250,125,BLACK,MAGENTA,WHITE);
    getch();
    closegraph();
    return 0;
}