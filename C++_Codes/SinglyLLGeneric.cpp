// Singly Linear

#include<iostream>
using namespace std;

template<class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode * next;
};

template<class T>  
class SinglyLL
{
    private:               
        struct SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);
};

template<class T>  
SinglyLL<T> :: SinglyLL()
{
    cout << "Object of SinglyLL gets created.\n";
    first = NULL;
    iCount = 0;
}

template<class T>  
void SinglyLL<T> :: InsertFirst(T no)          
{
    struct SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;    
    first = newn;

    iCount++;
}

template<class T>  
void SinglyLL<T> :: InsertLast(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;
    
    newn = new SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(iCount == 0)        
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
    }

    iCount++;
}

template<class T>  
void SinglyLL<T> :: DeleteFirst()
{
    struct SinglyLLLnode<T> * temp = NULL;

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
        delete temp;
    }

    iCount--;
}

template<class T>  
void SinglyLL<T> :: DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;

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

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

template<class T>  
void SinglyLL<T> :: Display()             
{
    struct SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = first;

    for(iCnt = 1; iCnt <= iCount; iCnt++)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template<class T>  
int SinglyLL<T> :: Count()
{
    return iCount;
}

template<class T>  
void SinglyLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> * temp = NULL;

    if(pos < 1 || pos > (iCount+1))
    {
        cout << "Invalid Input\n";
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
        struct SinglyLLLnode<T> * newn = NULL;

        newn = new SinglyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template<class T>  
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > (iCount))
    {
        cout << "Invalid Input\n";
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
        temp = first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        iCount--;
    }
}

int main()
{
    // For Integer
    printf("For Integer : \n");

    SinglyLL<int> iobj;
    int iRet = 0;

    iobj.InsertFirst(51);
    iobj.InsertFirst(21);
    iobj.InsertFirst(11);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    iobj.InsertLast(101);
    iobj.InsertLast(111);
    iobj.InsertLast(121);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    iobj.DeleteFirst();

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    iobj.DeleteLast();

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    iobj.InsertAtPos(105, 4);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    iobj.DeleteAtPos(4);

    iobj.Display();
    iRet = iobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    // For double
    printf("\n For Double : \n");

    SinglyLL<double> dobj;

    dobj.InsertFirst(51.5);
    dobj.InsertFirst(21.5);
    dobj.InsertFirst(11.5);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.InsertLast(101.5);
    dobj.InsertLast(111.5);
    dobj.InsertLast(121.5);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.DeleteFirst();

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.DeleteLast();

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.InsertAtPos(105.5, 4);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.DeleteAtPos(4);

    dobj.Display();
    iRet = dobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    // For character
    printf("\n For Character : \n");

    SinglyLL<char> cobj;

    cobj.InsertFirst('C');
    cobj.InsertFirst('B');
    cobj.InsertFirst('A');

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    cobj.InsertLast('D');
    cobj.InsertLast('E');
    cobj.InsertLast('F');

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    dobj.DeleteFirst();

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    cobj.DeleteLast();

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    cobj.InsertAtPos('G', 4);

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    cobj.DeleteAtPos(4);

    cobj.Display();
    iRet = cobj.Count();

    cout << "Number of SinglyLLLNodes are : " << iRet << "\n";

    return 0;
}