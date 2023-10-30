#include<stdio.h>
#include<malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,struct node **,int);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    //InsertLast(&pFirst1,&pLast1,10);
    //InsertLast(&pFirst1,&pLast1,20);
    //InsertLast(&pFirst1,&pLast1,30);
    //InsertLast(&pFirst1,&pLast1,40);

    InsertLast(&pFirst2,&pLast2,50);
    InsertLast(&pFirst2,&pLast2,60);
    InsertLast(&pFirst2,&pLast2,70);
    InsertLast(&pFirst2,&pLast2,80);

    printf("Linked List 1st : \n");
    Display(pFirst1,pLast1);

    printf("\nLinked List 2nd : \n");
    Display(pFirst2,pLast2);

    ConcatList(&pFirst1,&pLast1,&pFirst2,&pLast2);

    printf("\nLinked List 1st : \n");
    Display(pFirst1,pLast1);

    printf("\nLinked List 2nd : \n");
    Display(pFirst2,pLast2);


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
void ConcatList(struct node **ppHead1,struct node **ppTail1,
                struct node **ppHead2,struct node **ppTail2)
{
    if(*ppHead2 == NULL)
        return ;
    if(*ppHead1 == NULL)
    {
        (*ppHead1) = (*ppHead2);
        (*ppTail1) = (*ppTail2);
        (*ppHead2)=(*ppTail2)= NULL;
        return;
    }

    (*ppTail1)->pNext = (*ppHead2);
    (*ppHead2)->pPrev = (*ppTail1);

    (*ppTail1) = (*ppTail2);

    (*ppTail1)->pNext = (*ppHead1);
    (*ppHead1)->pPrev = (*ppTail1);

    (*ppHead2)=(*ppTail2)= NULL;

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
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }
    while(pHead != pTail->pNext);
    return;
}

