// RENAME OPERATION

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

class FileProject8
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

        System.out.println("Enter numbers for selecting files :");

        ArrayList<String> Arr = new ArrayList<>();
        ArrayList<String> Brr = new ArrayList<>();
        String Replace = null;
        i = 0;

        while(i != -1)
        {
            System.out.println("Enter index of file : ");
            i = sobj.nextInt();

            sobj.nextLine();

            if(i != -1)
            {
                System.out.println("Enter Replace name for file : ");
                Replace = sobj.nextLine();

                Arr.add(FileName[i-1].getName());
                Brr.add(Replace);
            }
            else
            {
                break;
            }
        }

        for(i = 0; i < Arr.size(); i++)
        {
            File ffobj = new File(fobj, Arr.get(i));
            File frobj = new File(fobj, Brr.get(i));

            boolean Ret = ffobj.renameTo(frobj);

            if(Ret)
            {
                System.out.println("Original Name : " + Arr.get(i) + " ||  Replace name : " + Brr.get(i));
            }
            else
            {
                System.out.println("Error : Not Replaced");
            }
        }
    }
}