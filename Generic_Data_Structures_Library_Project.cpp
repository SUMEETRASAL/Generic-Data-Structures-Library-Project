///////////////////////////////////////////////////////////////////////////////////////
//
//                                  PROJECT:
//                          GENERIC DATA STRUCTURES LIBRARY     
//              
//                  AUTHOR:         Sumeet Vivek Rasal
//                  DAY & DATE:     Friday, 12th July, 2024
//
///////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                  Code of Singly Linear Linked List
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL <T>* First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL <T>* temp = First;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;    //new struct node   // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T>* temp = First;

    newn = new nodeSL<T>;    // malloc

    newn->data = No;
    newn->next = NULL;

    if(First == NULL) // if(iCount == 0)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp -> next;
        }
        temp -> next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else 
    {
        temp = First;
        
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp -> next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First -> next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"LL is empty\n";
        return;
    }
    else if(First -> next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp ->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> * temp1;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else 
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1 -> next;
        }

        temp2 = temp1->next;

        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }    
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                  Code of Doubly Circular Linked List
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDC
{
    int data;
    struct nodeDC *next;
    struct nodeDC *prev;
};

template <class T>
class DoublyCL
{
    private:
        struct nodeDC <T>* First;
        struct nodeDC <T>* Last;
        int iCount;

