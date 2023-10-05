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
int SearchLastOccurence(struct Node *,int);

int main(void)
{
    struct Node *pFirst =NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    printf("%d",SearchLastOccurence(pFirst,20));
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

int SearchLastOccurence(struct Node *pHead,int iKey)
{
    int iPos=0;
    int iLastPos = 0;

    while(pHead != NULL)
    {
        iPos++;
        
        if((pHead)->iData == iKey)
        iLastPos = iPos;

        pHead = pHead -> pNext;
    }

    return iLastPos;
}
