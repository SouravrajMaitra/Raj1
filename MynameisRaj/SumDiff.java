import java.util.Scanner;

class SumDiff
{
    public static void main(String args[])
    {
        System.out.print("Enter 2 numbers:");
        Scanner sc=new Scanner(System.in);
        int a=sc.nextInt(),b=sc.nextInt();
        SumDiff s=new SumDiff();
        s.summation(a,b);
        //s.difference(a,b);
    }
    void summation(int p,int q)
    {
        int carry;
        while(q!=0)
        {
            carry=p & q;
            p^=q;
            q=carry<<1;
        }
        System.out.println("Sum of two numbers:"+p);
    }
    void difference(int p,int q)
    {
        int carry;
        while(q!=0)
        {
            carry=(-p) & q;
            p^=q;
            q=carry<<1;
        }
        System.out.println("Difference of two numbers:"+p);
    }
}