#include<graphics.h>

void FFill4(int x,int y,int old_c,int new_c)
{
    if(getpixel(x,y)==old_c)
    {
        putpixel(x,y,new_c);
        FFill4(x-1,y,old_c,new_c);
        FFill4(x+1,y,old_c,new_c);
        FFill4(x,y+1,old_c,new_c);
        FFill4(x,y-1,old_c,new_c);
    }
}

void FFill8(int x,int y,int old_c,int new_c)
{
    if(getpixel(x,y)==old_c)
    {
        putpixel(x,y,new_c);
        FFill8(x-1,y,old_c,new_c);
        FFill8(x+1,y,old_c,new_c);
        FFill8(x,y+1,old_c,new_c);
        FFill8(x,y-1,old_c,new_c);
        FFill8(x-1,y+1,old_c,new_c);
        FFill8(x-1,y-1,old_c,new_c);
        FFill8(x+1,y+1,old_c,new_c);
        FFill8(x+1,y-1,old_c,new_c);
    }
}

int main()
{
    int gm,gd=DETECT;
    initgraph(&gd,&gm,NULL);
    rectangle(100,50,400,200);
    delay(2000);
    //FFill4(250,125,BLACK,RED);
    FFill8(250,125,BLACK,MAGENTA);
    getch();
    closegraph();
    return 0;
}