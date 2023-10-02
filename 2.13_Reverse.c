#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pPrev;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
void Display(struct Node *pHead);
void PhysicalReverse(struct Node **);
void Reverse(struct Node *);

int main(void)
{
    struct Node *pFirst =NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);
    InsertFirst(&pFirst,60);
    printf("Before reverse\n");
    Display(pFirst);
    printf("\nAfter Reverse:\n");
    Reverse(pFirst);
    printf("\n Parat tasach\n");
    Display(pFirst);
    return 0;
}

void InsertFirst(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;
    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed");
        return;
    }

    pNewNode ->iData =iNo;
    pNewNode ->pPrev = NULL;

    if((*ppHead) == NULL)
    {
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;       
        return;
    }

    pNewNode ->pNext= (*ppHead);
    (*ppHead)->pPrev = pNewNode;
    (*ppHead) = pNewNode;
    return;
}
void Reverse(struct Node *pHead)
{
    //PhysicalReverse(&pHead);
    //Display(pHead);
    //PhysicalReverse(&pHead);

    if(NULL == pHead)
    {
        printf("Linked is empty!");
        return;
    }
     while(pHead->pNext != NULL)
     {
        pHead = pHead -> pNext;
     }

     while(pHead != NULL)
     {
        printf("|%d|%d|%d|->",pHead->pNext,pHead->iData,pHead->pPrev);
        pHead = pHead->pPrev;
     }
  
    return;
}
void PhysicalReverse(struct Node **ppHead)
{
    struct Node *pNext = NULL;
    struct Node *pCurrent = (*ppHead);
    struct Node *pPrev = NULL;

    while(pCurrent != NULL)
    {
        pNext = pCurrent -> pNext;
        pCurrent ->pNext =pPrev;
        pCurrent ->pPrev = pNext;
        pPrev = pCurrent;
        pCurrent = pNext;
    }

    *ppHead = pPrev;

}
void Display(struct Node *pHead)
{
    if(pHead == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }
    while(pHead != NULL)
    {
        printf("->|%d|%d|%d|",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead->pNext;
    }
    return;
}