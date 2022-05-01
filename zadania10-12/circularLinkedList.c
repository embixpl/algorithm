#include <stdio.h>
#include <stdlib.h>
#include "circularLinkedList.h"

void push(node *head, int value)
{
    node q = malloc(sizeof(linkedListNode));
    if (*head == NULL)
    {
        *head = q;
        q->data = value;
        q->next = q;
    }
    else
    {
        q->data = (*head)->data;
        q->next = (*head)->next;
        (*head)->next = q;
        (*head)->data = value;
    }
}
void pushEnd(node *head, int value)
{
    push(head, value);
    *head = (*head)->next;
}
void pop(node *head)
{
    node q = NULL;
    if (*head != NULL)
    {
        q = (*head)->next;
        if (q == (*head)) //jednoelementowa lista
        {
            *head = NULL;
        }
        else
        {
            (*head)->data = q->data;
            (*head)->next = q->next;
        }
        free(q);
    }
}
void popEnd(node *head)
{
    if (*head == NULL)
    {
        printf("Lista jest pusta\n");
    }
    if ((*head)->next == *head)
    {
        *head = NULL;
    }
    node q = *head;
    while ((*head)->next->next != q)
    {
        head = &(*head)->next;
    }
    node r = (*head)->next;
    (*head)->next = r->next;
    free(r);
    r = NULL;
}
node find(node head, int value)
{
    node q = head;
    if (q != NULL)
    {
        while ((q->next != head) && (q->data != value))
        {
            q = q->next;
        }
        if (q->data == value)
        {
            return q;
        }
    }
    return NULL;
}
void pushBefore(node current, int value)
{
    node q = NULL;
    q = find(current, current->data);
    if (q == NULL)
    {
        printf("Nie znaleziono elementu\n");
    }
    else
    {
        push(&q, value);
    }
}
void pushAfter(node current, int value)
{
    node q = NULL;
    q = find(current, current->data);
    if (q == NULL)
    {
        printf("Nie znaleziono elementu\n");
    }
    else
    {
        push(&(q->next), value);
    }
}
void removeNode(node *head, node current)
{
    node q = NULL;
    node p = *head;
    q = find(*head, current->data);
    if (q == 0)
    {
        printf("Nie znaleziono elementu\n");
    }
    if (q != NULL)
    {
        if (q == q->next)
        {
            *head = NULL;
        }
        else if (q->next == p)
        {
            popEnd(&p);
        }
        else
        {
            if ((*head) == q->next)
            {
                head = &q;
            }
            pop(&q);
        }
    }
}

int saveToFile(node head, char *fname)
{
    FILE *plik;
    node walker = head;
    if ((plik = fopen(fname, "w")) == NULL)
    {
        exit(1);
    }
    while (walker)
    {
        fprintf(plik, "%d ", walker->data);
        if (walker->next == head)
        {
            break;
        }
        walker = walker->next;
    }
    fprintf(plik, "\n");
    fclose(plik);
    return 0;
}
node readFromFile(char *fname)
{
    FILE *plik = fopen(fname, "r");
    int val;
    node head = NULL;

    if (plik == NULL)
    {
        printf("Blad otwarcia pliku\n");
        return NULL;
    }
    while (fscanf(plik, "%d ", &val) != EOF)
    {
        pushEnd(&head, val);
    }
    fclose(plik);
    return head;
}

void printList(node head)
{
    node walker = head;
    while (walker)
    {
        printf("%d ", walker->data);
        if (walker->next == head)
        {
            break;
        }
        walker = walker->next;
    }
    printf("\n");
}
void removeEveryK(node* head,int k)
{   
    int i;

    if(*head==NULL || head==NULL)
    {
        printf("Lista jest pusta\n");
    }
    node walker=*head;
    while(walker->next!=walker)
    {
        for(i=0;i<k;i++)
        {
            walker=walker->next;
        }
    
        pop(&walker);
        *head=walker;
    }
    

}
void diffList(node* a, node* b){
    node *h_b=b;
    node temp;

    while((*b)->next!=*h_b){
        while(*a!=NULL){
            temp=find(*a, (*b)->data);
            if (temp==NULL)
            {
                 break;
            }
            else{
             pop(&temp);
            }
        }
        b=&((*b)->next);
    }
    
}