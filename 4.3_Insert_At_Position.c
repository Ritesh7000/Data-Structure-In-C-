#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node 
{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **,int);
void InsertLast(struct node **,struct node **,int);
void InsertAtPosition(struct node **,struct node **,int , int);
int CountNodes(struct node *,struct node *);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    Display(pFirst,pLast);
    //printf("\n%d\n",CountNodes(pFirst,pLast));
    printf("\n");
    InsertAtPosition(&pFirst,&pLast,50,5);
    InsertAtPosition(&pFirst,&pLast,60,5);
    Display(pFirst,pLast);


    return 0;
}
void InsertAtPosition(struct node **ppHead,struct node **ppTail,int iNo,int iPos)
{
    struct node *pNewNode = NULL;
    int iCount;
    struct node *pTemp = NULL;

    iCount = CountNodes(*ppHead,*ppTail);
    
    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("Position is Invalid!");
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(ppHead,ppTail,iNo);
        return;
    }
    if(iPos == iCount+1)
    {
        InsertLast(ppHead,ppTail,iNo);
        return;
    }

    pNewNode = (struct node*)malloc(sizeof(struct node));
    if(pNewNode == NULL)
    {
        printf("\nMemory Allocation is Failed!\n");
        return;
    }

    pNewNode ->iData = iNo;
    pTemp = *ppHead;
    iCount = 1;
    while(iPos-1 > iCount)
    {
        iCount++;
        pTemp = pTemp ->pNext;
    }
    pNewNode ->pNext = pTemp ->pNext;
    pNewNode ->pPrev = pTemp;
    pTemp->pNext->pPrev=pNewNode;
    pTemp->pNext = pNewNode;

    return;
}
int CountNodes(struct node *pHead,struct node *pTail)
{
    int iCount = 0;

    do
    {
        iCount++;
        pHead = pHead ->pNext;
    }
    while(pHead != pTail ->pNext);

    return iCount;
}

void InsertFirst(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!");
        return;
    }
    pNewNode->iData =iNo;
    if(*ppHead == NULL)
    {
        //pNewNode->pNext=pNewNode;
        //pNewNode->pPrev=pNewNode;
        //*ppHead=*ppTail=pNewNode;
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext=*ppHead;
        (*ppTail)->pPrev=*ppHead;
        return;
    }

    pNewNode->pNext = *ppHead;
    pNewNode->pPrev = *ppTail;
    
    (*ppHead) ->pPrev = pNewNode;
    *ppHead = pNewNode;
    (*ppTail)->pNext = *ppHead;
    //(*ppHead)->pPrev= *ppTail;
 
    return;
}

void InsertLast(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData=iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppHead)->pPrev= *ppTail;
        (*ppTail)->pNext = *ppHead;
        return;
    }

    pNewNode ->pNext = *ppHead;
    pNewNode ->pPrev = *ppTail;

    (*ppTail)->pNext = pNewNode;
    (*ppTail) = pNewNode;   
    (*ppHead)->pPrev = *ppTail; 
   
    return;
}
void Display(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }
    do
    {
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }
    while(pHead != pTail->pNext);
    return;
}