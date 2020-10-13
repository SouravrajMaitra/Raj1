#include<stdio.h>

int count(int n)
{
    int c=0;
    while(n)
    {
        ++c;
        n/=10;
    }
    return c;
}

int power(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=10;
    return(p);
}

int main()
{
    int n,t;
    printf("Enter a number:");
    scanf("%d",&n);
    t=count(n);
    if(n==n*n%power(t))
        printf("Automorphic number!!!");
    else
        printf("Not an automorphic number!!!");
    return 0;
}