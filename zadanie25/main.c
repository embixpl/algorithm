#include<stdio.h>
#include<stdlib.h>
#define MAX 9999
#define w 10

void dijkstra(int G[w][w],int start);

int main(){


return 0;
}
void dijkstra(int G[w][w],int start)
{
    int KOSZT[w][w],DYSTANS[w],POP[w]; //koszt przejscia, dystans, poprzednik
    int ODKRYTE[w];//wierzcholki do ktr jest dotep
    int i,j,nast,min_dys,licznik;
    for(i=0;i<w;i++)
    {
        for(j=0;j<w;j++)
        {
            if(G[i][j]==0)
            {
                KOSZT[i][j]=MAX;
            }
            else
            {
                KOSZT[i][j]=G[i][j];
            }
        }
    }
    //ustawienie odkrytych poprzednikow
    for(i=0;i<w;i++)
    {
        DYSTANS[i]=KOSZT[start][i];
        POP[i]=start;
        ODKRYTE[i]=0;
    }
    DYSTANS[start]=0;
    ODKRYTE[start]=1;
    licznik=1;
    ////szukanie sciezki
    while(licznik<w-1)
    {
        min_dys=MAX;
        for(i=0;i<w;i++)
        {
            if(DYSTANS[i]<min_dys && !ODKRYTE[i])
            {
                min_dys=DYSTANS[i];
                nast=i;
            }
        }
        ODKRYTE[nast]=1;
        for(i=0;i<w;i++)
        {
            if(!ODKRYTE[i])
            {
                if(min_dys+KOSZT[nast][i]<DYSTANS[i])
                {
                    DYSTANS[i]=min_dys+KOSZT[nast][i];
                    POP[i]=nast;
                }

            }
            licznik++;
        }
    }
    //wypisanie wartosci sciezki i trasy
    for(i=0;i<w;i++)
    {
        if(i!=start)
        {
            printf("\nWartosc %d sciezki %d",i,DYSTANS[i]);
            printf("\nPrzebyta sciezka = %d",i);
            j=i;
            do
            {
                j=POP[j];
                printf(" <--- %d",j);
            }while(j!=start);
        }
    }


}