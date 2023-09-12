#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};

void InsertFirst(struct Node **ppHead,int iNo);
void InsertLast(struct Node **ppHead,int iNo);
void InsertAtPosition(struct Node **ppHead,int iNo,int iPos);
int Count(struct Node *pHead);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertLast(&pFirst,10);
    InsertLast(&pFirst,20);
    InsertLast(&pFirst,30);
    InsertAtPosition(&pFirst,40,2);
    InsertAtPosition(&pFirst,50,5);
    Display(pFirst);

    return 0;
}
void InsertFirst(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;

    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Alloacation is Failed");
        return;
    }

    pNewNode ->iData =iNo;

    if(NULL == (*ppHead))
    {
        (*ppHead) = pNewNode;
        pNewNode ->pNext=NULL;
        return;
    }

    pNewNode ->pNext = (*ppHead);
    (*ppHead)=pNewNode;

    return;
}
void InsertLast(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;
    struct Node *pTemp = NULL;

    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Alloacation is Failed");
        return;
    }

    pNewNode ->iData =iNo;
    pNewNode ->pNext=NULL;

    if(NULL == (*ppHead))
    {
        (*ppHead) = pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while(pTemp->pNext!=NULL)
    {
       (pTemp)=(pTemp)->pNext;
    }

    pTemp->pNext = pNewNode;
    return;
}
void InsertAtPosition(struct Node **ppHead,int iNo,int iPos)
{
    int iCount = 0;
    struct Node *pNewNode = NULL;
    struct Node *pTemp = NULL;


    iCount = Count(*ppHead);
    if(iPos < 0 || iPos > iCount +1)
    {
        printf("Position is not valid! \n");
        return;
    }

    if(iPos==1)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    if(iPos == iCount+1)
    {
        InsertLast(ppHead,iNo);
        return;
    }

    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(NULL == (*ppHead))
    {
        printf("Memory Allocation is Failed! \n");
        return;
    }
    pNewNode ->iData = iNo;

    pTemp = (*ppHead);

    iCount = 1;  //count cha reuse kela ahe.tyamule aple 4byte vachale

    while(iCount < iPos-1)
    {
        iCount++;
        pTemp = pTemp ->pNext;
    }
    pNewNode->pNext = pTemp -> pNext;
    pTemp -> pNext = pNewNode; 
    return;
}
int Count(struct Node *pHead)
{
    int iCount=0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead ->pNext;
    }
    return iCount;
}
void Display(struct Node *pHead)
{
    if((pHead) == NULL)
    {
        printf("Linked List is Empty!!");
        return;
    }
    while(pHead != NULL)
    {
        printf("->|%d|",pHead->iData);
        pHead = pHead ->pNext;
    }
    return;
}

