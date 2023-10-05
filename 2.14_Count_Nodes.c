#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node{
    struct Node *pPrev;
    int iData;
    struct Node *pNext;
};

void InsertLast(struct Node **ppHeadd,int iNo);
int CountNodes(struct Node *pHHead);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertLast(&pFirst,30);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,30);
    InsertLast(&pFirst,40);
    InsertLast(&pFirst,50);
    InsertLast(&pFirst,50);


    printf("pFirst is =\t");
    Display(pFirst);
    printf("\nTotal Nodes = %d\n",CountNodes(pFirst));
    
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

int CountNodes(struct Node *pHead)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
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
