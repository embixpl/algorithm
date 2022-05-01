#include<stdio.h>
#include<string.h>
#include"heapSort.h"
#include <time.h>
#include<stdlib.h>

void heapify(char** tab,int n,int i)
{
    int largest = i;
    int l=2*i+1;
    int r=2*i+2;

    if (l < n && strcmp(tab[l], tab[largest]) > 0)
        largest = l;
    if (r < n && strcmp(tab[r], tab[largest]) > 0)
        largest = r;
    if (largest != i)
    {
        char* temp = tab[i];
        tab[i] = tab[largest];
        tab[largest] = temp;
        heapify(tab, n, largest);
    }
}


void hsort(char** tab,int n)
{
    int i;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(tab,n,i);
    }
    for(i=n-1;i>=0;i--){
        char* tmp=tab[0];
        tab[0]=tab[i];
        tab[i]=tmp;
        heapify(tab,i,0);
    }
}
void wyswietl(char** tab,int n)
{
    int i,j;
    for(i=0;i<n;++i)
    {
        for(j=0;j<=10;j++)
        {
            printf("%c",tab[i][j]);
        } 
        printf("\n");
    }
}