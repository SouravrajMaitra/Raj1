#include<stdio.h>
#include "CopyCat.c"


int menu()
{
    int ch;
    printf("\n\t\t\t\t\tMenu:");
    printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.SEARCH\n\t4.DELETE\n\t5.UPDATE\n\t6.SORT\n\t7.EXIT");
    scanf("%d",&ch);
    printf("----------------------------------------------------------------------------------------------------------");
}

int main()
{
    int t;
    while(1)
    {
       t=menu();

       if(t>=7)
              break;
        switch(t)
        {
            case 1://insert();
                   break;
            case 4:deletefile();
                   break;
            case 3:search();
                   break;
            case 6:sort();
                   break;
            case 2:if(empty())
                   disp();
                   else
                   printf("File is empty!!!");
                   break;
            case 5:update();
                   break;
            default:printf("Wrong choice!!!");
        }
    }
    return 0;
}