#include<stdio.h>
#include<stdlib.h>

void count(int*,int*,int);
void disp(int*,int);

int main()
{
    int T,N,i,*A,*B;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&N);
        A=(int*)calloc(N,sizeof(int));
        B=(int*)calloc(N,sizeof(int));
        B[N-1]=0;
        for(int j=0;j<N;j++)
            scanf("%d",A+j);
        count(A,B,N);
        disp(B,N);
        free(A);
        free(B);
    }
    return 0;
}

void count(int* A,int* B,int N)
{
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
            if(A[j]>A[i])
                ++B[i];
    }
}

void disp(int* A,int N)
{
    for(int i=0;i<N;i++)
        printf("%d ",A[i]);
}