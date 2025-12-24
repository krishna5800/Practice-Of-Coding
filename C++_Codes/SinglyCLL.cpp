#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

class SinglyCLL
{
    private:
        int iCount;
        PNODE first;
        PNODE last;

    public:
        SinglyCLL()
        {
            cout << "Object of SinglyCLL is created successfully\n";
            iCount = 0;
            first = NULL;
            last = NULL;
        }

        void InsertFirst(int no)
        {
            PNODE newn = new NODE;

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

        void InsertLast(int no)
        {
            PNODE newn = new NODE;

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

        void InsertAtPos(int no, int pos)
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
                PNODE newn;
                newn = new NODE;
                PNODE temp = NULL;
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

        void DeleteFirst()
        {
            PNODE temp = NULL;

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

        void DeleteLast()
        {
            PNODE temp = NULL;
            PNODE target = NULL;

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

        void DeleteAtPos(int pos)
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
                PNODE temp = NULL;
                PNODE target = NULL;
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

        void Display()
        {
            PNODE temp = NULL;

            temp = first;

            cout << "\n-> ";
            do
            {
                cout << "| " << temp->data << " |->";
                temp = temp->next;
            }while(temp!=first);

            cout << "(back to first)\n";
        }

        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyCLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    obj.InsertAtPos(105, 4);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    obj.DeleteAtPos(4);

    obj.Display();
    iRet = obj.Count();

    cout << "Number of nodes are : " << iRet << "\n";

    return 0;
}