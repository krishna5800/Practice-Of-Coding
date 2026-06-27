// DELETE OPERATION

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

class FileProject7
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

        System.out.println("Enter number of files you want to delete : ");
        
        ArrayList <String> Arr = new ArrayList<>();
        i = 0;

        while(i != -1)
        {
            System.out.println("Enter the number : " + " OR Enter -1 :");
            i = sobj.nextInt();

            if(i == -1)
            {
                break;
            }

            if(i > FileName.length)
            {
                System.out.println("Error : No such file index");
                break;
            }

            Arr.add(FileName[i-1].getName());
        }

        System.out.println("Selected Files are : ");


        for(String f : Arr)
        {
            System.out.println(f);
        }

        for(String f : Arr)
        {
            File ffobj = new File(fobj, f.trim());
            ffobj.delete();
        }

        System.out.println("Files Deleted Successfully");

    }
}