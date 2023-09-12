#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHed2,int iPos);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;
    struct Node *pSecond =NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    //InsertFirst(&pSecond,40);
    //InsertFirst(&pSecond,50);
    //InsertFirst(&pSecond,60);
    Display(pFirst);
    printf("\n");
    Display(pSecond);
    printf("\n");
    ConcatAtPosition(&pFirst,&pSecond,2);
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

void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos)
{
    int iCount = 1;
    struct Node *pTemp1 = NULL;
    struct Node *pTemp2 = NULL;

    //iCount = Count(ppHead1);

    if((*ppHead2) == NULL)
    return;

    if((*ppHead1) == NULL)
    {
       (*ppHead1) = (*ppHead2);
       *ppHead2 =NULL;
       return; 
    }

    pTemp1 = (*ppHead1);
    pTemp2 = (*ppHead2);
    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2 ->pNext;
    }
    while(iCount > iPos-1)
    {
        iCount++;
        pTemp1 =pTemp1->pNext;
    }
    pTemp2->pNext = pTemp1->pNext;
    pTemp1->pNext = (*ppHead2);

    *ppHead2 =NULL;

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
