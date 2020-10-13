#include<stdio.h>

int pro(int k,int n)
{
    int i,p=1;
    for(i=1;i<=n;i++)
        p*=k;
    return(p);
}

int main()
{
    int poly[100],n,i,result=0,x;
    printf("Enter the order:");
    scanf("%d",&n);
    printf("Enter the polynomial coefficients:");
    for(i=0;i<n+1;i++)
        scanf("%d",poly+i);
    printf("Enter root:");
    scanf("%d",&x);
    for(i=0;i<n+1;i++)                                          //Traditional rule
        result+=poly[i]*pro(x,n-i);
    printf("Value of the polynomial for x=%d is %d",x,result);
    return 0;
}