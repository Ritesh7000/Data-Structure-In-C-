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
void DeleteAll(struct Node **ppHead);

int main(void)
{
    struct Node *pFirst =NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);

    Display(pFirst);
    DeleteAll(&pFirst);
    Display(pFirst);
    return 0;
}
void DeleteAll(struct Node **ppHead)
{
    struct Node *pTemp = NULL;

    if(NULL == (*ppHead))
    {
        printf("Linked is Empty!");
        return;
    }

    while((*ppHead) != NULL)
    {
        pTemp = (*ppHead);
        (*ppHead) = pTemp ->pNext;
        pTemp ->pNext = NULL;
        pTemp ->pPrev = NULL;
        free(pTemp);
    }

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
