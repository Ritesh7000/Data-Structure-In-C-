#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
int SearchFirst(struct Node *pHead,int iKey);

void Display(struct Node *pHead);
int main(void)
{
    int P;
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    Display(pFirst);

    P = SearchFirst(pFirst,20);
    printf(" \n %d",P);


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

int SearchFirst(struct Node *pHead,int iKey)
{
    int iPos = 0;

    while(pHead != NULL)
    {
        iPos++;
        if(iKey == pHead ->iData)
        break;

        pHead = pHead ->pNext;
    }
    if(NULL == pHead)
    iPos = 0;

    return iPos;
    
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