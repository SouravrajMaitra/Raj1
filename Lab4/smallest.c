#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{int t;t=*a;*a=*b;*b=t;}

int partition(int *a,int l,int u)
{
    int i=l+1,j=u,pivot=a[l];
    while(i<=j)
    {
        while(a[i]<pivot)
            ++i;
        while(a[j]>pivot)
            --j;
        if(i<j)
            swap(a+i,a+j);
    }
    swap(a,a+j);
    return(j);
}

int k(int *a,int l,int u,int key)
{
    if(l<=u)
    {
        int t=partition(a,l,u);
        if(key==t)
            return(t);
        else if(key<t)
            return(k(a,l,t-1,key));
        else
            return(k(a,t+1,u,key));
    }
    return -1;
}

int main()
{
    int n,*a,i,K1,K2;
    printf("Size:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("Elements:");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    printf("Enter K for min.:");
    scanf("%d",&K1);
    printf("Enter K for max.:");
    scanf("%d",&K2);
    printf("%d is the %d smallest element.",a[k(a,0,n-1,K1-1)],K1);
    printf("\n%d is the %d largest element.",a[k(a,0,n-1,n-K2+1)],K2);
    free(a);
    return 0;
}