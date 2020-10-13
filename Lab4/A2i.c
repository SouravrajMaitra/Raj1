#include<stdio.h>
#include<stdlib.h>

int max,min;

void maxmin(int *a,int l,int u)
{
    int mid,max1,min1;
    if(l==u)
        max=min=a[l];
    else if(u-l==0)
    {
        if(a[l]<a[u])
        {
            min=a[l];
            max=a[u];
        }
        else if(a[l]>a[u])
        {
            min=a[u];
            max=a[l];
        }
    }
    else
    {
        mid=(l+u)/2;
        maxmin(a,l,mid);
        max1=max;min1=min;
        maxmin(a,mid+1,u);
        if(max<max1)
            max=max1;
        if(min>min1)
            min=min1;
    }
}

int main()
{
    int i,n,*a;
    printf("Size:");
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    printf("Elements:");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    maxmin(a,0,n-1);
    printf("Max. element:%d\nMin. element:%d",max,min);  
    free(a);  
    return 0;
}