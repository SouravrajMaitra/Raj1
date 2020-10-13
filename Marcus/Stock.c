#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "login.c"
int main()
{
    int ch;
    if(loginCheck())
        printf("Account Blocked!!!");
    else
    {
        printf("\n\nMenu:\n");
        printf("1.Product\n2.Billing\n3.Logout\n\nEnter you choice:");
        scanf("%d",&ch);
        if(ch==1)
        else if(ch==2)
        else if(ch==3)
        else
    }
    return 0;
}