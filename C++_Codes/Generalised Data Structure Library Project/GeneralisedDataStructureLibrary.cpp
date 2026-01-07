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
    Stack                   Stacknode                         Stack             Done               |
    Queue                   Queuenode                         Queue             Done               |
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

    if(first == NULL) 
    { 
        return; 
    }

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

        DoublyCLLnode(T no)
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
    newn = new DoublyCLLnode<T>(no);

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
    newn = new DoublyCLLnode<T>(no);

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
        newn = new DoublyCLLnode<T>(no);

        DoublyCLLnode<T> * temp = NULL;
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

    if(first == NULL) 
    { 
        return; 
    }

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

///////////////////////////////////////////////////////////////////////
//          Stack Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   Stacknode
//  Description         :   Used to create node
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   Stack
//  Description         :   Used for stack creation
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    private:
        int iCount;
        Stacknode<T> * first;

    public:
        Stack();

        void push(T no);      
        T pop();             
        T peep();

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   Stack
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
{
    cout << "Stack gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   push
//  Input           :   Data for stack
//  Output          :   Nothing
//  Description     :   Push data in stack
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: push(T no)
{
    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn->next = this->first;
    this->first = newn;
    
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   pop
//  Input           :   Nothing
//  Output          :   Data popped from stack
//  Description     :   Pop data in stack
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: pop()
{
    T Value = 0;
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}   

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   peep
//  Input           :   Nothing
//  Output          :   Data from stack
//  Description     :   Print data at top of stack
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
T Stack<T> :: peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Display Stack all data
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout << "Stack is empty...\n";
        return ;
    }

    while(temp != NULL)
    {
        cout << "|\t" << temp->data << "\t|\n"; 
        temp = temp->next;
    }
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of data elements
//  Description     :   Give count of data elements from stack
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int Stack<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////
//          Queue Using Generic Approach
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   Queuenode
//  Description         :   Used to create node
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template<class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Class Name          :   Queue
//  Description         :   Used for queue creation
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    private:
        int iCount;
        Queuenode<T> * first;
        Queuenode<T> * last;

    public:
        Queue();

        void enqueue(T no);      
        T dequeue();              

        void Display();
        int Count();
};

/////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name    :   Queue
//  Input               :   Nothing
//  Output              :   Nothing
//  Description         :   Used to allocate resources and initialization
//  Author              :   Krishna Govindrav Hitnalikar
//  Date                :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
{
    cout << "Queue gets created successfully...\n";

    this->iCount = 0;
    this->first = NULL;
    this->last = NULL;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   enqueue
//  Input           :   Data for element
//  Output          :   Nothing
//  Description     :   Add element in last of queue
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;         
    }
    
    this->iCount++;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   dequeue
//  Input           :   Nothing
//  Output          :   Element removed from queue
//  Description     :   Removes first elements from queue
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)    
    {
        cout << "Queue is empty...\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;
    return Value;
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Display
//  Input           :   Nothing
//  Output          :   Nothing
//  Description     :   Display Queue all data
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)   
    {
        cout << "Queue is empty...\n";
        return ;
    }

    while(temp != NULL)
    {
        cout << "| " << temp->data << " | - "; 
        temp = temp->next;
    }

    cout << "\n";
}

/////////////////////////////////////////////////////////////////////////////////
//
//  Function Name   :   Count
//  Input           :   Nothing
//  Output          :   Count of data elements
//  Description     :   Give count of data elements from queue
//  Author          :   Krishna Govindrav Hitnalikar
//  Date            :   07/01/2026
//  
/////////////////////////////////////////////////////////////////////////////////

template<class T>
int Queue<T> :: Count()
{
    return iCount;
}

//////////////////////////////////// End of Library ////////////////////////////////////////////

