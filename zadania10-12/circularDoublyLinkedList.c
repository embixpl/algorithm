#include<stdio.h>
#include<stdlib.h>
#include"circularDoublyLinkedList.h"

void printList(node head)
{
    node walker=head;
    while(walker)
    {
        printf("%d ",walker->data);
        if(walker->next==head)
        {
            break;
        }
        walker=walker->next;
    }
    printf("\n");
}

void push(node* head,int value)
{
    node q=(node)malloc(sizeof(doublyLinkedListNode));
    if(*head==NULL)
    {
        *head=q;
        q->data=value;
        q->next=q;
        q->prev=q;
    }
    else{
        q->data=(*head)->data;
        if((*head)->next)
        {
            (*head)->next->prev=q;
            //(*head)->prev=(*head)->next;
        }
        q->next=(*head)->next;
        q->prev=*head;
        (*head)->next=q;
        (*head)->data=value;
        
        
    }
}
void pushEnd(node* head,int value)
{
    if(*head==NULL)
    {
        push(head,value);
    }
    else{
        node q=(node)malloc(sizeof(doublyLinkedListNode));
        q->data=value;
        q->prev=(*head)->prev;
        q->next=*head;
        (*head)->prev->next=q;
    }
}
void pop(node* head)
{
    node q=NULL;
    if(*head!=NULL)
    {
        q=(*head)->next;
        if(q==(*head))
        {
            *head=NULL;
        }
        else{
            (*head)->data=q->data;
            (*head)->next=q->next;
        }
        free(q);
    }
}
void popEnd(node* head)
{
    if(*head==NULL)//lista pusta
    {
        printf("Lista jest pusta\n");
    }
    if((*head)->next==*head)//lista jednoelementowa
    {
        *head=NULL;
    }
    //usuwanie wlasciwe
    node q=(*head)->prev;
    node r=q->prev;
    (*head)->next=r->next;
    r->next=*head;
    (*head)->prev=r;
    free(q);
}
node find(node head,int value)
{
    node q=head;
    if(q!=NULL)
    {
        while((q->next!=head)&&(q->data!=value))
        {
            q=q->next;
        }
        if(q->data==value)
        {
            return q;
        }
    }
    return NULL;
}
void pushBefore(node current, int value)
{
    node q=NULL;
    q=find(current,current->data);
    if(q==NULL)
    {
        printf("Nie znaleziono elementu\n");
    }
    else{
        push(&q,value);
    }
}
void pushAfter(node current, int value)
{
    node q=NULL;
    q=find(current,current->data);
    if(q==NULL)
    {
        printf("Nie znaleziono elementu\n");
    }
    else{
        push(&(q->next),value);
    }
} 
void removeNode(node* head,node current)
{
    node q=NULL;
    node p=*head;
    q=find(*head,current->data);
    if(q==0)
    {
        printf("Nie znaleziono elementu\n");
    }
    if(q!=NULL)
    {
        if(q==q->next)
        {
            *head=NULL;
        }
        else if (q->next==p)
        {
            popEnd(&p);
        }
        else{
            if((*head)==q->next)
            {
                head=&q;
            }
            pop(&q);
        }
        
    }
}
node readFromFile(char *fname)
{
    FILE *plik;
    plik=fopen(fname,"r+");
    node head=NULL;
    int val;
    while(fscanf(plik,"%d",&val)!=EOF)
    {
        pushEnd(&head,val);
    }
    return (head);
    fclose(plik);
}

int saveToFile(node head,char *fname)
{
    FILE *plik;
    node walker=head;
    if((plik=fopen(fname,"w"))==NULL)
    {
        exit(1);
    }
    while(walker!=head)
    {
        fprintf(plik,"%d ",walker->data);
        walker=walker->next;
    }
    fprintf(plik,"\n");
    fclose(plik);
    return 0;
}