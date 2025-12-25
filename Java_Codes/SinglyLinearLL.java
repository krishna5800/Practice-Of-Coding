
class node
{
    public int data;
    public node next;
}

class SinglyLL 
{
    private node first;
    private int iCount;

    public SinglyLL() 
    {
        System.out.println("Object of SinglyLL created successfully");
        iCount = 0;
        first = null;
    }

    public void InsertFirst(int no)
    {
        node newn = new node();

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node();
        node temp = null;

        newn.data = no;
        newn.next = null;

        if(first == null)
        {
            first = newn;
        }
        else
        {
            temp = first;

            while(temp.next != null)
            {
                temp = temp.next;
            }

            temp.next = newn;
        }

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
            first = first.next;
        }

        System.gc();

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null)
        {
            return;
        }
        else if(first.next == null)
        {
            first = null;
        }
        else
        {
           temp = first;

           while(temp.next.next != null)
           {
                temp = temp.next;
           }

            temp.next = null;
        }

        System.gc();

        iCount--;
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        while(temp != null)
        {
            System.out.print("| " + temp.data + " |->");
            temp = temp.next;
        }

        System.out.println(" NULL");
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > (iCount+1))
        {
            System.out.println("Invalid Position\n");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == (iCount+1))
        {
            InsertLast(no);
        }
        else
        {
            node newn = new node();
            int iCnt = 0;
            node temp = null;

            newn.data = no;
            newn.next = null;

            temp = first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;
        }
    }

    public void DeleteAtPos(int pos)
    {
        if(pos < 1 || pos > (iCount))
        {
            System.out.println("Invalid Position\n");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == (iCount))
        {
            DeleteLast();
        }
        else
        {
            int iCnt = 0;
            node temp = null;
            node target = null;

            temp = first;

            for(iCnt = 1; iCnt < (pos-1); iCnt++)
            {
                temp = temp.next;
            }

            target = temp.next;
            temp.next = target.next;
            System.gc();

            iCount--;
        }
    }
}

class SinglyLinearLL
{
    public static void main(String A[])
    {
        SinglyLL obj = new SinglyLL();
        int iRet = 0;

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);

        obj.DeleteFirst();

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);

        obj.DeleteLast();

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);

        obj.InsertAtPos(105, 4);

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);

        obj.DeleteAtPos(4);

        obj.Display();
        iRet = obj.Count();

        System.out.println("Number of nodes are : " + iRet);
    }
}