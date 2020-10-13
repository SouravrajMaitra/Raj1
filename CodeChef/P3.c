#include<stdio.h>
#include<stdlib.h>

int main()
{
    int T,N;float loss,price,quantity,x;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        loss=0.0;
        scanf("%d",&N);
        for(int j=0;j<N;j++)
        {
            scanf("%f%f%f",&price,&quantity,&x);
            loss+=price*(1-(1-x/100)*(1+x/100))*quantity;
        }
        printf("%f\n",loss);
    }
    return 0;
}