    public:
        DoublyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL <T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Linked List is emprty\n";
        return;
    }

    cout<<"<=> ";
    do
    {
        cout<<"| "<<First->data <<"| <=> ";
        First = First -> next;
    }while(Last -> next != First);

    cout<<"\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDC <T>* newn = NULL;

    newn = new nodeDC <T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{
    struct nodeDC <T>* newn = NULL;

    newn = new nodeDC <T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last ->next = newn;
        newn->prev = Last;
        Last = newn;
    }
    Last -> next = First;
    First -> prev = Last;

    iCount++;    
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDC <T>* temp = NULL;
    struct nodeDC <T>* newn = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDC <T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        First = First -> next;
        delete Last->next;
        First -> prev = Last;
        Last -> next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if(First == NULL && Last == NULL)   // Empty LL
    {
        return;
    }
    else if(First == Last)   // Single node
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else    // More than one node
    {
        Last = Last -> prev;
        delete First -> prev;

        Last -> next = First;
        First -> prev = Last;
    }
    iCount--;    
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC <T>* temp = NULL;

    int i = 0;

    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid postion\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }    
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                      Code of Doubly Linear Linked List
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
    private:
        struct nodeDL <T>* First;
        int iCount;

    public:
        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);        
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display()
{
    struct nodeDL <T>* temp = First;

    cout<<"NULL<=>";
    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL <T>* newn = NULL;

    newn = new struct nodeDL <T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL <T>* newn = NULL;
    struct nodeDL <T>* temp = NULL;

    newn = new struct nodeDL <T>;

    newn->data = No;
    newn->prev = NULL;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    int i = 0;
    struct nodeDL <T>* newn = NULL;
    struct nodeDL <T>* temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new struct nodeDL <T>;
        newn->data = No;
        newn->prev = NULL;
        newn->next = NULL;

        temp = First;   

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        temp->next->prev = newn;
        newn->next = temp->next;
        newn->prev = temp;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    else if(First->next == NULL)    //if LL contains 1 nodeDL
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL <T>* temp = First;

        First->next->prev = NULL;
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(First == NULL)
    {
        cout<<"Linked List is empty\n";
        return;
    }
    else if(First->next == NULL)    //if LL contains 1 nodeDL
    {
        delete First;
        First = NULL;
    }
    else
    {
        struct nodeDL <T>* temp = First;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeDL <T>* temp1 = NULL;
    struct nodeDL <T>* temp2 = NULL;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;    //to store the address of the nodeDL to be deleted

        temp1->next = temp2->next;
        temp2->next->prev = temp1;

        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                      Code of Singly Circular Linked List
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSC
{
    T data;
    struct nodeSC *next;
};

template <class T>
class SinglyCL
{
    private:
        struct nodeSC <T>* First;
        struct nodeSC <T>* Last;
        int iCount;

    public:
        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL <T>::SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL <T>::Display()
{
    struct nodeSC <T>* temp = First;

    do
    {
        cout<<"|"<<First->data<<"|->";
        First = First->next;
    } while (First != Last->next);
    cout<<"\n";
}

template <class T>
int SinglyCL <T>::Count()
{
    return iCount;
}

template <class T>
void SinglyCL <T>::InsertFirst(T No)
{
    struct nodeSC <T>* newn = NULL;
    newn = new struct nodeSC <T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        newn->next = First;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        Last->next = First;
    }
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertLast(T No)
{
    struct nodeSC <T>* newn = NULL;
    newn = new struct nodeSC <T>;

    newn->data = No;
    newn->next = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        newn->next = First;
        Last = newn;
    }
    else
    {
        
        Last->next = newn;
        newn->next = First;
        Last = newn;
    }
    iCount++;
}

template <class T>
void SinglyCL <T>::InsertAtPos(T No, int iPos)
{
    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeSC <T>* newn = NULL;
        newn = new struct nodeSC <T>;

        newn->data = No;
        newn->next = NULL;

        struct nodeSC <T>* temp = First;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        
        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL <T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete...LL is empty\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last->next = First->next;
        delete First;
        First = Last->next;
    }
    iCount--;
}

template <class T>
void SinglyCL <T>::DeleteLast()
{
    struct nodeSC <T>* temp = NULL;

    if((First == NULL) && (Last == NULL))
    {
        cout<<"Unable to delete...LL is empty\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;

        do
        {
            temp = temp->next;
        } while (First->next->next != Last->next);
        
        temp->next = First;
        delete Last;
        Last = temp;
    }
    iCount--;
}

template <class T>
void SinglyCL <T>::DeleteAtPos(int iPos)
{
    if(iPos < 1 || iPos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        struct nodeSC <T>* temp1 = First;
        struct nodeSC <T>* temp2 = NULL;
        int i = 0;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;

        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                              Code of STACK
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeSTK
{
    T data;
    struct nodeSTK *next;
};

template <class T>
class Stack
{
    private:
        struct nodeSTK <T>* First;
        int iCount;

    public:
        Stack();

        void Display();
        int Count();

        void Push(T No);  //InsertFirst()
        int Pop();   //DeleteFirst()
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout<<"Elements of stack are : \n";
    struct nodeSTK <T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"\n";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)  //InsertFirst()
{
    struct nodeSTK <T>* newn = NULL;

    newn = new struct nodeSTK <T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack<T>::Pop()      //DeleteFirst()
{
    int iValue = 0;
    struct nodeSTK <T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"Stack is empty..unable to pop\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                              Code of QUEUE
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template <class T>
class Queue
{
    private:
        struct nodeQ <T>* First;
        int iCount;

    public:
        Queue();

        void Display();
        int Count();

        void EnQueue(T No);  //InsertLast()
        int DeQueue();   //DeleteFirst()
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout<<"Elements of queue are : \n";
    struct nodeQ <T>* temp = First;

    while(temp != NULL)
    {
        cout<<temp->data<<"->\t";
        temp = temp->next;
    }
    cout<<"\n";
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)  //InsertFirst()
{
    struct nodeQ <T>* newn = NULL;
    struct nodeQ <T>* temp = NULL;
    newn = new struct nodeQ <T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
int Queue<T>::DeQueue()      //DeleteFirst()
{
    int iValue = 0;
    struct nodeQ <T>* temp = NULL;

    if(First == NULL)
    {
        cout<<"unable to remove as Queue is empty..\n";
        return -1;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;

        iCount--;
    }
    return iValue;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                  Code of Binary Search Tree
//
//
///////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct nodeBST
{
    T data;
    struct nodeBST* lchild;
    struct nodeBST* rchild;
};

template <class T>
class BST
{
    private:
        struct nodeBST <T>* Root;
        int iCount;
    
    public:
        BST();
        struct nodeBST <T>* GetRoot()
        {
            return Root;
        }

        void Insert(T No);

        void InOrder(struct nodeBST <T>* Root);
        void PreOrder(struct nodeBST <T>* Root);
        void PostOrder(struct nodeBST <T>* Root);

        bool Search(T No);
        int CountLeaf(struct nodeBST <T>* Root);
        int CountParent(struct nodeBST <T>* Root);
        int CountAll();
};

template <class T>
BST<T>::BST()
{
    Root = NULL;
    iCount = 0;
}

template <class T>
void BST<T>::Insert(T No)
{
    struct nodeBST <T>* newn = NULL;
    struct nodeBST <T>* temp = NULL;

    newn = new struct nodeBST <T>;

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if(Root == NULL)
    {
        Root = newn;
    }
    else
    {
        temp = Root;

        while(1)
        {
            if(temp->data == No)
            {
                cout<<"Unable to insert node as element is already present\n";
                delete newn;
                return;
            }
            else if(No > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(No < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
    iCount++;
}

template <class T>
void BST<T>::InOrder(struct nodeBST <T>* Root)
{
    if(Root != NULL)
    {
        InOrder(Root->lchild);
        cout<<Root->data<<"\n";
        InOrder(Root->rchild);
    }
}

template <class T>
void BST<T>::PreOrder(struct nodeBST <T>* Root)
{
    if(Root != NULL)
    {
        cout<<Root->data<<"\n";
        PreOrder(Root->lchild);
        PreOrder(Root->rchild);
    }
}

template <class T>
void BST<T>::PostOrder(struct nodeBST <T>* Root)
{
    if(Root != NULL)
    {
        PostOrder(Root->lchild);
        PostOrder(Root->rchild);
        cout<<Root->data<<"\n";
    }
}

template <class T>
bool BST<T>::Search(T No)
{
    bool flag = false;

    if(Root == NULL)
    {
        cout<<"Tree is empty\n";
        return flag;
    }

    while(Root != NULL)
    {
        if(Root->data == No)
        {
            flag = true;
            break;
        }
        else if(No > Root->data)
        {
            Root = Root->rchild;
        }
        else if(No < Root->data)
        {
            Root = Root->lchild;
        }
    }
    return flag;
}

template <class T>
int BST<T>::CountLeaf(struct nodeBST <T>* Root)
{
    static int iCnt = 0;

    if(Root != NULL)
    {
        if(Root->rchild == NULL && Root->lchild == NULL)
        {
            iCnt++;
        }
        CountLeaf(Root->lchild);
        CountLeaf(Root->rchild);
    }
    return iCnt;
}

template <class T>
int BST<T>::CountParent(struct nodeBST <T>* Root)
{
    static int iCnt = 0;

    if(Root != NULL)
    {
        if(Root->rchild != NULL || Root->lchild != NULL)
        {
            iCnt++;
        }
        CountParent(Root->lchild);
        CountParent(Root->rchild);
    }
    return iCnt;
}

template <class T>
int BST<T>::CountAll()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//
//                                  MAIN
//
//
///////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //////////////////////////////////////////////////////////
    //
    //      Object creation and Function calls from here
    //
    //////////////////////////////////////////////////////////

    return 0;
}