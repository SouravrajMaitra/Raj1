import java.util.Scanner;

class Factorial
{
    public static void main(String args[])
    {
        for(String x:args)
            System.out.println(x+"!="+factorial(Integer.parseInt(x)));
    }
    static int factorial(int n)
    {
        if(n==1 || n==0)
            return 1;
        return n*factorial(n-1);
    }
}