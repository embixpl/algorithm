#include<stdio.h>
#include<stdlib.h>
#include"priorityQueue.h"
int main()
{
    node l=NULL;
    node tmp=NULL;
    addElement(&l,10,13);
    addElement(&l,11,12);
    addElement(&l,5,6);
    addElement(&l,13,7);
    addElement(&l,131,4);
    printList(l);
    tmp=getHighestPriority(&l);
    if(tmp!=NULL)
    {
        printf("w[%d]p[%d]\n",tmp->data,tmp->priority);
    }
    else{
        printf("Nie znaleziono elementu\n");
        
    }
    printList(l);
    return 0;
}