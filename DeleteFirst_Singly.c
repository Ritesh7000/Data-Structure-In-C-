#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
int DeleteFirst(struct Node **ppHead);
void Display(struct Node *pHead);
int main(void)
{
    struct Node *pFirst = NULL;

    InsertFirst(&pFirst,10);
    InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
    Display(pFirst);
    DeleteFirst(&pFirst);
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