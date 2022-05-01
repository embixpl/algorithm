typedef struct listNode
{
  int data;
  struct listNode *next;
} linkedListNode;

typedef linkedListNode* node; // tym razem ukrywamy jeden wskaźnik w definicji linkedListNode;

void addElement(node* head, int value); // dodaj element w kolejności
int pop(node* head); // usuwanie pierwszego elementu listy i zwracanie jego wartości
int popBack(node* head); // usuwanie ostatniego elementu listy i zwracanie jego wartości
node find(node head, int value); // znajdowanie elementu o wskazanej wartości
void removeElement(node* head, node element); // usuwanie elementu wcześniej znalezionego
void printList(node head); // wyświetlanie listy
node readFromFile(char *fname); // wczytaj zawartość listy z pliku
int saveToFile(node head, char *fname); // zapisz zawartość listy do pliku

// UWAGA! Należy dać użytkownikowi możliwość wyboru, czy lista jest z wartownikiem, czy nie, można to zrobić albo przekazując do funkcji dodatkowy parametr (np. int sentinel) lub parametr trzymając jako zmienną w bibliotece

// Zadanie 7
node merge(node p, node q); // złączenie dwóch list uporządkowanych p i q w jedną listę uporządkowaną

// Zadanie 8
void compare(node p, node q, node* uniqP, node* uniqQ); // porównanie dwóch list, uniqP zawiera elemeny unikalne dla listy P, uniqQ zawiera elementy unikalne dla listy Q