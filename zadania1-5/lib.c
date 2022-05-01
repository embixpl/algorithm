#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

void push(node **head, int val)
{
    node *q=(node *)malloc(sizeof(node));
    q->data=val;
    q->next=*head;
    *head=q;
}
void pushEnd(node **head,int val)
{
    while(*head!=NULL)
    {
        head=&((*head)->next);
    }
    push(head,val);
}
void pop(node **head) //usuwanie pierwszego elementu
{
    node *q=(node *)malloc(sizeof(node));
    if(*head!=NULL)
    {
        q=*head;
        *head=q->next;
        free(q);
    }
}
void popEnd(node **head) /// usuwanie ostatniego elementu 
{
    if(*head==NULL || (*head)->next==NULL) //czy mozna uzyc funkcji free na wskaźniku ktr pokazuje na null?
    {
        free(*head);
        *head=NULL;
    }
    node* p=NULL;
    node* q=NULL;
    p=*head;
    q=(*head)->next;
    while(q->next !=NULL)
    {
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}
node* find(node *head,int val)
{
    node* walker=NULL;
    walker=head;
    if(walker==NULL)
    {
        return NULL;
    }
    while( walker !=NULL)
    {
        if(walker->data==val)
        {
            return walker;
        }
        walker=walker->next;
    }
    return NULL;
}
void pushBefore(node **head,node *current, int val) //dodaj przed wskazanym
{
    while(*head !=NULL && (*head)->data !=current->data)
    {
        head=&((*head)->next);
    }
    push(head,val);
}
void pushAfter(node **head, node *current,int val) //dodaj za wskazanym
{
    while(*head !=NULL && (*head)->data !=current->data)
    {
        head=&((*head)->next);
    }
    if(*head==NULL)
    {
        push(head,val);
    }
    else
    {
        head=&((*head)->next);
        push(head,val);
    }
}

void removeNode(node **head,node *current)//usun wskazany
{
    while(head!=NULL &&(*head)->data!=current->data)
    {
        head=&((*head)->next);
    }
    pop(head);
    
}


node* readFromFile(char *fname)
{
    FILE *plik;
    plik=fopen(fname,"r+");
    node* head=NULL;
    char list[10];
    int val;
    while(fscanf(plik,"%9s",list)==1)
    {
        val=atoi(list);
        pushEnd(&head,val);
    }
    return head;
    fclose(plik);
}
int saveToFile(node *head,char *fname)
{
    FILE *plik;
    node* walker=head;
    if((plik=fopen(fname,"w"))==NULL)
    {
        exit(1);
    }
    while(walker!=NULL)
    {
        fprintf(plik,"%d ",walker->data);
        walker=walker->next;
    }
    fprintf(plik,"\n");
    fclose(plik);
    return 0;
}
/*-----------Zadanie 2--------------*/
void removeAll_iteratively(node **head,int val)
{

    if(*head!=NULL)
    {
        while((*head)!=NULL)
        {
            if((*head)->data==val)
            {
                pop(head);
            }
            else{
                head=&((*head)->next);
            }
        }
    }
} 
void removeAll_recursively(node **head,int val)
{
    if(*head!=NULL)
    {
        if((*head)->data==val)
        {
            pop(head);
            head=&((*head)->next);
            removeAll_recursively(head,val);
        }
        else{
            head=&((*head)->next);
            removeAll_recursively(head,val);
        }
    }
}
//------------Zadanie 3---------------
int findMostCommon(node* head)
{
    if(head==NULL)
    {
        return 0;
    }
    node* q=head;
    int max=0;
    int result;
    int counter;
    while(q!=NULL)
    {
        node *p=q;
        counter=0;
        while(p!=NULL)
        {
            if(q->data==p->data)
            {
                counter++;
            }
            p=p->next;
        }    
            if(max<counter)
            {
                result=q->data;
                max=counter;
            }
            q=q->next;       
    }
        
    
    return result;
}

//------------Zadanie 4----------------

void usunniepodz(node **l,int k)
{
    node** tmp =NULL;
    while(*l!=NULL)
    {
        if(((*l)->data)%k!=0)
        {
            tmp=l;
            pop(l);
            l=tmp;
        }
        else
        {
            l=&((*l)->next);
        }
    }
}

/*------------Zadanie 5---------------*/
void revert_iteratively(node **head)
{
    node* q=NULL;
    node* r=NULL;//zmienne pomocnicze
    if(*head !=NULL)
    {
        q=(*head)->next;
        (*head)->next=NULL;
        while(q!=NULL)
        {
            r=q;
            q=q->next;
            r->next=*head;
            *head=r;
        }
    }
}
void revert_recursively(node **head)
{
    node *q=*head;
    if((*head!=NULL)&&((*head)->next!=NULL))
    {
        (*head)=(*head)->next;
        revert_recursively(head);
        q->next->next=q;
        q->next=NULL;
    }
}