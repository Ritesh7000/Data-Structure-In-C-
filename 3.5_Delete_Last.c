#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
int DeleteLast(struct node**,struct node **);
void Display(struct node  *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast  = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    printf("add of pFirst =  %d\n",pFirst);
    printf("add of pLast->pNext = %d\n",pLast->pNext);
    Display(pFirst,pLast);

    printf("\n");
   
    DeleteLast(&pFirst,&pLast);
    DeleteLast(&pFirst,&pLast);
    Display(pFirst,pLast);
    printf("\npFirst = %d \n",pFirst);
    printf("\npLast = %d",pLast->pNext);

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
