int sum(int a,int b)
{
    return(a+b);
}

int dif(int a,int b)
{
    return(a-b);
}

int fact(int n)
{
    int p=1;
    for(int i=1;i<=n;i++)
    p*=i;
    return(p);
}

int q(int a,int b)
{
    return((float)a/b);
}

int p(int a,int b)
{
    return(a*b);
}

int p1(int n,int k)
{
    int i,m=1;
    for(i=1;i<=k;i++)
        m*=n;
    return(m);
}