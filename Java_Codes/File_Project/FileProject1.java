// COPY FILE OPERATION 

import java.io.File;
import java.util.Scanner;

class FileProject1
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        String FileName = null;
        boolean bFlag = true;
        byte brr[] = new byte[1024];

        System.out.println("Enter file name : ");
        System.out.println("Note : Use entention .txt");
        FileName = sobj.nextLine();

        File fobj = new File(FileName);

        // FILE CREATION MECHANISM
        try
        {
            if(fobj.exists())
            {
                System.out.println("Error : Can't create file already exists");
                bFlag = false;
            }
            else
            {
                fobj.createNewFile();
            }
        }
        catch(Exception eobj)
        {
            bFlag = false;
            System.out.println("Error : " + eobj);
        }
        finally
        {
            if(bFlag == true)
            {
                System.out.println("File created successfully");
            }
            else
            {
                System.out.println("Error : File creation failed");
            }
        }
    }
}