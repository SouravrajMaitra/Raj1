#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void disp(int *a,int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}

int sum(int *a,int l,int u)
{
    int i,s=0;
    for(i=l;i<=u;i++)
        s+=a[i];
    return s;
}

int Balance(int *a,int l,int u)
{
    int lw,rw,mid=(l+u)/2,sz=u-l+1;
    if(!(sz%2))
    {
        if(sz==2)
        {
            return((a[l]<a[u])?l:u);
        }
        lw=sum(a,l,mid);
        rw=sum(a,mid+1,u);
        if(lw<rw)
            return(Balance(a,l,mid));
        else
            return(Balance(a,mid+1,u));
    }
    else
    {
        lw=sum(a,l,mid-1);
        rw=sum(a,mid+1,u);
        if(lw==rw)
            return(mid);
        else if(lw<rw)
            return(Balance(a,l,mid-1));
        else
            return(Balance(a,mid+1,u));
    }
}

int main()
{

    int i,wt,n,wt1,f,*a,k;
    /*
    n->no. of coins
    i->index
    wt->weight of the original coin
    wt1->weight of the fake coin
    f->index of the fake coin
    */
    printf("Enter the no. of coins:");
    scanf("%d",&n);
    for(k=1;k<6;k++)
    {
         printf("\nEnter the weight of the original coin:");
    scanf("%d",&wt);
    srand(time(0));
    f=rand()%n;
    wt1=rand()%wt;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        if(i!=f)
            a[i]=wt;
    }
    a[f]=wt1;
    disp(a,n);
    printf("\nIndex of the fake coin:%d",Balance(a,0,n-1));
    free(a);
    }
}