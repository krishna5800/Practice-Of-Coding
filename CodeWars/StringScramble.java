import java.util.*;

class StringScramble 
{
    String scramble(String str, int indices[]) 
    {
        char Arr[] = str.toCharArray();
        char Brr[] = str.toCharArray();
        int iCnt = 0;

        int i = 0;

        for (i = 0; i < Arr.length; i++, iCnt = 0) 
        {
            iCnt = indices[i];
            Arr[iCnt] = Brr[i];
        }

        return new String(Arr);
    }
}

class test 
{
    public static void main(String A[]) 
    {
        Scanner sobj = new Scanner(System.in);
        String Arr = null;
        String Brr = null;
        int indices[] = {0,3,1,2};

        Arr = sobj.nextLine();

        StringScramble ssobj = new StringScramble();

        Brr = ssobj.scramble(Arr, indices);

        System.out.println(Brr);
    }
}
