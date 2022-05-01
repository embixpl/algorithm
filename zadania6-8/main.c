#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "linkedList.h"
int main()
{
    node p=NULL;
    node q=NULL;
    node* uniqP=NULL;
    node* uniqQ=NULL;
    char nazwa[]="plik1.txt";
    char nazwa2[]="plik2.txt";
    p=readFromFile(nazwa);
    q=readFromFile(nazwa2);
    compare(p,q,uniqP,uniqQ);
    printList(*uniqP);
    printList(*uniqQ);
    return 0;
}