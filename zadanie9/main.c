#include<stdio.h>
#include<stdlib.h>
#include "doublyLinkedList.h"

/// menu dla listy posortowanej
void menuSort()
{
  printf("1 - dodaj element\n");
  printf("2 - odszukaj zadany element\n");
  printf("3 - usuwanie wskazanego elementu\n");
  printf("4 - wczytanie listy z pliku (sortuje przy wczytywaniu)\n");
  printf("5 - zapisz zawartosc do pliku\n");
  printf("6 - wyswietl liste\n");
  printf("0 - zakoncz dzialanie programu\n");
}
int main()
{
    int n1,zmienna,i=0;
    char nazwa[]="plik1.txt";
    node znalezionaZmienna=NULL;
    node s=wartownik();
    while(i!=1)
    {
    printf("Nastepna operacja: \n");
    menuSort();
    printf("Twoj wybor: ");
    scanf("%d",&n1);
    switch (n1)
    {
        case 0:
          i=1;
        break;
        case 1:
          printf("Jaka zmienna chcesz dodac do listy: ");
          scanf("%d",&zmienna);
          addElementInOrder(&s,zmienna);
        break;

        case 2:
          printf("Jaki element listy chcesz odszukac: ");
          scanf("%d",&zmienna);
          znalezionaZmienna=findInOrder(s,zmienna);
          if(znalezionaZmienna!=NULL){
            printf("Znaleziono element: %d\n",znalezionaZmienna->data);
          }
          else{
            printf("Nie znaleziono elementu\n");
          }
          break;

        case 3:
          printf("Jaki element chcesz usunac: ");
          scanf("%d",&zmienna);
          removeElementInOrder(&s,find(s,zmienna));
          break;
        case 4:
          printf("Wczytywanie wartosci listy z pliku\n");
          s=readFromFileInOrder(nazwa);
          printf("Wyswietlanie listy z pliku: \n");
          printList(s);
          break;
        case 5:
          printf("Zapisywanie do pliku\n");
          saveToFile(s,nazwa);
          break;

        case 6:
          printList(s);
          break;

        default:
          printf("Wybrano zla opcje\n");
          break;
        

    return 0;
  }
}
}