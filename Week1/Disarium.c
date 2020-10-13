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

int power(int k,int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=k;
    return(p);
}

int main()
{
    int n,s=0,p,t;
    printf("Enter the number:");
    scanf("%d",&n);
    p=n;
    t=count(n);
    while(n)
    {
        s+=power(n%10,t--);
        n/=10;
    }
    if(p==s)
        printf("Disarium number!!!");
    else
        printf("Not a disarium number!!!");
    return 0;
}