#include<stdio.h>

int power(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=2;
    return(p);
}

int main()
{
    int n,k,i,t;
    printf("Enter a number:");
    scanf("%d",&n);
    for(k=2;(t=power(k))<n;k++);
    if(t-1==n)
        printf("Mersene number");
    else
        printf("Not a Mersene number");
    return 0;
}