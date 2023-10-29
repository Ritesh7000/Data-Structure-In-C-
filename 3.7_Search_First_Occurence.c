#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};

void InsertFirst(struct node **, struct node **,int );
void Display(struct node *, struct node *);
int SearchFirstOccurence(struct node  *,struct node *, int);

int main(void)
{
    struct node * pFirst = NULL;
    struct node * pLast = NULL;

    InsertFirst(&pFirst,&pLast,10);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,40);
    Display(pFirst,pLast);
    printf("\n");
    printf("Position = %d",SearchFirstOccurence(pFirst,pLast,30));
    return 0;
}
void InsertFirst(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }
    pNewNode ->iData = iNo;

    if((*ppHead) == NULL)
    {
            (*ppHead) = pNewNode;
            (*ppTail) = pNewNode;
            (*ppTail)->pNext = (*ppHead);
            return;
    }

    pNewNode ->pNext = (*ppHead);
    (*ppHead) = pNewNode;
    (*ppTail) ->pNext = *ppHead;

    return;
}
int SearchFirstOccurence(struct node *pHead,struct node *pTail,int iKey)
{
    int iPos=0;

    if((pHead) == NULL)
    return 0;

    do{
        iPos ++;

        if((pHead)->iData == iKey)
        return iPos;

        pHead = pHead ->pNext;
    }
    while(pHead != (pTail)->pNext);

    return 0;
}

void Display(struct node *pHead,struct node *pTail)
{

    do
    {
        printf("|%d|%d|->",pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }
    while(pHead != pTail ->pNext);
    return;
}