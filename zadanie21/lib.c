#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

void bubbleSort(int arr[],int size,sort* pomiar)
{
    int i,j,tmp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=tmp;
                pomiar->prze+=2;
            }
            pomiar->por+=2;
        }
    }
}
void insertSort(int arr[],int size,sort *pomiar)
{
    int i,j,tmp;
    for(i=1;i<size;i++)
    {
        if(arr[i]<arr[0])
        {
            pomiar->por+=2;
            tmp=arr[0];
            arr[0]=arr[i];
            pomiar->prze+=1;
        }
        else{
            pomiar->por+=2;
            tmp=arr[i];
        }
        for(j=i-1;tmp<arr[j];j--)
        {
            pomiar->por++;
            arr[j+1]=arr[j];
            pomiar->prze++;
        }
        arr[j+1]=tmp;
        pomiar->prze++;
    }
}
void shellSort(int arr[],int size,sort *pomiar)
{
    int i,j,tmp;
    int p;//p jak przedzial, przedzial to polowa tablicy
    for(p=size/2;p>0;p/=2)
    {
        for(i=p;i<size;i++)
        {
            tmp=arr[i];
            for(j=i;j>p;j-=p)
            {
                if(tmp<arr[j-p])
                {
                    pomiar->por++;
                    arr[j]=arr[j-p];
                    pomiar->prze++;
                }
                else{
                    pomiar->por++;
                    break;
                }
                arr[j]=tmp;
                pomiar->prze++;
            }
        }
    }
}
int partition(int arr[],int start,int koniec,sort *pomiar)
{
    int x=arr[koniec];
    int i=(start-1);
    int tmp,j;
    for(j=start;j<koniec;j++)
    {
        if(arr[j]<=x)
        {
            i++;
            tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
            pomiar->prze+=3;
        }
        pomiar->por++;
    }
    tmp=arr[i+1];
    arr[i+1]=arr[koniec];
    arr[koniec]=tmp;
    pomiar->prze+=3;
    return (i+1);
}
void quickSort(int arr[],int start,int koniec,sort *pomiar)
{
    if(start<koniec)
    {
        int q=partition(arr,start,koniec,pomiar);
        quickSort(arr,start,q-1,pomiar);
        quickSort(arr,q+1,koniec,pomiar);
    }
}
int Losuj(int min, int max)
{ 
	return (rand()%(max-min+1))+min; 
}
void copy(int z[],int d[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        d[i]=z[i];
    }
}
void pokazdane(sort pomiary[], int iteruj, FILE *xyz)
{
    long int minMod = pomiary[0].prze;
    long int maxMod = pomiary[0].prze;
    long int minPor = pomiary[0].por;
    long int maxPor = pomiary[0].por;
    long int sumMod = 0;
    long int sumPor = 0;
	int i;
    for(i=0;i<iteruj;i++)
    {
        sumMod += pomiary[i].prze;
        sumPor += pomiary[i].por;
        
        if(pomiary[i].prze > maxMod)
			maxMod = pomiary[i].prze;
        if(pomiary[i].prze < minMod)
			minMod = pomiary[i].prze;
        if(pomiary[i].por > maxPor)
			maxPor = pomiary[i].por;
        if(pomiary[i].por < minPor)
			minPor = pomiary[i].por;
    }
    double sredniaMod =(sumMod*1.0)/(iteruj*1.0);
    double sredniaPor =(sumPor*1.0)/(iteruj*1.0);
    printf("Ilosc porownan:      (MAX | MIN | SRE):   %ld | %ld | %.2lf\n",maxPor,minPor,sredniaPor);
    fprintf(xyz,"Ilosc porownan:      (MAX | MIN | SRE):   %ld | %ld | %.2lf\n",maxPor,minPor,sredniaPor);
    printf("Ilosc modyfikacji:   (MAX | MIN | SRE):   %ld | %ld | %.2lf\n",maxMod,minMod,sredniaMod);
    fprintf(xyz,"Ilosc modyfikacji:   (MAX | MIN | SRE):   %ld | %ld | %.2lf\n",maxMod,minMod,sredniaMod);
}