#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node{
    int iData;
    struct Node *pPrev;
    struct Node *pNext;
};

void Display(struct Node *pHead);
void InsertLast(struct Node **ppHead,int iNo);
int SearchAllOccurence(struct Node *,int);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertLast(&pFirst,10);
    InsertLast(&pFirst,20);
    InsertLast(&pFirst,30);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,40);
    Display(pFirst);
    printf("\n");
    
    printf("%d",SearchAllOccurence(pFirst,40));

    return 0;
}

void InsertLast(struct Node **ppHead,int iNo)
{
    struct Node *pNewNode = NULL;
    struct Node *pTemp = NULL;

    pNewNode = (struct Node*)malloc(sizeof(struct Node));
    if(pNewNode == NULL)
    {
        printf("Memory Allocation is failed!");
        return;
    }

    pNewNode ->iData = iNo;
    pNewNode ->pNext = NULL;

    if(NULL == (*ppHead))
    {
        pNewNode ->pPrev = NULL;
        (*ppHead) = pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while (pTemp->pNext != NULL)
    {
        pTemp = pTemp ->pNext;
    }

    pTemp ->pNext = pNewNode;
    pNewNode ->pPrev = pTemp;
}

int SearchAllOccurence(struct Node *pHead,int iKey)
{
    int iCount=0;

    while((pHead) != NULL)
    {
        if((pHead)->iData == iKey)
        iCount++;

        pHead = (pHead) -> pNext;
    }
    return iCount;
}

void Display(struct Node *pHead)
{
    if(NULL == pHead)
    {
        printf("Linked List is Empty");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead->pNext;
    }
    return;
}
