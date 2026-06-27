
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

class File_Project
{
    public String DirectoryName;

    public File_Project(String DirName)
    {
        this.DirectoryName = DirName;
    }

    // chech if directory exists

    public boolean DirExist()
    {
        File fobj = new File(DirectoryName);
        boolean bFlag = false;

        if(!(fobj.exists()))
        {
            System.out.println("\nERROR : Directory Does Not Exist");
            return bFlag;
        }

        if(!(fobj.isDirectory()))
        {
            System.out.println("\nERROR : Not an directory");
            return bFlag;
        }

        return (bFlag=true);
    }

    // Display basic info about file

    public void Info()
    {
        File fobj = new File(DirectoryName);
        
        System.out.println("\nInformation about directory : ");
        System.out.println("Directory Path : " + fobj.getAbsolutePath());
        System.out.println("Read Permission : " + fobj.canRead());
        System.out.println("Write Permission : " + fobj.canWrite());
        System.out.println("Total Space : " + fobj.getTotalSpace());
        System.out.println("Hashcode : " + fobj.hashCode());
    }

    // display all files from directory

    public void Display()
    {
        File fobj = new File(DirectoryName);
        File FileList[] = fobj.listFiles();
        int i = 0;

        System.out.println("\nFiles from the directory are : ");
        i = 1;

        for(File f : FileList)
        {
            System.out.println(i + " : " + f.getName());
            i++;
        }
    }

    // copy file data from one file to another new file

    public void Copy_File(String SourceFile, String DestFile) throws FileNotFoundException, IOException
    {
        File fobj = new File(DirectoryName);

        File fsource = new File(fobj, SourceFile);
        File fdest = new File(fobj, DestFile);

        if(!(fsource.exists()))
        {
            System.out.println("\nERROR : NO SUCH SOURCE FILE IN DIRECTORY");
            return;
        }

        if(fdest.exists())
        {
            System.out.println("\nERROR : DESTINATION FILE ALREADY EXIST");
            return;
        }
        else
        {
            fdest.createNewFile();
        }

        FileInputStream fiobj = new FileInputStream(fsource);
        FileOutputStream foobj = new FileOutputStream(fdest);

        byte buff[] = new byte[1024];
        int readBytes = 0;

        while((readBytes = fiobj.read(buff))!= -1)
        {
            foobj.write(buff, 0, readBytes);
        }

        System.out.println("\nFile Data Copied Successfully\n");

        fiobj.close();
        foobj.close();
    }

    // Rename an file from directory

    public void Rename_File(String SourceFile, String NewName)
    {
        File fobj = new File(DirectoryName);

        File fsource = new File(fobj, SourceFile);
        File frename = new File(fobj, NewName);

        boolean Ret = fsource.renameTo(frename);

        if(Ret)
        {
            System.out.println("\nFile Renamaed Successfully\n");
        }
        else
        {
            System.out.println("\nERROR : FILE NOT RENAMED");
        }
    }

    // delete file function

    public void DeleteFile(String FileName)
    {
        File fobj = new File(DirectoryName);

        File fdelete = new File(fobj, FileName.trim());

        if(!(fdelete.exists()))
        {
            System.out.println("\nERROR : NO SUCH FILE IN DIRECTORY");
            return;
        }

        fdelete.delete();

        System.out.println("\nFile Deleted Successfully\n");
    }

    // zip files method

