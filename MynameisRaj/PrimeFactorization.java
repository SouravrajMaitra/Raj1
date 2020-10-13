import java.util.Scanner;

class PrimeFactorization
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Size:");
        int n=sc.nextInt();
        int a[]=new int[n];
        System.out.println("Elements:");
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
        for(int x:a)
            primef(x);
    }
    static void primef(int p)
    {
        System.out.print(p+"=");
        int i=2,c;
        while(p!=1)
        {
            c=0;
            while(p%i==0)
            {
                ++c;
                p/=i;
            }
            System.out.print(i+"^"+c);
            ++i;
            if(p!=1)
            System.out.print(" x ");
        }
        System.out.println();
    }
}