#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct Node
{
    int iData;
    struct Node *pNext;
};
void InsertFirst(struct Node **ppHead,int iNo);
void Display(struct Node *pHead);
int main(void)
{
    struct Node *pFirst = NULL;

   // InsertFirst(&pFirst,10);
    //InsertFirst(&pFirst,20);
    InsertFirst(&pFirst,30);
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

 //   if(NULL == (*ppHead))
   // {
     //   (*ppHead) = pNewNode;
       // pNewNode ->pNext=NULL;
       // return;
   // }

    pNewNode ->pNext = (*ppHead);
    (*ppHead)=pNewNode;

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
        printf("->|%d|%d|",pHead->iData,pHead->pNext);
        pHead = pHead ->pNext;
    }
    return;
}
