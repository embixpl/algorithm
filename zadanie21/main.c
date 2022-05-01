#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "lib.h"
int main()
{
    FILE *pomiary=NULL;
	pomiary=fopen("pomiary.txt","w");
    srand(time(NULL));
    int M = Losuj(500,1000);
    int j;
    return 0;
    sort BabelkoweTab[M];
    sort WstawianieTab[M];
    sort ShellTab[M];
    sort QSTab[M];
    for(j=0;j<M;j++)
    {
        int rozmiar=Losuj(900,1000);
        int dane[rozmiar];
        int i;
        for(i=0;i<rozmiar;i++)
        {
            dane[i]=Losuj(1,rozmiar);
        }
        sort B;
        B.por=0;
        B.prze=0;
        int *daneB=(int*)malloc(rozmiar*sizeof(int));
        copy(dane,daneB,rozmiar);
        bubbleSort(daneB,rozmiar,&B);
        free(daneB);
        daneB=NULL;
        BabelkoweTab[j].por=B.por;
        BabelkoweTab[j].prze=B.prze;


        sort I;
        I.por=0;
        I.prze=0;
        int *daneI=(int*)malloc(rozmiar*sizeof(int));
        copy(dane,daneI,rozmiar);
        insertSort(daneI,rozmiar,&I);
        free(daneI);
        daneI=NULL;
        WstawianieTab[j].por=I.por;
        WstawianieTab[j].prze=I.prze;

        sort S;
        S.por=0;
        S.prze=0;
        int *daneS=(int*)malloc(rozmiar*sizeof(int));
        copy(dane,daneS,rozmiar);
        bubbleSort(daneS,rozmiar,&S);
        free(daneS);
        daneS=NULL;
        ShellTab[j].por=S.por;
        ShellTab[j].prze=S.prze;






        sort Q;
        Q.por=0;
        Q.prze=0;
        int *daneQ=(int*)malloc(rozmiar*sizeof(int));
        copy(dane,daneQ,rozmiar);
        bubbleSort(daneQ,rozmiar,&Q);
        free(daneQ);
        daneQ=NULL;
        QSTab[j].por=Q.por;
        QSTab[j].prze=Q.prze;
    }



    printf("\nPodsumowanie:\n\n");
    fprintf(pomiary,"\nPodsumowanie:\n\n");
    printf("--------- Sortowanie Babelkowe -------------------------\n");
    fprintf(pomiary,"--------- Sortowanie Babelkowe -------------------------\n");
    pokazdane(BabelkoweTab,M,pomiary);
	printf("\n\n");
	fprintf(pomiary,"\n\n");
    printf("--------- Sortowanie przez wstawianie ------------------\n");
    fprintf(pomiary,"--------- Sortowanie przez wstawianie ------------------\n");
    pokazdane(WstawianieTab,M,pomiary);
	printf("\n\n");
	fprintf(pomiary,"\n\n");
    printf("--------- Sortowanie Shella ----------------------------\n");
    fprintf(pomiary,"--------- Sortowanie Shella ----------------------------\n");
    pokazdane(ShellTab,M,pomiary);
	printf("\n\n");
	fprintf(pomiary,"\n\n");
    printf("--------- Sortowanie Szybkie ---------------------------\n");
    fprintf(pomiary,"--------- Sortowanie Szybkie ---------------------------\n");
    pokazdane(QSTab,M,pomiary);
    fclose(pomiary);
    return 0;
}