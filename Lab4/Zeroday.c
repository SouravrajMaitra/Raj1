#include<stdio.h>
#include<stdlib.h>

void z(int *a,int n)
{
    int i,flag=1;
    for(i=0;i<n;i++)
        {
            if(a[i]==0)
                printf("0 ");
        }
}

void nz(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]!=0)
            printf("%d ",a[i]);
}

int main()
{
    int n,*a,i,j,p;
    printf("Size:");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    printf("Elements:");
    for(i=0;i<n;i++)
        scanf("%d",a+i);
    z(a,n);nz(a,n);
    free(a);
    return 0;
}