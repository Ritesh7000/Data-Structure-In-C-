#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertAtPosition(struct node **,struct node **,int, int);
void InsertLast(struct node**,struct node **,int);
void InsertFirst(struct node **,struct node **, int);
int CountNodes(struct node*,struct node*);
void Display(struct node *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    InsertAtPosition(&pFirst,&pLast,10,1);
    InsertAtPosition(&pFirst,&pLast,20,2);
    InsertAtPosition(&pFirst,&pLast,30,1);
    InsertAtPosition(&pFirst,&pLast,40,3);
    InsertAtPosition(&pFirst,&pLast,50,2);
    InsertAtPosition(&pFirst,&pLast,60,5);

    Display(pFirst,pLast);
    printf("\n%d",pFirst);
    printf("\n%d",pLast);

    return 0;
}

void InsertAtPosition(struct node ** ppHead, struct node **ppTail,int iNo, int iPos)
{
    

    struct node *pNewNode = NULL;
    int iCount;
    struct node *pTemp = NULL;

    
    iCount = CountNodes(*ppHead,*ppTail);

    if(iPos <= 0 || iPos > iCount+1)
    {
        printf("Position is Invalid\n");
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
        printf("Memory Allocation is Failed!!\n");
        return;
    }
    pTemp = (*ppHead);
    pNewNode ->iData = iNo;

    iCount = 1;

    while(iCount < iPos -1)
    {
        iCount++;
        pTemp = pTemp ->pNext;
    }

    pNewNode ->pNext = pTemp ->pNext;
    pTemp -> pNext = pNewNode;

    return;
}
void InsertFirst(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNeawNode = NULL;

    pNeawNode = (struct node*)malloc(sizeof(struct node));

    if(pNeawNode == NULL)
    {
        printf("Memory Allocation is Failed!!\n");
        return;
    }

    pNeawNode ->iData =iNo;
    if(NULL == (*ppHead))
    {
        *ppHead = pNeawNode;
        *ppTail = pNeawNode;
        (*ppTail)->pNext = (*ppHead);

        return;
    }

    pNeawNode ->pNext = *ppHead;
    *ppHead = pNeawNode;
    (*ppTail)->pNext = *ppHead;

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

    pNewNode ->iData = iNo;

    if((*ppHead) == NULL)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppTail)->pNext = (*ppHead);
        return;
    }

    (*ppTail)->pNext = pNewNode;
    (*ppTail) = pNewNode;
    (*ppTail)->pNext = (*ppHead);
    
    return;

}
int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCounts=0;
    if(pHead == NULL)
    {
        printf("Linked list is empty!\n");
        return iCounts;
    }

    do 
    {
        iCounts++;
        pHead = pHead ->pNext;
    }
    while((pHead) != pTail->pNext);

    return iCounts;

}
void Display(struct node *pHead, struct node *pTail)
{
     if(pHead == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }

    do 
    {
        printf("|%d|%d|->",pHead->iData,pHead->pNext);

        pHead = pHead->pNext;
    }
    while(pHead != pTail->pNext);

    return;

}

