#include<stdio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};

void InsertFirst(struct Node **ppHead,int iNo);
int DeleteLast(struct Node **ppHead);
int DeleteFirst(struct Node **ppHead);
int DeleteAtPosition(struct Node **ppHead,int iPos);
int Count(struct Node *pHead);
void Display(struct Node *pHead);

int main(void)
{
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    InsertFirst(&pFirst,40);
    InsertFirst(&pFirst,50);


    Display(pFirst);
    printf("\n");
    DeleteAtPosition(&pFirst,3);
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

int DeleteFirst(struct Node **ppHead)
{
    int iDelData;
    struct Node *pTemp = NULL;

    if((*ppHead)==NULL)
    {
        printf("Linked List is Empty! \n");
        return -1;
    }

    pTemp = (*ppHead);//pTemp ha first node var ahe

    (*ppHead) = pTemp->pNext; //*ppHead 2nd node la point kartoy ata
    iDelData = pTemp->iData;  //data kadhun ghetala
    pTemp->pNext = NULL;    //Mohmaya
    free(pTemp);              //free kela
    pTemp = NULL;              //Sanskar pointernull kela 

    return iDelData;
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
int DeleteAtPosition(struct Node **ppHead,int iPos)
{
    int iCount = 0;
    int iDelData;
    struct Node *pTemp1 = NULL;
    struct Node *pTemp2 = NULL;
    iCount = Count(*ppHead);

    if(iPos <=0 || iPos > iCount)
    {
        printf("Position is not valid! \n");
        return -1;
    }
    
    if(iPos == 1)
    {
       return DeleteFirst(ppHead);
    }

    if(iPos == iCount+1)
    {
        return DeleteLast(ppHead);
    }

    pTemp1 = (*ppHead);
    iCount =1;

    while(iPos-1 > iCount)
    {
        iCount++;
        pTemp1 = pTemp1 ->pNext;
    }

    pTemp2 = pTemp1->pNext;
    iDelData = pTemp2 -> iData;
    pTemp1->pNext = pTemp2 ->pNext;
    pTemp2 ->pNext = NULL;;
    free(pTemp2);

    return iDelData;
}

int Count(struct Node *pHead)
{
    int iCount=0;

    while(pHead != NULL)
    {
        iCount++;
        pHead = pHead ->pNext;
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