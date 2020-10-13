#include<stdio.h>

int prime(int n)
{
    int i;
    for(i=2;i<n;i++)
        if(!(n%i))
            return 0;
    return 1;
}

int check(int n)
{
    int i,a[]={2,3,5};
    for(i=0;i<3;i++)
    {
        if(a[i]==n)
            return 1;
    }
    return 0;
}

int main()
{
    int i,n,flag=0;
    printf("Enter number:");
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        if(!(n%i) && prime(i))
        {
            if(!(check(i)))
            {
                flag=0;
                break;
            }
            flag=1;
        }
    }
    if(flag)
        printf("Ugly number!!!");
    else
        printf("Not an ugly number!!!");
    return 0;
}