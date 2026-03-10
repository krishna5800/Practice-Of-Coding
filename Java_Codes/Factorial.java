import java.util.Scanner;

class FactorialX
{
    public static long i = 1;

    public long CalculateFactorial(int n)
    {
        if(n > 0)
        {
            n--;
            CalculateFactorial(n);
            i = i* (n+1);
        }

        return i;
    }
}

class Factorial
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        int n = 0;
        long Ret = 0;

        System.out.println("Enter Number : ");
        n = sobj.nextInt();

        FactorialX fobj = new FactorialX();

        Ret = fobj.CalculateFactorial(n);

        System.out.println(Ret);
    }
}