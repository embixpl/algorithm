#include<stdio.h>
#include<stdlib.h>
#include"priorityQueue.h"

/*-------------FUNKCJE NA POTRZEBY ZADANIA-------------------*/
void printList(node head)
{
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
void push(node *head, int val,int priority)
{
    node q=(node)malloc(sizeof(priorityQueueNode));
    q->data=val;
    q->next=*head;
    q->priority=priority;
    *head=q;
}
void pushEnd(node *head,int val,int priority)
{
    while(*head!=NULL)
    {
        head=&((*head)->next);
    }
    push(head,val,priority);
}
void pop(node* head)
{
    node q=(node )malloc(sizeof(priorityQueueNode));
    if(*head!=NULL)
    {
        q=*head;
        *head=q->next;
        free(q);
    }
}
/*------------------------------------------*/
void addElement(node* head,int val,int priority)
{
    if((*head)==NULL)
    {
        push(head,val,priority);
    }
    else{

        while((*head)!=NULL&&(*head)->priority>=priority)
        {

            head=&((*head)->next);
        }
        push(head,val,priority);
    }
}
node getHighestPriority(node* head)
{
    /*
        Lista jest tak skonstruowana ze
        element z najwyzszym priorytetem jest zawsze pierwszy
        w zwiazku z tym pobieram pierwszy element przestawiam head na nastepny
        i zwracam usuniety byly pierwszy element
    */
    node q=NULL;
    if((*head)==NULL)
    {
        return NULL;
    }
    else{
        q=*head;
        *head=q->next;
        q->next=NULL;
    }
    return q;
}
void changeElementPriority(node* head,int val,int priority)
{
    node walker2=*head;
    node walker=(*head)->next;
    node tmp=NULL;
    node tmp2=NULL;
    if(walker!=NULL && walker->next!=NULL)
    {
        if(walker2->data==val)
        {
            
        }
        while(walker->next!=NULL)
        {

        }
    }
}