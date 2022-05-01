#include<stdio.h>
#include<stdlib.h>
#include "circularDoublyLinkedList.h"
int main()
{
    node l=NULL;
   // char nazwa[]="plik3.txt";
    int i;
    
    push(&l,13);
   // pushEnd(&l,16);
    push(&l,4);
    printList(l);
    for(i=1;i<=10;i++)
    {
        push(&l,(i+12));
    }
    // printList(l);
    // pushBefore(find(l,20),444);
    // printList(l);
    // removeNode(&l,find(l,444));
    //l=readFromFile(nazwa);
    pushEnd(&l,16);
    printList(l);
    //saveToFile(l,nazwa);

    return 0;
}