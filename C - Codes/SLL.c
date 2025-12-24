#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;

    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// call  by value

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("| %d | -> ", first->data);
        first = first->next;
    }

    printf("NULL \n");
}

int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

// call by address

// insert

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)    // LL is empty
    {
        (*first) = newn;
    }
    else                    // LL has atlest 1 node
    {
        newn->next = (*first);
        (*first) = newn; 
    }
}

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;      // made another head like pointer

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first) == NULL)    // LL is empty
    {
        (*first) = newn;
    }
    else                    // LL has atlest 1 node
    {
        temp = (*first);

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
}

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)        // LL is empty
    {
        return ;
    }
    else if((*first)->next == NULL) // LL has just 1 node 
    {
        free(*first);
        (*first) = NULL;
    }
    else                        // LL has more than 1 node
    {
        temp = (*first);
        (*first) = (*first)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)        // LL is empty
    {
        return ;
    }
    else if((*first)->next == NULL) // LL has just 1 node 
    {
        free(*first);
        (*first) = NULL;
    }
    else                        // LL has more than 1 node
    {
        temp = (*first);

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize+1)
    {
        printf("Invalide Position\n");
        return ;
    }
    else if(pos == 1)
    {
        InsertFirst(first, no);
    }
    else if(pos == (iSize+1))
    {
        InsertLast(first, no);
    }
    else
    {
        temp = (*first);

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if(pos < 1 || pos > iSize)
    {
        printf("Invalide Position\n");
        return ;
    }
    else if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == (iSize))
    {
        DeleteLast(first);
    }
    else
    {
        temp = (*first);

        for(iCnt = 1; iCnt < (pos-1); iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        free(target);
    }
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);
    InsertFirst(&head, 10);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 121);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    DeleteFirst(&head);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    DeleteLast(&head);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    InsertAtPos(&head, 105, 5);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    DeleteAtPos(&head, 5);

    Display(head);
    iRet = Count(head);
    printf("Count is : %d\n", iRet);

    return 0;
}