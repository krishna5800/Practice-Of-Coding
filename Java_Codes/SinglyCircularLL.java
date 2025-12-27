




class node
{
    public int data;
    public node next;

    // New
    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglycLL
{
    public int iCount;
    public node first;
    public node last;

    public SinglycLL() 
    {
        System.out.println("Object of SinglyCLL created successfully");
        this.iCount = 0;
        this.first = null;
        this.last = null;
    }

    public void InsertFirst(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;

        iCount++;
    }

    public void InsertLast(int no)
    {
        node newn = new node(no);

        if(first == null && last == null)
        {
            first = newn;
            last = newn;
        }
        else
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;

        iCount++;
    }

    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }

        System.gc();

        iCount--;
    }

    public void DeleteLast()
    {
        node temp = null;

        if(first == null && last == null)
        {
            return;
        }
        else if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            while(temp.next.next != first)
            {
                temp = temp.next;
            }

            last.next = null;
            last = temp;
            temp.next = null;
            last.next = first;
        }

        System.gc();

        iCount--;
    }

    public void Display()
    {
        node temp = null;
        temp = first;

        System.out.print("\n (start) ->");
        do
        {
            System.out.print("| " + temp.data + " | ->");
            temp = temp.next;
        }while(temp != first);

        System.out.print("(back to first)\n");
    }

    public int Count()
    {
        return iCount;
    }

    public void InsertAtPos(int no, int pos)
    {
        if(pos < 1 || pos > (iCount+1))
        {
            System.out.println("Invalid Position");
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
            node newn = new node(no);
            node temp = null;

            temp = first;
            int iCnt = 0;

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
            System.out.println("Invalid Position");
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
            node temp = null;

            temp = first;
            int iCnt = 0;

            for(iCnt = 1; iCnt <(pos-1); iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            System.gc();

            iCount--;
        }
    }
}

class SinglyCircularLL
{
    public static void main(String A[])
    {
        SinglycLL obj = new SinglycLL();
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