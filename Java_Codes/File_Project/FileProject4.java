// COPY FILE OPERATION

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Scanner;

class FileProject4
{
    public static void main(String A[]) throws FileNotFoundException, IOException
    {
        Scanner sobj = new Scanner(System.in);

        String DestFile = null;
        String SourceFile = null;

        boolean bFlag = true;
        
        byte buff[] = new byte[1024];

        System.out.println("Enter source file name : ");
        SourceFile = sobj.nextLine();

        System.out.println("Enter destination file name : ");
        DestFile = sobj.nextLine();

        File fdest = new File(DestFile);
        File fsour = new File(SourceFile);

        if(!(fsour.exists()))
        {
            System.out.println("Error : Source file not found");
            return;
        }

        // FILE CREATION MECHANISM
        try
        {
            if(fdest.exists())
            {
                System.out.println("Error : Can't create file already exists");
                bFlag = false;
            }
            else
            {
                fdest.createNewFile();
            }
        }
        catch(Exception eobj)
        {
            bFlag = false;
            System.out.println("Error : " + eobj.getMessage());
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
                return;
            }
        }

        // Content copy mechanism

        FileInputStream fiobj = new FileInputStream(fsour);
        FileOutputStream foobj = new FileOutputStream(fdest);

        int readBytes = 0;

        while((readBytes = fiobj.read(buff)) != -1)
        {
            foobj.write(buff, 0, readBytes);
        }

        System.out.println("File Copied Successfully");
    }
}