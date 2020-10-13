import java.util.Scanner;

class Competition
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        int T=sc.nextInt();
        for(int t=0;t<T;t++)
        {
            int n=sc.nextInt();
            int inp[]=new int[n];
            for(int i=0;i<n;i++)
            inp[i]=sc.nextInt();
            check(inp);
        }           
    }
    static void check(int a[])
    {
        int i=0,j=a.length-1,motu,patlu,tm,tp;
        motu=patlu=tm=tp=0;
        while(i<j)
        {
            if(tm>(tp+2*a[j]))
            {
                ++patlu;
                tp+=2*a[j];
                --j;
            }
            else if(tp>(tm+a[i]))
            {
                ++motu;
                tm+=a[i];
                ++i;
            }
            else
            {
                ++motu;
                ++patlu;
                tm+=a[i];
                tp+=2*a[j];
                i++;--j;
            }
        }
           if(i == j){
		if(tm<=tp)
			motu++ ;
		else
			patlu++ ;
	}
            System.out.println(motu+" "+patlu);
            if(motu>patlu)
                System.out.println("Motu wins.");
            else
                System.out.println("Patlu wins.");
    }
}