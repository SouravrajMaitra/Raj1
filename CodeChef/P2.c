#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T,N,P,*A,CW,H;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        CW=0;H=0;
        scanf("%d %d",&N,&P);
        A=(int*)calloc(N,sizeof(int));
        for(int j=0;j<N;j++)
        {
            scanf("%d",A+j);
            if(P/2<=A[j])
                ++CW;
            else if(P/10>=A[j])
                ++H;
        }
        if(CW==1 && H==2)
            printf("yes\n");
        else
            printf("no\n");
        free(A);
    }
    return 0;
}