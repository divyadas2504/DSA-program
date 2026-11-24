#include <stdio.h>
#include <stdlib.h>
struct node
{
    int co,po;
    struct node *addr;
};
typedef struct node *NODE;
NODE insertend(NODE start,int co,int po )
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(start==NULL)
        return temp;
    cur=start;
    while(cur->addr!=NULL)
        cur=cur->addr;
    cur->addr=temp;
    return start;
}
void display(NODE start)
{
    NODE temp;
    if(start==NULL)
        printf("\n polynomial is empty");
    else
        {
        temp=start;
    while(temp->addr!=NULL)
    {
        printf("%d*x^%d+",temp->co,temp->po);
        temp=temp->addr;
    }
    printf("%d*x^%d",temp->co,temp->po);
    }
}
NODE addterm(NODE res,int co,int po)
{
    NODE temp,cur;
    temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->addr=NULL;
    if(res==NULL)
        return temp;
    cur=res;
    while(cur!=NULL)
    {
        if(cur->po==po)
        {
            cur->co=cur->co+co;
            return res;
        }
        cur=cur->addr;
    }
    if(cur==NULL)
        res=insertend(res,co,po);
    return res;
}
NODE multiply(NODE poly1,NODE poly2)
{
    NODE P1,P2,res=NULL;
    for(P1=poly1;P1!=NULL;P1=P1->addr)
    for(P2=poly2;P2!=NULL;P2=P2->addr)
    res=addterm(res,P1->co*P2->co,P1->po+P2->po);
    return res;
}
int main()
{
    NODE poly1=NULL,poly2=NULL,poly;
    int n,i,co,po;
    printf("\n read number of terms of 1st polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n read co and po of %d term:",i);
        scanf("%d%d",&co,&po);
        poly1 = insertend (poly1,co,po);
    }
    printf("\n first polynomial is\n");
    display(poly1);

    printf("\n read number of terms of 2nd polynomial:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("\n read co and po of %d term:",i);
        scanf("%d%d",&co,&po);
        poly2 = insertend (poly2,co,po);
    }
    printf("\n second polynomial is\n");
    display(poly2);

    poly=multiply(poly1,poly2);
     printf("\n the resultant polynomial is\n");
     display(poly);
    return 0;
}