    public void zip_files() throws IOException
    {
        File fobj = new File(DirectoryName);

        ArrayList<String> Arr = new ArrayList<>();
        int i = 0;
        Scanner sobj = new Scanner(System.in);

        File FileList[] = fobj.listFiles();

        if (FileList == null || FileList.length == 0) 
        {
            System.out.println("No files found in the directory.");
            return;
        }

        Display();

        System.out.println("\nSelect files you want to zip :");
        System.out.println("Like number 1,2,3... || to stop enter -1 : \n");

        while(true)
        {
            System.out.println("Enter file number : ");
            i = sobj.nextInt();  

            if(i == -1)
            {
                break;
            }
            else if(i > 0 && i <= FileList.length)
            {
                Arr.add(FileList[i-1].getName());
            }
            else
            {
                System.out.println("Invalid selection. Try again.");
            } 
        }

        System.out.println("\nSelected files are : ");

        for(String S : Arr)
        {
            System.out.println(S);
        }

        sobj.nextLine();

        System.out.println("\nEnter zip file name : (with .zip eztension) : ");
        String ZipName = sobj.nextLine();

        File zzobj = new File(fobj, ZipName);

        try
        (
            ZipOutputStream zobj = new ZipOutputStream(new FileOutputStream(zzobj))
        )
        {
            for(String file : Arr)
            {
                File ffobj = new File(fobj, file.trim());

                try
                (
                    FileInputStream fiobj = new FileInputStream(ffobj);
                )
                {
                    ZipEntry zeobj = new ZipEntry(ffobj.getName());
                    zobj.putNextEntry(zeobj);

                    byte buff[] = new byte[1024];
                    int iRet = 0;

                    while((iRet = fiobj.read(buff)) != -1)
                    {
                        zobj.write(buff, 0, iRet);
                    }

                    zobj.closeEntry();
                }
            }
        }

        System.out.println("\nFiles Zipped Successfully\n");
    }
}

class Final
{
    public static void main(String A[]) throws IOException
    {
        Scanner sobj = new Scanner(System.in);
        boolean bRet = false;
        int iChoice = 0;
        String DirName = null;

        System.out.println("\n----- WELCOME TO DIRECTORY MANAGEMANT SYSTEM -----\n");

        System.out.println("\nEnter Directory Name To Start : \n");
        DirName = sobj.nextLine();

        File_Project fpobj = new File_Project(DirName);

        bRet = fpobj.DirExist();

        if(bRet)
        {
            while (true) 
            { 
                System.out.println("\nSelect choice and operation from below table : \n");

                System.out.println(" ---------------------------------------------------------");
                System.out.println("|    CHOICE      ||      OPERATION                        |");
                System.out.println(" ---------------------------------------------------------");
                System.out.println("|      1         ||    Get Directory Information          |");
                System.out.println("|      2         ||    Display all Files                  |");
                System.out.println("|      3         ||    Copy file                          |");
                System.out.println("|      4         ||    Rename file                        |");
                System.out.println("|      5         ||    Delete file                        |");
                System.out.println("|      6         ||    Zip file                           |");
                System.out.println("|      7         ||    Exit                               |");
                System.out.println(" ---------------------------------------------------------");

                System.out.println("\nEnter Choice : ");
                
                try
                {
                    iChoice = sobj.nextInt();
                }
                catch(InputMismatchException imeobj)
                {
                    System.out.println("Invalid input! Please enter a number.");
                    sobj.next();
                }

                switch (iChoice) 
                {
                    case 1:
                        fpobj.Info();
                        break;

                    case 2:
                        fpobj.Display();
                        break;

                    case 3:
                        String DestFile = null;
                        String SourceFile = null;

                        sobj.nextLine();

                        System.out.println("\nEnter Source file : \n");
                        SourceFile = sobj.nextLine();

                        System.out.println("\nEnter Destination file : \n");
                        DestFile = sobj.nextLine();

                        fpobj.Copy_File(SourceFile, DestFile);
                        break;

                    case 4:
                        String RenameName = null;
                        String DirFile = null;

                        sobj.nextLine();

                        System.out.println("\nEnter Source file : \n");
                        DirFile = sobj.nextLine();

                        System.out.println("\nEnter New name for file : \n");
                        RenameName = sobj.nextLine();

                        fpobj.Rename_File(DirFile, RenameName);
                        break;

                    case 5:
                        String DeleteFileName = null;

                        sobj.nextLine();

                        System.out.println("\nEnter File you want to delete : \n");
                        DeleteFileName = sobj.nextLine();

                        fpobj.DeleteFile(DeleteFileName);
                        break;

                    case 6:
                        fpobj.zip_files();
                        break;

                    case 7:
                        System.out.println("----- THANK YOU FOR VISITING APPLICATION -----");
                        break;

                    default:
                        System.out.println("\nERROR : ENTER VALID CHOICE OPTION");
                }

                if(iChoice == 7)
                {
                    break;
                }
            }
        }
        else
        {
            System.out.println("\nERROR : CHECK DIRECTORY NAME CORRECTLY");
        }
    }
}