#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};

void InsertFirst(struct Node **ppHead,int iNo);
int SearchAllOccurence(struct Node *pHead, int iKey);
void Display(struct Node *pHead);


int main(void)
{
    int a;
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,20);
    Display(pFirst);
    ///a=SearchAllOccurence(pFirst,20);
    printf("\n %d",SearchAllOccurence(pFirst,20));

    //printf("\n %d",a);

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

int SearchAllOccurence(struct Node *pHead, int iKey)
{
    int iCount = 0;

    while(pHead != NULL)
    {
        if(pHead ->iData == iKey)
        iCount++;

        pHead= pHead ->pNext;
    }
    return iCount;
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