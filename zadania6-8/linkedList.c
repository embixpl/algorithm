#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"
#include<limits.h>
/*
    Notatka dla DM
    6. zrobione
    7. zrobione
    8. zrob


*/
///////////////////////////////////////////////////////////////////

void push(node *head, int val)
{
    node q=(node)malloc(sizeof(linkedListNode));
    q->data=val;
    q->next=*head;
    *head=q;
}
void pushEnd(node *head,int val)
{
    while(*head!=NULL && (*head)->data!=INT_MAX)
    {
        head=&((*head)->next);
    }
    push(head,val);
}
node readFromFile(char* fname)
{
    FILE *plik= fopen(fname,"r");
    int val;
    node head=NULL;
    
    if (plik == NULL) 
    {
        printf("Blad otwarcia pliku\n");
        return NULL;
    }
    while(fscanf(plik,"%d ",&val) !=EOF)
    {
        pushEnd(&head,val);    
    }
    fclose(plik);
    return head;
}
///////////////////////////////////////////////////////////////
void addElement(node* head,int value)
{
    if((*head)==NULL)
    {
        push(head,value);
    }
    else{
        while((*head) && (*head)->data!=INT_MAX && (*head)->data<value)
        {
            head=&((*head)->next);
        }
        push(head,value);
    }
}
int pop(node* head)
{
    node q=(node)malloc(sizeof(linkedListNode));
    int val;
    if(*head!=NULL)
    {
        q=*head;
        val=q->data;
        *head=q->next;
        free(q);
    }
    return val;
}
int popBack(node* head)
{
    int val;
    if(*head==NULL)
    {
        printf("Lista jest pusta\n");
        return 0;
    }
    while((*head)->next!=NULL && ((*head)->next)->data!=INT_MAX)
    {
        head=&(*head)->next;
    }
    val=(*head)->data;
    pop(head);
    return val;
}
node find(node head,int val)
{
    node walker=NULL;
    walker=head;
    if(walker==NULL)
    {
        return NULL;
    }
    while( walker->data<=val)
    {
        if(walker->data==val)
        {
            return walker;
        }
        walker=walker->next;
    }

    return NULL;
}

void removeElement(node *head,node current)
{
    while(head!=NULL &&(*head)->data!=INT_MAX && ((*head)->data!=current->data))
    {
        head=&((*head)->next);
    }
    pop(head);
    
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
node merge(node p,node q)
{
    node s=NULL;
    if(p==NULL)
    {
        return q;
    }
    else if(q == NULL)
    {
        return p;
    }
    if(p->data <= q->data)
    {
        s=p;
        s->next=merge(p->next,q);
    }
    else{
        s=q;
        s->next=merge(p,q->next);
    }
    return s;
}
// /*-------------Na potrzeby zadania 8------------*/
// void pop2(node* head)
// {
//     node q=(node)malloc(sizeof(linkedListNode));
//     if(*head!=NULL)
//     {
//         q=*head;
//         *head=q->next;
//         free(q);
//     }
// }
// /*----------------------------------------------*/
// void compare(node p,node q, node* uniqP,node* uniqQ)
// {

//     node walker=p;
//     node walker2=q;
//     node tmp=NULL;
//     while(walker->next!=NULL)
//     {
//         tmp=find(q,walker->data);
//         if(tmp==NULL)
//         {
//             addElement(uniqP,walker->data);
//         }
//         else
//         {
//             pop2(&walker);
//         }
//         walker=walker->next;
//     }
//     while(walker2->next!=NULL)
//     {
//         tmp=find(p,walker2->data);
//         if(tmp==NULL)
//         {
//             addElement(uniqQ,walker2->data);
//         }
//         else
//         {
//             pop2(&walker2);
//         }
//         walker2=walker2->next;
//     }
// }