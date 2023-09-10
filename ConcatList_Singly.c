#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
void ConcatList(struct Node **ppHead1,struct Node **ppHed2);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;
    struct Node *pSecond =NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pSecond,40);
    InsertFirst(&pSecond,50);
    InsertFirst(&pSecond,60);
    Display(pFirst);
    printf("\n");
    Display(pSecond);

    printf("\n");
    ConcatList(&pFirst,&pSecond);
    Display(pFirst);
    printf("\n");
    Display(pSecond);

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

void ConcatList(struct Node **ppHead1,struct Node **ppHed2)
{
    struct Node *pTemp = NULL;

    if((*ppHed2) == NULL)
    {
        return;
    }
    if((*ppHead1) == NULL)
    {
        *ppHead1 = *ppHed2;
        *ppHed2 = NULL;
        return;
    }
    pTemp = (*ppHead1);

    while(pTemp->pNext != NULL)
    pTemp = pTemp->pNext;

    pTemp -> pNext = (*ppHed2);
    *ppHed2=NULL;

    return;
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