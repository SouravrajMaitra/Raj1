import java.util.Scanner;

class Largest
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter 3 values:");
        int a=sc.nextInt(),b=sc.nextInt(),c=sc.nextInt();
        System.out.println("Largest of 3 is:"+((a>b && a>c)?a:((b>a && b>c)?b:c)));
    }
}