#include<stdio.h>
#include<stdlib.h>

int main()
{
    int N,*A,Q,*t,T,*q,max=-111;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        scanf("%d %d",&N,&Q);
        A=(int*)calloc(N,sizeof(int));
        q=(int*)calloc(Q,sizeof(int));;
        t=(int*)calloc(N,sizeof(int));
        for(int j=0;j<N;j++)
        {
            scanf("%d",A+j);
            if(max<A[j])
                max=A[j];
            t[j]=max;
        }
        for(int j=0;j<Q;j++)
            scanf("%d",q+j);
        for(int j=0;j<Q;j++)
            printf("%d\n",t[q[j]-1]);    
        free(A);
        free(q);
        free(t);
    }
    
    return 0;
}