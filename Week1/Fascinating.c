#include<stdio.h>

int count(long n)
{
    int c=0;
    while(n)
    {
        ++c;
        n/=10;
    }
    return c;
}

long power(int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=10;
    return(p);
}

int check(long n)
{
    int i,a[9]={0};
    while(n)
    {
        ++a[n%10-1];
        n/=10;
    }
    for(i=1;i<=9;i++)
        if(a[i-1]!=1)
            return 0;
    return 1;
}

int main()
{
    long n,a,b,t;
    printf("Enter a number:");
    scanf("%ld",&n);
    a=n*2;
    b=n*3;
    t=(n*power(count(a))+a)*power(count(b))+b;
    if(check(t))
        printf("Fascinating number!!!");
    else
        printf("Not a fascinating number!!!");
    return 0;
}