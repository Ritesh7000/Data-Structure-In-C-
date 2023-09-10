#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
void PhysicalReverse(struct Node **ppHead);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    printf("\n");
    PhysicalReverse(&pFirst);
    Display(pFirst);

    return 0;
}

void InsertFirst(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;

    pNewNode = (struct Node*)malloc(sizeof(struct Node));

    if(pNewNode == NULL)
    {
        printf("Memory Alloacation is Failed");
        return;
    }

    pNewNode ->iData =iNo;

    if(NULL == (*ppHead))
    {
        (*ppHead) = pNewNode;
        pNewNode ->pNext=NULL;
        return;
    }

    pNewNode ->pNext = (*ppHead);
    (*ppHead)=pNewNode;

    return;
}


void PhysicalReverse(struct Node **ppHead)
{
    struct Node *pPrev =NULL;
    struct Node *pCurrent =*ppHead;
    struct Node *pNext = NULL;


    while(pCurrent != NULL)
    {
        pNext = pCurrent->pNext;
        pCurrent -> pNext = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;       
    }
    *ppHead =pPrev;
}
void Display(struct Node *pHead)
{
    if((pHead) == NULL)
    {
        printf("Linked List is Empty!!");
        return;
    }
    while(pHead != NULL)
    {
        printf("->|%d|",pHead->iData);
        pHead = pHead ->pNext;
    }
    return;
}