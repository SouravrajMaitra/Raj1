import java.util.Scanner;

class NQueens
{
    int opsol[];
    NQueens(int size)
    {
        opsol=new int[size];
    }

    int moddif(int a,int b)
    {
        return a>b?a-b:b-a;
    }

    boolean place(int row1,int column1)
    {
        int column2;
        for(int row2=0;row2<row1;row2++)
        {
            column2=opsol[row2];
            if(column1==column2 || moddif(row1,row2)==moddif(column1,column2))
                return false;
        }
        return true;
    }

    void nqueens(int row)
    {
        for(int c=0;c<=row;c++)
        {
            if(place(row,c))
            {
                opsol[row]=c;
                if(row==opsol.length-1)
                    dispQueens();
                else
                    nqueens(row+1);
            }
        }
    }
    void dispQueens()
    {
        for(int i:opsol)
            System.out.print(i+"\t");
        System.out.println();    
    }
}

class N_Queens
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the order:");
        int size=sc.nextInt();
        NQueens nq=new NQueens(size);
        nq.nqueens(0);
    }
}