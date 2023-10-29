#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,struct node **,int );
void Display(struct node *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    InsertLast(&pFirst,&pLast,10);
    InsertLast(&pFirst,&pLast,20);
    InsertLast(&pFirst,&pLast,30);
    InsertLast(&pFirst,&pLast,40);

    Display(pFirst,pLast);
    printf("\npFirst = %d\n",pFirst);
    printf("pLast = %d\n",pLast);

    return 0;
}

void InsertLast(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!");
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

void Display(struct node *pHead,struct node *pTail)
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