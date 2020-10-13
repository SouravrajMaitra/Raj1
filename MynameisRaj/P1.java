import java.util.Scanner;

class P
{
    private int s=0;
    private long p=1;
    int add(int ...v)      //with return type, with argument
    {
        for(int x:v)
            s+=x;
        return s;
    }
    long product(int ...v)
    {
        for(int x:v)
            p*=x;
        return p;
    }
    void displays()         //without return type, without argument
    {
        System.out.println("Sum="+s);
    }
    void displayp()
    {
        System.out.println("Product="+p);
    }
}

class P1
{
    public static void main(String args[])  //without return type, with argument
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("How many no. of numbers you want to enter?");
        int n=sc.nextInt();
        int k[]=new int[n];
        System.out.println("Enter the no.:");
        for(int i=0;i<k.length;i++)
            k[i]=sc.nextInt();
        P l=new P();
        l.add(k);
        l.product(k);
        l.displays();
        l.displayp();
    }
}