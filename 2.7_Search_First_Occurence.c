#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct node{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};
void InsetFirst(struct node **,int);
int DeleteLast(struct node**);
void Display(struct node*);
int SearchFirst(struct node*,int);

int main(void)
{
    struct node *pFirst =NULL;

    InsetFirst(&pFirst,10);
    InsetFirst(&pFirst,20);
    InsetFirst(&pFirst,30);
    Display(pFirst);
    DeleteLast(&pFirst);
    printf("\n");
    Display(pFirst);
    printf("%d",SearchFirst(pFirst,40));

    return 0;
}
void InsetFirst(struct node **ppHead,int iNo)
{
    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!!");;
        return;
    }

    pNewNode->iData=iNo;
    pNewNode->pPrev=NULL;

    if(*ppHead == NULL)
    {
        pNewNode->pNext=NULL;
        (*ppHead) = pNewNode;
        return;
    }

    pNewNode->pNext=(*ppHead);
    (*ppHead)->pPrev=pNewNode;
    *ppHead=pNewNode;
    return;
}
int DeleteLast(struct node**ppHead)
{
    int iDelData;
    struct node *pTemp = NULL;

    if(*ppHead == NULL)
    {
        printf("list is empty!");
        return -1;
    }
    if((*ppHead)->pNext == NULL)
    {
        iDelData = (*ppHead)->iData;
        free(*ppHead);
        *ppHead = NULL;
        return iDelData;
    }
    pTemp = (*ppHead);
    while(pTemp ->pNext ->pNext != NULL)
    {
        pTemp = pTemp ->pNext;
    }
    iDelData = pTemp ->pNext ->iData;
    pTemp ->pNext ->pPrev = NULL;
    free(pTemp ->pNext);
    pTemp ->pNext = NULL;

    return iDelData;
}
void Display(struct node*pHead)
{
    while(pHead != NULL)
    {
        printf("|%d|->",pHead->iData);
        pHead = pHead->pNext;
    }
    return;
}
int SearchFirst(struct node*pHead,int iKey)
{
    int iPos=0;

    while(pHead != NULL)
    {
        iPos++;

        if((pHead)->iData == iKey)
        return iPos;

        pHead = (pHead) ->pNext;
    }
    if(NULL==pHead)
    iPos = 0;

    return iPos;
}