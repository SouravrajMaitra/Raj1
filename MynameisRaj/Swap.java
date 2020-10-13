import java.util.Scanner;
class Swap
{
    public static void main(String args[])
    {
        int a,b;
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter 2 numbers:");
        a=sc.nextInt();
        b=sc.nextInt();
        System.out.println("a="+a+"\tb="+b);
        a=a^b;
        b=a^b;
        a=a^b;
        System.out.println("a="+a+"\tb="+b);
        sc.close();
    }
}