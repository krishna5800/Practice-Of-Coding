import java.util.Scanner;

class Test
{
    public static void main(String Arr[])
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;
        int iCount = 1;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        System.out.println("");

        for(int i = 1; i <= iNo && iCount <= iNo; i++)
        {
            for(int j = 1; j <= 3 && iCount <= iNo; j++)
            {
                System.out.print("* ");
                iCount++;
            }

            for(int k = 1; k <= 3 && iCount <= iNo; k++)
            {
                System.out.print("# ");
                iCount++;
            }
        }

    }
}