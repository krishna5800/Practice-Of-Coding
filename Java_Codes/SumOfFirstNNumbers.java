import java.util.Scanner;

class SumOfFirstNNumbersX
{
    public static int i = 0;

    public int SumOperation(int n)
    {
        if(n > 0)
        {
            n--;
            SumOperation(n);
            i = i + n + 1;
        }

        return i;
    }
}

class SumOfFirstNNumbers
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        int n = 0;

        System.out.println("Enter Number : ");
        n = sobj.nextInt();

        SumOfFirstNNumbersX ssobj = new SumOfFirstNNumbersX();

        int Ret = ssobj.SumOperation(n);

        System.out.println(Ret);
    }
}