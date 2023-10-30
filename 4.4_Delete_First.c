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
int DeleteFirst(struct node **,struct node **);
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
    printf("\n%d",DeleteFirst(&pFirst,&pLast));

    return 0;
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
int DeleteFirst(struct node **ppHead,struct node **ppTail)
{
    int iDeleData;

    iDeleData = (*ppHead)->iData;

    (*ppTail)->pNext = (*ppHead)->pNext;
    (*ppHead)->pNext->pPrev=(*ppTail);
    (*ppHead)->pNext=(*ppHead)->pPrev=NULL;
    free(*ppHead);
    (*ppHead)=(*ppTail)->pNext;

    return iDeleData;
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