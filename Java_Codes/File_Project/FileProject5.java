// COPY ZIP OPERATION

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

class FileProject5
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);

        String Directory_Name = null;

        System.out.println("Enter Directory Name : ");
        Directory_Name = sobj.nextLine();

        File fobj = new File(Directory_Name);

        if(!(fobj.exists()))
        {
            System.out.println("Error : Directory Does Not Exist");
            return;
        }

        if(!(fobj.isDirectory()))
        {
            System.out.println("Error : Not an directory");
            return;
        }

        File FileName[] = fobj.listFiles();
        int i = 1;

        System.out.println("All Files from directory : ");

        for(File f : FileName)
        {
            System.out.println(i + " : " + f.getName());
            i++;
        }

        System.out.println("Enter files you want to ZIP : " + "Like 1,2,...");

        ArrayList<String> Arr = new ArrayList<>();

        while(i != -1)
        {
            System.out.println("Enter number :" + " Or enter '-1' ");
            i = sobj.nextInt();

            if(i != -1 & i <= (FileName.length + 1))
            {
                Arr.add(FileName[i-1].getName());
            }
            else
            {
                break;
            }
        }

        System.out.println("Selected files are : ");

        for(String S : Arr)
        {
            System.out.println(S);
        }
    }
}