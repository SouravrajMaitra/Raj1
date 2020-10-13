import java.util.Scanner;

class MergeSort
{
    int n,a[];
    MergeSort(int p)
    {
        n=p;
        a=new int[n];
    }
    void input()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Elements:");
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
    }
    void Merge(int l1,int u1,int l2,int u2)
    {
        int i=l1,j=l2,k=0,b[]=new int[u2-l1+1];
        while(i<=u1 && j<=u2)
            b[k++]=(a[i]<a[j])?a[i++]:a[j++];
        while(i<=u1)
            b[k++]=a[i++];
        while(j<=u2)
            b[k++]=a[j++];
        k=l1;
        for(int x:b)
            a[k++]=x;
    }
    void MS(int l,int u)
    {
        if(l<u)
        {
            int mid=(l+u)/2;
            MS(l,mid);
            MS(mid+1,u);
            Merge(l,mid,mid+1,u);
        }
    }
    void disp()
    {
        for(int x:a)
            System.out.print(x+" ");
    }
}

class Sort1
{
    public static void main(String args[])
    {
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.print("Size:");
        n=sc.nextInt();
        MergeSort ms=new MergeSort(n);
        ms.input();
        ms.MS(0,n-1);
        System.out.println("After sorting:");
        ms.disp();
    }
}