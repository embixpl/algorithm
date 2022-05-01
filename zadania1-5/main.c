#include<stdio.h>
#include<stdlib.h>
#include "lib.h"

void menu()
{
    printf("1 - dodaj element na poczatek listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element listy\n");
    printf("6 - dodaj nowy element przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("11 - usun z listy wszystkie wystapienia wskazanej wartosci\n");
    printf("12 - odwroc liste\n");
    printf("13 - znajdz najczesciej wystepujacy element\n");
    printf("14 - usun wszystkie liczby niepodzielne przez podana wartosc\n");
    printf("0 - zakoncz dzialanie programu\n");
}
void show(node *head)
{
    while(head !=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
int main()
{
    int n1,n2,zmienna,zmienna2,i=0;
    char nazwa[]="plik1.txt";
    node* znalezionaZmienna=NULL;
    node* s=NULL;
    node* p=NULL;
    while(i!=1)
    {
    printf("Nastepna operacja: \n");
    menu();
    printf("Twoj wybor: ");
    scanf("%d",&n1);
    switch (n1)
    {
        case 0:
          i=1;
        break;
        case 1:
          printf("Jaka zmienna chcesz dodac na poczatek listy: ");
          scanf("%d",&zmienna);
          push(&s,zmienna);
        break;
        case 2:
          printf("Jaka zmienna chcesz dodac na koniec listy: ");
          scanf("%d",&zmienna);
          pushEnd(&s,zmienna);
          break;
        case 3:
          pop(&s);
          printf("Usunieto pierwszy element listy\n");
          break;
        case 4:
          popEnd(&s);
          printf("Usunieto ostatni element listy\n");
          break;
        case 5:
          printf("Jaki element listy chcesz odszukac: ");
          scanf("%d",&zmienna);
          znalezionaZmienna=find(s,zmienna);
          if(znalezionaZmienna!=NULL){
            printf("Znaleziono element: %d\n",znalezionaZmienna->data);
          }
          else{
            printf("Nie znaleziono elementu\n");
          }
          break;
        case 6:
          printf("1 - Dodaj nowy element przed wskazanym\n");
          printf("2 - Dodaj nowy element za wskazanym\n");
          scanf("%d",&n2);
          switch(n2)
          {
            case 1:
              printf("Jaki element chcesz dodac: ");
              scanf("%d",&zmienna);
              printf("Przed jakim elementem chcesz dodac: ");
              scanf("%d",&zmienna2);
              pushBefore(&s,find(s,zmienna2),zmienna);
              break;
            case 2:
              printf("Jaki element chcesz dodac: ");
              scanf("%d",&zmienna);
              printf("Za jakim elementem chcesz dodac: ");
              scanf("%d",&zmienna2);
              pushAfter(&s,find(s,zmienna2),zmienna);
              break;
            default:
              printf("Wybrano zla opcje\n");
              break;
          }
          break;
        case 7:
          printf("Jaki element chcesz usunac: ");
          scanf("%d",&zmienna);
          removeNode(&s,find(s,zmienna));
          break;
        case 8:
          printf("Wczytywanie wartosci listy z pliku\n");
          p=readFromFile(nazwa);
          s=p;
          printf("Wyswietlanie listy z pliku: \n");
          show(p);
          break;
        case 9:
          printf("Zapisywanie do pliku\n");
          saveToFile(s,nazwa);
          break;

        case 10:
          show(s);
          break;
        case 11:
          printf("Jaki element chcesz usunac: ");
          scanf("%d",&zmienna);
          removeAll_iteratively(&s,zmienna);
          //removeAll_recursively(&s,zmienna);
          break;
        case 12:
          printf("Odwracanie listy\n");
          revert_iteratively(&s);
          //revert_recursively(&s);
          printf("Odwrocona lista:\n");
          show(s);
          break;
        case 13:
          zmienna=findMostCommon(s);
          printf("Najczesciej na liscie wystepuje wartosc: %d\n",zmienna);
          break;
        case 14:
          printf("Usuwanie elemenentow niepodzielnych przez liczbe: ");
          scanf("%d",&zmienna);
          usunniepodz(&s,zmienna);
          break;
        default:
          printf("Wybrano zla opcje\n");
          break;
        
    }
    }
    return 0;
}