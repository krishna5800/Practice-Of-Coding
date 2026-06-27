// COPY FILE OPERATION 

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

class FileProject2
{
    public static void main(String A[]) throws FileNotFoundException, IOException
    {
        Scanner sobj = new Scanner(System.in);

        String DestFile = null;
        String SourceFile = null;

        boolean bFlag = true;
        String Line = null;

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

        // used try with resource block (Otherwise it don not work)
        try         
        (
            BufferedReader reader = new BufferedReader(new FileReader(fsour.getAbsolutePath()));
            BufferedWriter writer = new BufferedWriter(new FileWriter(fdest.getAbsolutePath()));
        )
        {
            while((Line = reader.readLine()) != null)
            {
                writer.write(Line);
                writer.newLine();
            }

            System.out.println("File copied successfully!");
        }
        catch(Exception eobj)
        {
            System.out.println("Error : " + eobj.getMessage());
        }
    }
}