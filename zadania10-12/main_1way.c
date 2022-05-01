#include<stdio.h>
#include<stdlib.h>
#include "circularLinkedList.h"
int main()
{
    node l=NULL;
    // node l2=NULL;
    char nazwa[]="plik3.txt";
    // char nazwa2[]="plik2.txt";
    l=readFromFile(nazwa);
    //l2=readFromFile(nazwa2);
    printList(l);
    removeEveryK(&l,3);
    // printList(l2);
    // diffList(&l,&l2);
    printList(l);
    // printList(l2);
    return 0;
}