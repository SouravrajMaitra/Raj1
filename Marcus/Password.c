#include<stdio.h>
#include<conio.h>

int main()
{
    char name[100]={'\0'},i=0;
    while(1)
    {
        name[i]=getch();
        if(name[i]=='\r')
            break;
        else
            printf("*");
            ++i;
    }
    fflush(stdin);
    printf("\nYou entered %s",name);
    return 0;
}