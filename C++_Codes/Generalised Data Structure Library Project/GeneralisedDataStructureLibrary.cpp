/////////////////////////////////////////////
//    Generalised Data Structure Library   //
/////////////////////////////////////////////

/*
---------------------------------------------------------------------------------------------------+
    Type                    Name of class for node            Name of class for functionality      |
---------------------------------------------------------------------------------------------------
    Singly Linear           SinglyLLLnode                     SinglyLLL         Done               |
    Singly Circular         SinglyCLLnode                     SinglyCLL         Done               |
    Doubly Linear           DoublyLLLnode                     DoublyLLL         Done               |
    Doubly Circular         DoublyCLLnode                     DoublyCLL         Done               |
---------------------------------------------------------------------------------------------------+
*/

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////
//          Singly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   SinglyLLLnode
//  Description         :   Used to create node class
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode * next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   SinglyLL
//  Description         :   Used for singly linear linked list
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyLL
{
    private:             
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   SinglyLL
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyLL<T> :: SinglyLL()
{
    cout << "Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertFirst(T no)     
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;   
    this->first = newn;

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;
    
    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)          
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteFirst()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)             
    {
        return ;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)            
    {
        return ;
    }
    else if(this->first->next == NULL)   
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to display the linked list
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: Display()            
{
    SinglyLLLnode<T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }

    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of nodes
//  Description     :   Used to get count of all nodes in linked listS
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyLL<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input           :   Data of node and position of node
//  Output          :   Nothing
//  Description     :   Used to insert node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: InsertAtPos(T no, int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;

    if(pos < 1 || pos > (this->iCount+1))
    {
        cout << "Invalid Input\n";
        return ;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount+1))
    {
        this->InsertLast(no);
    }
    else
    {
        SinglyLLLnode<T> * newn = NULL;

        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input           :   Position of node
//  Output          :   Nothing
//  Description     :   Used to delete node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    int iCnt = 0;
    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > (this->iCount))
    {
        cout << "Invalid Input\n";
        return ;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == (this->iCount))
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

///////////////////////////////////////////////////////////////////////
//          Singly Circular Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   SinglyCLLnode
//  Description         :   Used to create node class
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode * next;

        SinglyCLLnode(T no)
        {
            data = no;
            next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   SinglyCLL
//  Description         :   Used for singly circular linked list
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class SinglyCLL
{
    private:
        int iCount;
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;

    public:
        SinglyCLL();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no, int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   SinglyCLL
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
    cout << "Object of SinglyCLL is created successfully\n";
    iCount = 0;
    first = NULL;
    last = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T> (no);

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        newn->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
    }
    
    last->next = first;

    iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    SinglyCLLnode<T> * newn = new SinglyCLLnode<T> (no);

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        newn->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    
    last->next = first;

    iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input           :   Data of node and position of node
//  Output          :   Nothing
//  Description     :   Used to insert node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no, int pos)
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
        SinglyCLLnode<T> * newn;
        newn = new SinglyCLLnode<T> (no);
        SinglyCLLnode<T> * temp = NULL;
        int iCnt = 0;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteFirst()
{
    SinglyCLLnode<T> * temp = NULL;

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
    }

    last->next = first;

    iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;

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

        while(temp->next != last)
        {
            temp = temp->next;
        }

        target = last;
        last = temp;
        delete target;
    }

    last->next = first;

    iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input           :   Position of node
//  Output          :   Nothing
//  Description     :   Used to delete node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
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
        SinglyCLLnode<T> * temp = NULL;
        SinglyCLLnode<T> * target = NULL;
        int iCnt = 0;

        temp = first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
    
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to display the linked list
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    SinglyCLLnode<T> * temp = NULL;

    temp = first;

    cout << "\n-> ";
    do
    {
        cout << "| " << temp->data << " |->";
        temp = temp->next;
    }while(temp!=first);

    cout << "(back to first)\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of nodes
