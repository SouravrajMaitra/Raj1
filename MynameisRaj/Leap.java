import java.util.Scanner;

class Leap
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter a year:");
        int year=sc.nextInt();
        System.out.println((year%400==0 || year%4==0 && year%100!=0)?"Leap Year":"Not a leap year");
    }
}