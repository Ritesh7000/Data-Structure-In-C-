#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
int DeleteLast(struct Node **ppHead);
void Display(struct Node *pHead);
int main(void)
{
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
   // InsertFirst(&pFirst,20);
    //InsertFirst(&pFirst,30);
    Display(pFirst);
    //printf("12345");
    DeleteLast(&pFirst);
    
    //DeleteLast(&pFirst);
    printf("\n");
    Display(pFirst);

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
int DeleteLast(struct Node **ppHead)
{
    int iDelData;
    struct Node *pTemp = NULL;
    
    if((*ppHead) == NULL)
    {
        printf("Linked List is Empty! \n");
        return -1;
    }
    if((*ppHead)->pNext==NULL)
    {
        iDelData = (*ppHead)->iData;
        free((*ppHead)->pNext);
        (*ppHead) = NULL;
        return iDelData;
    }

    pTemp = (*ppHead);
    while(pTemp ->pNext ->pNext != NULL)
    {
        pTemp = pTemp->pNext;
    }

    iDelData = pTemp -> pNext ->iData;
    free(pTemp ->pNext);
    pTemp ->pNext =NULL;
    pTemp = NULL;

    return iDelData;
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
