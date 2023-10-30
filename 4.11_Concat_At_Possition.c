#include<stdio.h>
#include<malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void InsertLast(struct node **,struct node **,int);
void ConcatList(struct node **,struct node **,struct node **,struct node **);
int CountNodes(struct node * , struct node *);
void ConcatAtPosition(struct node **,struct node **,struct node **,struct node **,int);
void Display(struct node *, struct node *);

int main(void)
{
    struct node *pFirst1 = NULL;
    struct node *pLast1 = NULL;
    struct node *pFirst2 = NULL;
    struct node *pLast2 = NULL;

    //InsertLast(&pFirst1,&pLast1,10);
    //InsertLast(&pFirst1,&pLast1,20);
    //InsertLast(&pFirst1,&pLast1,30);
    //InsertLast(&pFirst1,&pLast1,40);

    InsertLast(&pFirst2,&pLast2,50);
    InsertLast(&pFirst2,&pLast2,60);
    InsertLast(&pFirst2,&pLast2,70);
    InsertLast(&pFirst2,&pLast2,80);
     

    printf("Linked List 1st : \n");
    Display(pFirst1,pLast1);

    printf("\nLinked List 2nd : \n");
    Display(pFirst2,pLast2);

    ConcatAtPosition(&pFirst1,&pLast1,&pFirst2,&pLast2,0);

    printf("\nLinked List 1st : \n");
    Display(pFirst1,pLast1);

    printf("\nLinked List 2nd : \n");
    Display(pFirst2,pLast2);


    return 0;
}
void InsertLast(struct node **ppHead,struct node **ppTail,int iNo)
{
    struct node *pNewNode = NULL;

    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(pNewNode == NULL)
    {
        printf("Memory Allocation is Failed!\n");
        return;
    }

    pNewNode->iData=iNo;

    if(*ppHead == NULL)
    {
        *ppHead = pNewNode;
        *ppTail = pNewNode;
        (*ppHead)->pPrev= *ppTail;
        (*ppTail)->pNext = *ppHead;
        return;
    }

    pNewNode ->pNext = *ppHead;
    pNewNode ->pPrev = *ppTail;

    (*ppTail)->pNext = pNewNode;
    (*ppTail) = pNewNode;   
    (*ppHead)->pPrev = *ppTail; 
   
    return;
}
int CountNodes(struct node *pHead , struct node *pTail)
{
    int iCount=0;
    

    do{
        iCount++;
        pHead = pHead ->pNext;
    }while(pHead != pTail->pNext);

    return iCount;
}
void ConcatAtPosition(struct node **ppHead1,struct node **ppTail1,
                      struct node **ppHead2,struct node **ppTail2,
                      int iPos)
{
    int iCount= 0;
    struct node *pTemp =NULL;
    
    iCount = CountNodes(*ppHead1,*ppTail1);
    
    if(iPos <= 0 || iPos > iCount+1)
    {
        
        printf("\nPosition is not InValid1\n");
        return;
    }
    if(NULL == *ppHead2)
        return;

    if(iPos == iCount+1)
    {
        ConcatList(ppHead1,ppTail1,ppHead2,ppTail2);
        return;
    }
    if(iPos == 1)
    {
        ConcatList(ppHead2,ppTail2,ppHead1,ppTail1);
        *ppHead1 = *ppHead2;
        *ppTail1 = *ppTail2;
        *ppHead2 = *ppTail2 = NULL;
      
        return;
    }

    pTemp = *ppHead1;
    iCount = 1;

    while(iCount != iPos-1)
    {   
        iCount++;
        pTemp = pTemp->pNext;
    }

    (*ppTail2)->pNext = pTemp->pNext;
    pTemp->pNext->pPrev = (*ppTail2);

    pTemp->pNext = (*ppHead2);
    (*ppHead2)->pPrev = pTemp;
   
    *ppHead2=*ppTail2=NULL;

    return;
}
void ConcatList(struct node **ppHead1,struct node **ppTail1,
                struct node **ppHead2,struct node **ppTail2)
{
    if(*ppHead2 == NULL)
        return ;
    if(*ppHead1 == NULL)
    {
        (*ppHead1) = (*ppHead2);
        (*ppTail1) = (*ppTail2);
        (*ppHead2)=(*ppTail2)= NULL;
        return;
    }

    (*ppTail1)->pNext = (*ppHead2);
    (*ppHead2)->pPrev = (*ppTail1);

    (*ppTail1) = (*ppTail2);

    (*ppTail1)->pNext = (*ppHead1);
    (*ppHead1)->pPrev = (*ppTail1);

    (*ppHead2)=(*ppTail2)= NULL;

    return;
}
void Display(struct node *pHead, struct node *pTail)
{
    if(pHead == NULL)
    {
        printf("Linked List is Empty!");
        return;
    }
    do
    {
        printf("|%d|%d|%d|->",pHead->pPrev,pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }
    while(pHead != pTail->pNext);
    return;
}

