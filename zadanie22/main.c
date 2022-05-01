#include<stdio.h>
#include<string.h>
#include"heapSort.h"
#include <time.h>
#include<stdlib.h>


int main()
{
    int i,j;
    int wyrazy=1000;
    char* tab[wyrazy];
    char litery[]="abcdefghijklmnopqrstuvwxyz";
    for(i=0;i<wyrazy;i++)
    {
        tab[i]=(char*)malloc(sizeof(char)*10);
        for(j=0;j<10;j++)
        {
            tab[i][j]=litery[rand()%(sizeof(litery)-1)];
        }
        tab[i][10]=(char)'\0';
    }
    //wyswietl(tab,wyrazy);
    hsort(tab,wyrazy);
    wyswietl(tab,wyrazy);
    return 0;
}