#include<stdio.h>

int main()
{
    int poly[100],n,i,result,x;
    printf("Enter the order:");
    scanf("%d",&n);
    printf("Enter the polynomial coefficients:");
    for(i=0;i<n+1;i++)
        scanf("%d",poly+i);
    result=poly[0];                                 //Horner's rule
    printf("Enter root:");
    scanf("%d",&x);
    for(i=1;i<n+1;i++)
        result=result*x+poly[i];
    printf("Value of the polynomial for x=%d is %d",x,result);
    return 0;
}