#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node{
    int iData;
    struct Node *pPrev;
    struct Node *pNext;
};

void Display(struct Node *pHead);
int DeleteFirst(struct Node **ppHead);
void InsertLast(struct Node **ppHead,int iNo);

int main(void)
{
    struct Node *pFirst = NULL;

    //InsertLast(&pFirst,10);
    //InsertLast(&pFirst,20);
    //InsertLast(&pFirst,30);
    InsertLast(&pFirst,40);
    Display(pFirst);
    printf("\n After Delete! \n");
    printf("%d\n",DeleteFirst(&pFirst));
    Display(pFirst);

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

int DeleteFirst(struct Node **ppHead)
{
    int iDelData;

    if(NULL == (*ppHead))
    {
        printf("Linked List is Empty!");
        return -1;
    }

    iDelData = (*ppHead) ->iData;

    if(NULL == (*ppHead)->pNext)
    {
        free(*ppHead);
        *ppHead = NULL;
        return iDelData;
    }

    (*ppHead) = (*ppHead)->pNext; //2nd becomes first
    (*ppHead) ->pPrev ->pNext = NULL; // 1st node cha next null kar
    free((*ppHead)->pPrev); // 1st node free kar
    (*ppHead)->pPrev  =NULL; //2nd node chya prev madhe null tak

    return iDelData;
}

void Display(struct Node *pHead)
{
    if(NULL == pHead)
    {
        printf("Linked List is Empty!");
        return;
    }
    while (pHead != NULL)
    {
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead->pNext;
    }
    return;
}
