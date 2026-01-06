#include<iostream>
using namespace std;

template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode * next;
    struct DoublyCLLnode * prev ;
};

template<class T>
class DoublyCLL
{
    private:
        int iCount;
        struct DoublyCLLnode<T>* first;
        struct DoublyCLLnode<T>* last;

    public:
        DoublyCLL();
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
DoublyCLL<T> :: DoublyCLL()
{
    iCount = 0;
    first = NULL;
    last = NULL;
}

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;
    newn = new DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no, int pos)
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
        struct DoublyCLLnode<T> * newn = NULL;
        newn = new DoublyCLLnode<T>;

        struct DoublyCLLnode<T> * temp = NULL;
        int iCnt = 0;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

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
void DoublyCLL<T> :: DeleteFirst()
{
    struct DoublyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return ;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        first = first->next;
        delete temp;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    struct DoublyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return ;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = last;

        last = last->prev;
        delete temp;

        last->next = first;
        first->prev = last;
    }

    iCount--;
}

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
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
        struct DoublyCLLnode<T> * temp = NULL;
        struct DoublyCLLnode<T> * target = NULL;
        int iCnt = 0;

        temp = first;

        for(iCnt = 1; iCnt <(pos-1); iCnt++)
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
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    temp = first;

    cout << "\n(start) <=> ";
    do
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    }while(temp != first);

    cout << " (back to first)\n";
}

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

int main()
{
    // For Integer
    printf("For Integer : \n");

    DoublyCLL<int> iobj;
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

    DoublyCLL<double> dobj;

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

    DoublyCLL<char> cobj;

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