#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertLast(struct Node **ppHead,int iNo);
void Display(struct Node *pHead);
int main(void)
{
    struct Node *pFirst = NULL;

    InsertLast(&pFirst,10);
    InsertLast(&pFirst,20);
    InsertLast(&pFirst,30);
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
        printf("Memory Alloacation is Failed");
        return;
    }

    pNewNode ->iData =iNo;
    pNewNode ->pNext=NULL;

    if(NULL == (*ppHead))
    {
        (*ppHead) = pNewNode;
        return;
    }

    pTemp = (*ppHead);
    while(pTemp->pNext!=NULL)
    {
       (pTemp)=(pTemp)->pNext;
    }

    pTemp->pNext = pNewNode;
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