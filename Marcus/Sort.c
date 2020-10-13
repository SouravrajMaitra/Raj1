#include<stdio.h>

void disp(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
    printf("%d ",a[i]);
}

void swap(int *a,int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void bubble(int *a,int n)
{
    int i,j,flag;
    for(i=0;i<n-1;i++)
    {
        flag=0;
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1])
            {
                flag=1;
                swap(a+j,a+j+1);
            }
        if(!flag)
            break;
    }
}

void selection(int *a,int n)
{
    int i,j,small;
    for(i=0;i<n-1;i++)
    {
        small=i;
        for(j=i+1;j<n;j++)
            if(a[small]>a[j])
                small=j;
        if(small!=i)
            swap(a+i,a+small);
    }
}

void insertion(int *a,int n)
{
    int i,j,k,m;
    for(i=1;i<n;i++)
    {
        k=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>k)
                a[j+1]=a[j];
            else 
                break;
        }
        if(j!=i-1)
            a[j+1]=k;
    }
}

int main()
{
    int a[100],n,i;
    printf("Size:");
    scanf("%d",&n);
    printf("Elements:");
    for(i=0;i<n;i++)
    scanf("%d",a+i);
    //bubble(a,n);
    selection(a,n);
    //insertion(a,n);
    printf("Elements after sorting:\n");
    disp(a,n);
    return 0;
}