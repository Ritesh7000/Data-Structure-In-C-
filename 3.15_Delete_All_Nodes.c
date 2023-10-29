#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void DeleteAll(struct node **,struct node **);
void Display(struct node  *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast  = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);

    Display(pFirst,pLast);
    printf("\n After Delete = \n");
    DeleteAll(&pFirst,&pLast);
    Display(pFirst,pLast);+
    printf("\n Again Delete= \n");
    DeleteAll(&pFirst,&pLast);
 
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
void DeleteAll(struct node **ppHead, struct node **ppTail)
{
    struct node * pTemp = NULL;

    if(NULL == *ppHead)
    {
        printf("Linked List is Empty!!\n");
        return;
    }
    
    while(*ppHead != *ppTail)
    {   pTemp = *ppHead;
        *ppHead = pTemp->pNext;
        pTemp->pNext = NULL;
        free(pTemp);
        pTemp = pTemp ->pNext;
    }
    free(*ppTail);
    *ppHead = *ppTail = NULL;

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
        printf("|%d|%d|->",pHead->iData,pHead->pNext);

        pHead = pHead->pNext;
    }
    while(pHead != pTail->pNext);

    return;
}
