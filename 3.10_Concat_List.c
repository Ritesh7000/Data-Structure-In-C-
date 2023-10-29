#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **,struct node **, int);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
void Display(struct node  *,struct node *);

int main(void)
{
    struct node *pFirst1 = NULL;
    struct node *pLast1  = NULL;

    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    InsertFirst(&pFirst1,&pLast1,10);
    InsertFirst(&pFirst1,&pLast1,20);
    InsertFirst(&pFirst1,&pLast1,30);
    InsertFirst(&pFirst1,&pLast1,40);

    InsertFirst(&pFirst2,&pLast2,50);
    InsertFirst(&pFirst2,&pLast2,60);
    InsertFirst(&pFirst2,&pLast2,70);
    InsertFirst(&pFirst2,&pLast2,80);

    printf("First CLinkedList = \n");
    Display(pFirst1,pLast1);
    printf("\nSecond CLinkedList = \n");
    Display(pFirst2,pLast2);
    
    ConcatList(&pFirst1,&pLast1,&pFirst2,&pLast2);

    printf("\nFirst CLinkedList = \n");
    Display(pFirst1,pLast1);
    printf("\nSecond CLinkedList = \n");
    Display(pFirst2,pLast2);

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
void ConcatList(struct node **ppHead1,struct node **ppTail1,struct node **ppHead2,struct node **ppTail2)
{
    if(*ppHead2 == NULL)
    return;

    if(*ppHead1 == NULL)
    {
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;

        *ppHead2 = NULL;
        *ppTail2 = NULL;

        return;
    }

    (*ppTail1) ->pNext = *ppHead2;
    (*ppTail1) = (*ppTail2);
    (*ppTail1)->pNext = (*ppHead1);

    *ppHead2 = NULL;
    *ppTail2 = NULL;
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