//  Description     :   Used to get count of all nodes in linked listS
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//          Doubly Linear Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   DoublyLLLnode
//  Description         :   Used to create node class
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode * next;
        DoublyLLLnode * prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }

};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   DoublyLLL
//  Description         :   Used for doubly linear linked list
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyLLL
{
    private:
        int iCount;
        DoublyLLLnode<T> * first;

    public:
        DoublyLLL();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);
        
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   DoublyLLL
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyLLL<T> :: DoublyLLL()
{
    cout << "Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertFirst(T no)
{
    DoublyLLLnode<T> *newn = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertLast(T no)
{
    DoublyLLLnode<T> *newn = NULL;
    DoublyLLLnode<T> *temp = NULL;

    newn = new DoublyLLLnode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input           :   Data of node and position of node
//  Output          :   Nothing
//  Description     :   Used to insert node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: InsertAtPos(T no, int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    DoublyLLLnode<T> *newn = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > (this->iCount+1))
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == (this->iCount + 1))
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new DoublyLLLnode<T>(no);
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteFirst()
{
    if(this->first == NULL)                         
    {   
        return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        first = NULL;
    }       
    else                                            
    {
        this->first  = this->first->next;
        delete this->first->prev;
        this->first->prev = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteLast()
{
    DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL)                         
    {   
        return;
    }
    else if(this->first->next == NULL)             
    {
        delete this->first;
        first = NULL;
    }       
    else                                            
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input           :   Position of node
//  Output          :   Nothing
//  Description     :   Used to delete node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode<T> *temp = NULL;
    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout << "Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        this->iCount--;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to display the linked list
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyLLL<T> :: Display()
{
    DoublyLLLnode<T> *temp = NULL;

    temp = this->first;

    cout << "\nNULL <=>";
    while(temp != NULL)
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    }

    cout << "NULL\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of nodes
//  Description     :   Used to get count of all nodes in linked listS
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyLLL<T> :: Count()
{
    return this->iCount;
}

///////////////////////////////////////////////////////////////////////
//          Doubly Circular Linked List Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   DoublyCLLnode
//  Description         :   Used to create node class
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode * next;
        DoublyCLLnode * prev ;

        DoublyCLL(T no)
        {
            data = no;
            next = NULL;
            prev = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   DoublyCLL
//  Description         :   Used for doubly circular linked list
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class DoublyCLL
{
    private:
        int iCount;
        DoublyCLLnode<T>* first;
        DoublyCLLnode<T>* last;

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

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   DoublyCLL
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
    iCount = 0;
    first = NULL;
    last = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertFirst
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = NULL;
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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertLast
//  Input           :   Data of node
//  Output          :   Nothing
//  Description     :   Used to insert node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    DoublyCLLnode<T> * newn = NULL;
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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   InsertAtPos
//  Input           :   Data of node and position of node
//  Output          :   Nothing
//  Description     :   Used to insert node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

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
        DoublyCLLnode<T> * newn = NULL;
        newn = new DoublyCLLnode<T>;

        DoublyCLLnode<T> * temp = NULL;
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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteFirst
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at first position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    DoublyCLLnode<T> * temp = NULL;

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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteLast
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to delete node at last position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteLast()
{
    DoublyCLLnode<T> * temp = NULL;

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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   DeleteAtPos
//  Input           :   Position of node
//  Output          :   Nothing
//  Description     :   Used to delete node at desired position
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

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
        DoublyCLLnode<T> * temp = NULL;
        DoublyCLLnode<T> * target = NULL;
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

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Used to display the linked list
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    DoublyCLLnode<T> * temp = NULL;
    temp = first;

    cout << "\n(start) <=> ";
    do
    {
        cout << "| " << temp->data << " | <=>";
        temp = temp->next;
    }while(temp != first);

    cout << " (back to first)\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of nodes
//  Description     :   Used to get count of all nodes in linked listS
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   06/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

//////////////////////////////////// End of Library ////////////////////////////////////////////

int main()
{
    return 0;
}