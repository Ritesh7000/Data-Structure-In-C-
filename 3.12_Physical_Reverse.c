#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void PhysicalReverse(struct node **,struct node **);
void Display(struct node  *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast  = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    printf("add of %d\n",pFirst);
    printf("add of %d\n",pLast);
    Display(pFirst,pLast);
    printf("\n");
    PhysicalReverse(&pFirst,&pLast);
    Display(pFirst,pLast);
    printf("\npFirst = %d \n",pFirst);
    printf("pLast = %d",pLast->pNext);

return 0;
}

void InsertFirst(struct node **ppHead, struct node **ppTail, int iNo)
{
    struct node *pNeawNode = NULL;

    pNeawNode = (struct node*)malloc(sizeof(struct node));

    if(pNeawNode == NULL)
    {
        printf("Memory Allocation is Falied!!");
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

void PhysicalReverse(struct node**ppHead,struct node **ppTail)
{
    struct node *pPrev = *ppTail;
    struct node *pCurrent = *ppHead;
    struct node *pNext = NULL;
    
    if(*ppHead == NULL || *ppHead == *ppTail)
    return;

    do{
        pNext = pCurrent ->pNext;
        pCurrent->pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }
    while(pCurrent != *ppHead);

    *ppTail = *ppHead;
    *ppHead = pPrev; 
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
        printf("|%d|%d|->",pHead->iData,pHead->pNext);

        pHead = pHead->pNext;
    }
    while(pHead != pTail->pNext);

    return;
}