int main()
{
    cout << "\nSingly Linear Linked List : \n";
    
    SinglyLL<int> *obj = new SinglyLL<int> ();

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteFirst();

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteLast();

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->InsertAtPos(105, 4);

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

    obj->DeleteAtPos(4);

    obj->Display();

    cout << "Number of nodes are : " << obj->Count() << "\n";

/////////////////////////////////////////////////////////////////////////////////////////

    cout << "\nSingly Circular Linked List : \n";
    
    SinglyCLL<char> *sobj = new SinglyCLL<char> ();

    sobj->InsertFirst('X');
    sobj->InsertFirst('Y');
    sobj->InsertFirst('Z');

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

    sobj->InsertLast('U');
    sobj->InsertLast('V');
    sobj->InsertLast('W');

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

    sobj->DeleteFirst();

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

    sobj->DeleteLast();

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

    sobj->InsertAtPos('$', 4);

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

    sobj->DeleteAtPos(4);

    sobj->Display();

    cout << "Number of nodes are : " << sobj->Count() << "\n";

/////////////////////////////////////////////////////////////////////////////////////////

    cout << "\nDoubly Linear Linked List : \n";

    DoublyLLL<int> *dobj = new DoublyLLL<int>();

    dobj->InsertFirst(1);
    dobj->InsertFirst(2);
    dobj->InsertFirst(3);

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->InsertLast(4);
    dobj->InsertLast(5);
    dobj->InsertLast(6);

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteFirst();

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteLast();

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->InsertAtPos(100,4);

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

    dobj->DeleteAtPos(4);

    dobj->Display();

    cout << "Number of nodes are : " << dobj->Count() << "\n";

/////////////////////////////////////////////////////////////////////////////////////////

    cout << "\nDoubly Circular Linked List : \n";

    DoublyCLL<char> *dcobj = new DoublyCLL<char>();

    dcobj->InsertFirst('A');
    dcobj->InsertFirst('B');
    dcobj->InsertFirst('C');

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

    dcobj->InsertLast('X');
    dcobj->InsertLast('Y');
    dcobj->InsertLast('Z');

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

    dcobj->DeleteFirst();

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

    dcobj->DeleteLast();

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

    dcobj->InsertAtPos('@',4);

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

    dcobj->DeleteAtPos(4);

    dcobj->Display();

    cout << "Number of nodes are : " << dcobj->Count() << "\n";

/////////////////////////////////////////////////////////////////////////////////////

    cout << "\nStack : \n";

    Stack<char> *stackobj = new Stack<char>();

    stackobj->push('a');
    stackobj->push('b');
    stackobj->push('c');
    stackobj->push('d');

    stackobj->Display();

    cout << "Number of elements in Stack : " << stackobj->Count() << "\n";

    cout << "Return value of peep() is : " << stackobj->peep() << "\n";

    stackobj->Display();

    cout << "Number of elements in Stack : " << stackobj->Count() << "\n";

    cout << "Popped element is : " << stackobj->pop() << "\n";

    stackobj->Display();

    cout << "Number of elements in Stack : " << stackobj->Count() << "\n";

    cout << "Popped element is : " << stackobj->pop() << "\n";

    stackobj->Display();

    cout << "Number of elements in Stack : " << stackobj->Count() << "\n";

    stackobj->push('e');

    stackobj->Display();

    cout << "Number of elements in Stack : " << stackobj->Count() << "\n";

/////////////////////////////////////////////////////////////////////////////////////

    cout << "\nQueue : \n";

    Queue<double> *qobj = new Queue<double>();

    qobj->enqueue(11.56789);
    qobj->enqueue(21.56789);
    qobj->enqueue(51.56789);
    qobj->enqueue(101.56789);

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    cout << "Removed element is : " << qobj->dequeue() << "\n";

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    qobj->enqueue(121.56789);

    qobj->Display();
    cout << "Number of elements in Queue : " << qobj->Count() << "\n";

    delete obj;
    delete sobj;
    delete dobj;
    delete dcobj;
    delete stackobj;
    delete qobj;

    return 0;
}