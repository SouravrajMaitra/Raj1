#include<stdio.h>
#include<stdlib.h>
int linear(int *a,int n,int s)
{
    int i;
    for(i=0;i<n;i++)
    if(s==a[i])
    {
        return(i+1);
        break;
    }
    return 0;
}

int main()
{
    int *a,i,n,s,t;
    printf("Size:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter the search item:");
    scanf("%d",&s);
    if(t=linear(a,n,s))
        printf("Element found at position %d.",t);
    else
        printf("Element not found!!!");
    free(a);
    return 0;
}