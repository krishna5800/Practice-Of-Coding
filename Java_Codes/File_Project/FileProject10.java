// List all files in a folder

import java.io.File;
import java.util.Scanner;

class FileProject10
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
    }
}