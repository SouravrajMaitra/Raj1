import java.util.Scanner;

class Hell
{
    int n,a[];
    Hell(int p)
    {
        n=p;
        a=new int[n];
    }
    void input()
    {
        System.out.println("Elements:");
        Scanner sc=new Scanner(System.in);
        for(int i=0;i<n;i++)
            a[i]=sc.nextInt();
    }
    void check()
    {
        int s=0,flag=0;
        for(int x:a)
        {
            if(x==5)
            s+=5;
            else
            {
                if(x-s<=5)
                    s+=5;
                else
                    {
                        flag=1;
                        break;
                    }
            }
        }
        if(flag==1)
            System.out.println("No");
        else
            System.out.println("Yes");
    }
}

class Raj
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("No. of customers:");
        int n=sc.nextInt();
        Hell h=new Hell(n);
        h.input();h.check();
    }
}