#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node{
    struct Node *pPrev;
    int iData;
    struct Node *pNext;
};

void InsertAtPosition(struct Node **ppHead,int iNo,int iPos);
void InsertFirst(struct Node **ppHead,int iNo);
void InsertLast(struct Node **ppHeadd,int iNo);
int CountNodes(struct Node *pHHead);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertAtPosition(&pFirst,30,1);
    InsertAtPosition(&pFirst,40,1);
    InsertAtPosition(&pFirst,50,2);
    InsertAtPosition(&pFirst,30,4);
    InsertAtPosition(&pFirst,40,6);
    InsertAtPosition(&pFirst,50,5);
    InsertAtPosition(&pFirst,50,0);

    //printf("%d",CountNodes(pFirst));
    Display(pFirst);


    return 0;
}
void InsertFirst(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;
    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed");
        return;
    }

    pNewNode ->iData =iNo;
    pNewNode ->pPrev = NULL;

    if((*ppHead) == NULL)
    {
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;       
        return;
    }

    pNewNode ->pNext= (*ppHead);
    (*ppHead)->pPrev = pNewNode;
    (*ppHead) = pNewNode;
    return;

}
void InsertLast(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;
    struct Node *pTemp = NULL;

    pNewNode = (struct Node*)malloc(sizeof(struct Node));
    if(pNewNode == NULL)
    {
        printf("Memory Allocation is failed!");
        return;
    }

    pNewNode ->iData = iNo;
    pNewNode ->pNext = NULL;

    if(NULL == (*ppHead))
    {
        pNewNode ->pPrev = NULL;
        (*ppHead) = pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp ->pNext;
    }

    pTemp ->pNext = pNewNode;
    pNewNode ->pPrev = pTemp;

}
int CountNodes(struct Node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}
void InsertAtPosition(struct Node **ppHead,int iNo,int iPos)
{
    int iCount = 0;
    struct Node *pNewNode = NULL; 
    struct Node *pTemp = NULL;

    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iCount+1 < iPos)
    {
        printf("Position is InValid!");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(ppHead,iNo);
        return;
    }
    if(iCount+1 == iPos)
    {
        InsertLast(ppHead,iNo);
        return;
    }

    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!");
        return;
    }
    pNewNode ->iData = iNo;

    iCount = 1;
    pTemp = (*ppHead);

    while(iCount < iPos-1)
    {   iCount++;
        pTemp = pTemp ->pNext;
    } 
    pNewNode ->pNext = pTemp ->pNext;
    pTemp -> pNext -> pPrev = pNewNode;
    pTemp -> pNext = pNewNode;   
    pNewNode ->pPrev = pTemp;

    return;
}
void Display(struct Node *pHead)
{
     if(pHead == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }
    while(pHead != NULL)
    {
        printf("->|%d|",pHead->iData);
        pHead = pHead->pNext;
    }
    return;

}
