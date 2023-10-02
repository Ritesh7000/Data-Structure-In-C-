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
void ConcatList(struct Node**,struct Node **);

int main(void)
{
    struct Node *pFirst =NULL;
    struct Node*pSecond = NULL;


    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);

    InsertFirst(&pSecond,40);
    InsertFirst(&pSecond,50);
    InsertFirst(&pSecond,60);
    printf("pFirst = \n");
    Display(pFirst);
    printf("\npSecond = \n");
    Display(pSecond);
    ConcatList(&pFirst,&pSecond);
    printf("\npFirst = \n");
    Display(pFirst);
    printf("\npSecond = \n");
    Display(pSecond);


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

void ConcatList(struct Node **ppHead1,struct Node **ppHead2)
{
    struct Node *pTemp = NULL;

    if((*ppHead2)== NULL)
    return;

    if((*ppHead1)==NULL)
    {
        (*ppHead1)=(*ppHead2);
        (*ppHead2)=NULL;
        return;
    }

    pTemp = (*ppHead1);
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp ->pNext;
    }
    pTemp->pNext = (*ppHead2);
    (*ppHead2) ->pPrev =pTemp;

    (*ppHead2)=NULL;
    return;
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
        printf("->|%d|",pHead->iData);
        pHead = pHead->pNext;
    }
    return;
}
