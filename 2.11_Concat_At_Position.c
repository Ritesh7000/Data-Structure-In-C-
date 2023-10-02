#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pPrev;
    struct Node *pNext;
};

void InsertFirst(struct Node **,int);
void InsertLast(struct Node **,int);
void ConcatList(struct Node **,struct Node **);
void ConcatAtPosition(struct Node**,struct Node**,int );
void Display(struct Node *);
int CountNodes(struct Node *);

int main(void)
{
    struct Node *pFirst =NULL;
    struct Node *pSecond = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);

    InsertFirst(&pSecond,50);
    InsertFirst(&pSecond,60);
    InsertFirst(&pSecond,70);
    InsertFirst(&pSecond,80);

    printf("pFirst =\n");
    Display(pFirst);
    
    printf("\npSecond =\n");
    Display(pSecond);
    printf("abc");
    ConcatAtPosition(&pFirst,&pSecond,3);
    printf("xyz");
    ConcatAtPosition(&pFirst,&pSecond,2);

    printf("\npFirst=\n");
    Display(pFirst);

    printf("\npSecond=\n");
    Display(pSecond);


    return 0;
}
void ConcatAtPosition(struct Node **ppHead1,struct Node **ppHead2,int iPos)
{
    struct Node *pTemp1 = NULL;
    struct Node *pTemp2 = NULL;

    int iCount=0;

    iCount = CountNodes(*ppHead1);
    printf("%d\n",iCount);

    if(0>=iPos || iPos > iCount+1)
    {
        printf("position is Invalid");
        return;
    }

    if(NULL == (*ppHead2))
    return;

    if(iPos==1)
    {
        ConcatList(ppHead2,ppHead1);//1st hi 2nd la concat jhali apan add ulte pathavle
        (*ppHead1) = (*ppHead2);
        (*ppHead2) = NULL;
        return;
    }

    if(iPos == iCount+1)
    {
        ConcatList(ppHead1,ppHead2);
        return;
    }

    iCount = 1; //pTemp1 ch traverse karnyasathi ghetala
    pTemp1 = (*ppHead1);
    pTemp2 = (*ppHead2);

    while(iCount < iPos -1)
    {
        iCount++;
        pTemp1 = pTemp1 ->pNext; //pTemp1 ponting to before one node posiotn
    } 
    while(pTemp2->pNext != NULL)
    {
        pTemp2 = pTemp2 -> pNext;///pTemp2 pointing to last node
    }

    pTemp2 ->pNext = pTemp1 ->pNext;
    pTemp1 ->pNext->pPrev = pTemp2;
    pTemp1 ->pNext = (*ppHead2);
    (*ppHead2)->pPrev=pTemp1;
    
    (*ppHead2) = NULL;
    return;
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
 
int CountNodes(struct Node *pHead)
{
    int iCount=0;



    while(pHead != NULL);
    {
        iCount++;
    }
    return iCount;
}

void ConcatList(struct Node **ppHead1,struct Node **ppHead2)
{
    struct Node *pTemp = NULL;

    if((*ppHead2)== NULL)
    return;

    if((*ppHead1)==NULL)
    {
        (*ppHead1)=(*ppHead2);
        (*ppHead2)=NULL;
        return;
    }

    pTemp = (*ppHead1);
    while(pTemp->pNext != NULL)
    {
        pTemp = pTemp ->pNext;
    }
    pTemp->pNext = (*ppHead2);
    (*ppHead2) ->pPrev =pTemp;

    (*ppHead2)=NULL;
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