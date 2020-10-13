#include<stdio.h>

int main()
{
    int k=5;
    int *p=&k;
    int **m=&p;
    printf("%d%d%d\n",k,*p,**p);
    return 0;
}