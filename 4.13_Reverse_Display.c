#include<stdio.h>
#include<malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,struct node **,int);
void PhysicalReverse(struct node **,struct node **);
void Reverse(struct node **,struct node  **);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    InsertLast(&pFirst,&pLast,10);
    InsertLast(&pFirst,&pLast,20);
    InsertLast(&pFirst,&pLast,30);
    InsertLast(&pFirst,&pLast,40);

    Display(pFirst,pLast);

    printf("\nPRevese: \n");
    Reverse(&pFirst,&pLast);
    printf("\nLinkeLis = \n");
    Display(pFirst,pLast);


    return 0;
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
void Reverse(struct node **ppHead,struct node  **ppTail)
{
    PhysicalReverse(ppHead,ppTail);
    Display(*ppHead,*ppTail);
    PhysicalReverse(ppHead,ppTail);

}
void PhysicalReverse(struct node **ppHead,struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node  *pCurrent = *ppHead;
    struct node *pNext = NULL;

    do{
        pNext = pCurrent->pNext;
        pCurrent->pNext = pPrev;
        pCurrent ->pPrev = pNext;

        pPrev = pCurrent;
        pCurrent = pNext;
    }while(pCurrent != *ppHead);

    (*ppTail) = (*ppHead);
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

