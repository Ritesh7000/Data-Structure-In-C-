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
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **,int);
int CountNodes(struct node*,struct node*);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    //InsertFirst(&pFirst,&pLast,10);
   // InsertFirst(&pFirst,&pLast,20);
    //InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    Display(pFirst,pLast);
    printf("\n%d\n",DeleteAtPosition(&pFirst,&pLast,1));
    Display(pFirst,pLast);

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
int DeleteAtPosition(struct node **ppHead,struct node **ppTail,int iPos)
{
    int iDelData;
    int iCount;
    struct node *pTemp = NULL;
    iCount = CountNodes(*ppHead,*ppTail);

    if(iPos <= 0 || iPos > iCount)
    {
        printf("\nPostion is Not Valid!\n");
        return 0;
    }

    if(iPos == 1)
    {
        DeleteFirst(ppHead,ppTail);
        return iDelData;
    }
    else if(iPos == iCount)
    {
        DeleteLast(ppHead,ppTail);
        return iDelData;
    }
    pTemp = (*ppHead);
    iCount = 1;
    while(iCount != iPos-1)
    {
        iCount++;   
        pTemp = pTemp->pNext;
    }

    iDelData = pTemp->pNext->iData;

    pTemp->pNext->pNext->pPrev=pTemp;
    pTemp=pTemp->pNext;
    pTemp->pPrev->pNext=pTemp->pNext;
    pTemp->pNext=pTemp->pPrev=NULL;
    free(pTemp);

    return 0;
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
int DeleteLast(struct node **ppHead,struct node **ppTail)
{
    if(*ppHead == NULL)
        return 0;
        
    int iDelData;
    iDelData = (*ppTail)->iData;

    (*ppHead)->pPrev = (*ppTail)->pPrev;
    (*ppTail)->pPrev->pNext= (*ppHead);;
   
    (*ppTail)->pNext=(*ppTail)->pPrev=NULL;
    free(*ppTail);
    (*ppTail) = (*ppHead)->pPrev;

    return iDelData;
}
int CountNodes(struct node*pHead,struct node*pTail)
{
    int iCount=0;

    do{
        iCount++;
        pHead = pHead->pNext;

    }while(pHead != pTail->pNext);

    return iCount;
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