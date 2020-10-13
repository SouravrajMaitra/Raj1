#include<stdio.h>
#include "Student1.c"

int main()
{
    int t;long long roll;
    while((t=menu())!=7)
    {
        switch(t)
        {
            case 1:insert();
                   break;
            case 2:delete();
                   break;
            case 3:printf("\n\nEnter Roll number:");
                   scanf("%lld",&roll);
                   search(roll);
                   break;
            case 4:sort();
                   break;
            case 5:if(!(empty()))
                   display();
                   else
                   printf("\nFile is empty!!!");
                   break;
            case 6:update();
                   break;
            default:printf("\nWrong choice!!!");
        }
    }
    return 0;
}