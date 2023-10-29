#include<stdio.h>
#include<malloc.h>

struct node
{
    int iData;
    struct node *pNext;
};


void InsertFirst(struct node **,struct node **, int);
int CountNodes(struct node*,struct node*);
void Display(struct node *,struct node *);

int main(void)
{
    struct node *pFirst = NULL;
    struct node *pLast = NULL;

    Display(pFirst,pLast);
    printf("\nTotal Nodes = \t%d",CountNodes(pFirst,pLast));

    InsertFirst(&pFirst,&pLast,40);
    InsertFirst(&pFirst,&pLast,30);
    InsertFirst(&pFirst,&pLast,20);
    InsertFirst(&pFirst,&pLast,10);

    printf("\nLinked List = ");
    Display(pFirst,pLast);
    printf("\nTotal Nodes = \t%d",CountNodes(pFirst,pLast));

    return 0;
}



void InsertFirst(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNeawNode = NULL;

    pNeawNode = (struct node*)malloc(sizeof(struct node));

    if(pNeawNode == NULL)
    {
        printf("Memory Allocation is Failed!!\n");
        return;
    }

    pNeawNode ->iData =iNo;
    if(NULL == (*ppHead))
    {
        *ppHead = pNeawNode;
        *ppTail = pNeawNode;
        (*ppTail)->pNext = (*ppHead);

        return;
    }

    pNeawNode ->pNext = *ppHead;
    *ppHead = pNeawNode;
    (*ppTail)->pNext = *ppHead;

    return;

}


int CountNodes(struct node *pHead, struct node *pTail)
{
    int iCounts=0;
    if(pHead == NULL)
    {
        printf("Linked list is empty!\n");
        return iCounts;
    }

    do 
    {
        iCounts++;
        pHead = pHead ->pNext;
    }
    while((pHead) != pTail->pNext);

    return iCounts;

}

void Display(struct node *pHead, struct node *pTail)
{
     if(pHead == NULL)
    {
        printf("Linked List is Empty!\n");
        return;
    }

    do 
    {
        printf("|%d|%d|->",pHead->iData,pHead->pNext);

        pHead = pHead->pNext;
    }
    while(pHead != pTail->pNext);

    return;

}

