#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"doublyLinkedList.h"

void push(node* head, int val)
{
    node q=malloc(sizeof(doublyLinkedListNode));
    q->data=val;
    q->next=*head;
    if(*head!=NULL)
    {
        q->prev=(*head)->prev;
        (*head)->prev=q;
    }
    else{
        q->prev=NULL;
    }
    *head=q;
}
void pushEnd(node* head, int val)
{
    node q=malloc(sizeof(doublyLinkedListNode));
    while(*head!=NULL)
    {
        q=*head;
        head=&((*head)->next);
    }
    push(head,val);
    (*head)->prev=q;
}
int pop(node* head)
{
    node q=*head;
    int val;
    if(*head!=NULL)
    {
        val=q->data;
        if(q->next!=NULL)
        {
            q->next->prev=q->prev;
        }
        *head=q->next;
        free(q);
    }
    return val;
}
int popEnd(node* head)
{
    if(*head!=NULL)
    {
        while((*head)->next!=NULL)
        {
            head=&((*head)->next);
        }
    }
    return pop(head);
}
node find(node head,int val)
{
    while((head!=NULL) && (head->data !=val))
    {
        head=head->next;
    }
    return head;
}
void pushBefore(node* head, node current,int val)
{
    while(*head!=NULL && (*head)->data!=current->data)
    {
        head=&((*head)->next);
    }
    push(head,val);
}
void pushAfter(node* head, node current,int val)
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
void removeNode(node* head,node current)
{
    while(head!=NULL && ((*head)->data!=current->data))
    {
        head=&((*head)->next);
    }
    pop(head);
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
    while(walker!=NULL && walker->data!=INT_MAX)
    {
        fprintf(plik,"%d ",walker->data);
        walker=walker->next;
    }
    fprintf(plik,"\n");
    fclose(plik);
    return 0;
}
void printList(node head)
{
    while(head!=NULL && head->data!=INT_MAX)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
//////lista dwukierunkowa posortowana
node wartownik()
{
    node w=malloc(sizeof(doublyLinkedListNode));
    w->data=INT_MAX;
    w->next=NULL;
    return w;
}
void addElementInOrder(node* head,int val)
{
    if((*head)==NULL)
    {
        push(head,val);
    }
    else{
        while((*head) && (*head)->data<val)
        {
            head=&((*head)->next);
        }
        push(head,val);
    }
}
node findInOrder(node head,int val)
{
    node walker=head;
    if(walker==NULL)
    {
        return NULL;
    }
    while(walker->data!=val)
    {
        walker=walker->next;
        if(walker==NULL)
        {
            return NULL;
        }
        
    }
    return walker;

}
void removeElementInOrder(node* head,node element)
{
    while(head!=NULL && ((*head)->data!=element->data))
    {
        head=&((*head)->next);
    }
    pop(head);
}
node readFromFileInOrder(char *fname)
{
    FILE *plik;
    plik=fopen(fname,"r+");
    node head=NULL;
    int val;
    while(fscanf(plik,"%d",&val)!=EOF)
    {
        addElementInOrder(&head,val);
    }
    return (head);
    fclose(plik);
}