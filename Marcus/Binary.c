#include<stdio.h>
#include<stdlib.h>

int binary(int *a,int l,int u,int key)
{
    int m=(l+u)/2;
    if(l<=u)
    {
        if(a[m]==key)
            return(m+1);
        else if(key<a[m])
            return(binary(a,l,m-1,key));
        else if(key>a[m])
            return(binary(a,m+1,u,key));
    }
    return 0;
}

int main()
{
    int i,n,*a,t,s;
    printf("Size:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter the search item:");
    scanf("%d",&s);
    if(t=binary(a,0,n-1,s))
        printf("Element found at position %d.",t);
    else
        printf("Element not found!!!");
    free(a);
    return 0;
}