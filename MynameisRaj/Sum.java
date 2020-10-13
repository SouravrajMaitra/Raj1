class Sum
{
    public static void main(String args[])
    {
        int s=0;
        for(String x:args)
            s+=Integer.parseInt(x);
        System.out.println("Sum="+s);
    }
}