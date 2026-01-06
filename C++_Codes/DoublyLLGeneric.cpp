#include<iostream>
using namespace std;

template<class T>
struct node 
{
    T data;
    struct node * next;
    struct node * prev;
};

template<class T>
class DoublyLL
{
    private:
        int iCount;
        struct node<T> * first;

    public:
        DoublyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
        void Display();
        int Count();
};

template<class T>
DoublyLL<T> :: DoublyLL()
{
    iCount = 0;
    first = NULL;
}

template<class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct node<T> * newn;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        first->prev = newn;
        newn->next = first;
        first = newn;
    }

    iCount++;
}

template<class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct node<T> * newn;
    newn = new node<T>;
    struct node<T> * temp;
    temp = NULL;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

template<class T>
void DoublyLL<T> :: InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > (iCount+1))
    {
        cout << "Invalid Position\n";
        return ;
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
        struct node<T> * temp;
        temp = NULL;
        struct node<T> * newn;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        int iCnt = 0;

        temp = first;
        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template<class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct node<T> * temp;
    temp = NULL;

    if(first == NULL)
    {
        return ;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        first->prev = NULL;

        delete temp;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteLast()
{
    struct node<T> * temp;
    temp = NULL;
    struct node<T> * target;
    target = NULL;

    if(first == NULL)
    {
        return ;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = NULL;

        delete target;
    }

    iCount--;
}

template<class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    if(pos < 1 || pos > (iCount))
    {
        cout << "Invalid Position\n";
        return ;
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
        struct node<T> * temp = NULL;
        int iCnt = 0;
        struct node<T> * target = NULL;

        temp = first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;

        delete target;

        iCount--;
    }
}

template<class T>
void DoublyLL<T> :: Display()
{
    struct node<T> * temp;
    temp = NULL;

    temp = first;

    cout << "\nNULL <=>";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    }

    cout << " NULL\n";
}

template<class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

int main()
{
    // For Integer
    printf("For Integer : \n");

    DoublyLL<int> iobj;
    int iRet = 0;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    iobj.DeleteFirst();

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    iobj.DeleteLast();

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    iobj.InsertAtPos(105, 4);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    iobj.DeleteAtPos(4);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    // For double
    printf("\n For Double : \n");

    DoublyLL<double> dobj;

    dobj.InsertFirst(51.5);
    dobj.InsertFirst(21.5);
    dobj.InsertFirst(11.5);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.InsertLast(101.5);
    dobj.InsertLast(111.5);
    dobj.InsertLast(121.5);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.InsertAtPos(105.5, 4);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.DeleteAtPos(4);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    // For character
    printf("\n For Character : \n");

    DoublyLL<char> cobj;

    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    cobj.InsertLast('D');
    cobj.InsertLast('E');
    cobj.InsertLast('F');

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    dobj.DeleteFirst();

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    cobj.DeleteLast();

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    cobj.InsertAtPos('G', 4);

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    cobj.DeleteAtPos(4);

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of Nodes are : " << iRet << "\n";

    return 0;
}