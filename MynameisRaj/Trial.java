import java.util.Scanner;

class Trial
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int n1;double n2;String n3;
        n1=sc.nextInt();
        n2=sc.nextDouble();
        sc.nextLine();
        n3=sc.nextLine();
        System.out.println("String:"+n3+"\nDouble:"+n2+"\nInteger:"+n1);
    }
}