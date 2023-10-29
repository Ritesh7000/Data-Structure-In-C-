#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
int DeleteFirst(struct node **,struct node **);
int DeleteLast(struct node **,struct node **);
int DeleteAtPosition(struct node **,struct node **,int);
int CountNodes(struct node *, struct node *);
void Display(struct node  *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast  = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    printf("add of pFirst= %d\n",pFirst);
    printf("add of pLast->pNext = %d\n",pLast);
    Display(pFirst,pLast);

    DeleteAtPosition(&pFirst,&pLast,2);
        DeleteAtPosition(&pFirst,&pLast,2);
    printf("\n");
    Display(pFirst,pLast);
    printf("\npFirst = %d \n",pFirst);

    printf("pLast->pNext = %d",pLast->pNext);

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
int DeleteAtPosition(struct node **ppHead,struct node **ppTail,int ipos)
{
    //int iDelData;
    int iCount;
    struct node  *pTemp1 = NULL;
    struct node  *pTemp2 = NULL;
    iCount = CountNodes(*ppHead,*ppTail);

    if(ipos <= 0 || ipos > iCount)
    {
        printf("\nPositon is Invalide!\n");
        return -1;
    }
    if(ipos == 1)
    {
       return DeleteFirst(ppHead,ppTail);
    }
    if(ipos == iCount)
    {
       return DeleteLast(ppHead,ppTail);
    }

    pTemp1 = (*ppHead);

    iCount = 1;
    while(iCount != ipos-1)
    {
        iCount++;
        pTemp1 = pTemp1 ->pNext;
    }

    pTemp2 = pTemp1 ->pNext;
    pTemp1 ->pNext = pTemp2 ->pNext;
    iCount = pTemp2 ->iData;
    pTemp2 ->pNext = NULL;
    free(pTemp2);

    return iCount;
}
int DeleteFirst(struct node **ppHead,struct node**ppTail)
{
    int iDelData;

    if((*ppHead) == NULL)
    {
        printf("Limked List is empty!\n");
        return -1;
    }
 
    iDelData = (*ppHead)->iData;

    if(*ppHead == *ppTail)
    {
        (*ppHead) ->pNext =NULL;
        free(*ppHead);
        (*ppHead) = NULL;
        (*ppTail) = NULL;
        return iDelData;
    } 

    (*ppTail)->pNext = (*ppHead)->pNext;
    (*ppHead)->pNext = NULL;
    free(*ppHead);
    (*ppHead) =(*ppTail)->pNext;

    return iDelData;
}
int DeleteLast(struct node **ppHead, struct node **ppTail)
{
    int iDelData;

    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        printf("Linked is Empty!");
        return -1;
    }

    iDelData = (*ppTail)->iData;

    if(*ppHead == *ppTail)
    {
        (*ppTail)->pNext = NULL;
        free(*ppTail);
        (*ppHead)= NULL;
        (*ppTail)= NULL;
        return iDelData;
    }

    pTemp = *ppHead;

    while(pTemp ->pNext != (*ppTail))
    {
        pTemp = pTemp ->pNext;
    }

    pTemp ->pNext = (*ppTail)->pNext;
    (*ppTail)->pNext = NULL;
    free(*ppTail);
    (*ppTail) = pTemp;
    pTemp = NULL;

    return iDelData;
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
