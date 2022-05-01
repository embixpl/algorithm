typedef struct listNode
{
  int data;
  struct listNode* next;
  struct listNode* prev;
} doublyLinkedListNode;

typedef doublyLinkedListNode* node;

// ZADANIE 9

// Lista dwukierunkowa nieposortowana 
void push(node* head, int val); // dodawanie na początek listy
void pushEnd(node* head, int val); // dodawanie na koniec listy
int pop(node* head); // usuwanie pierwszego elementu listy i zwracanie jego wartości
int popEnd(node* head); // usuwanie ostatniego elementu listy i zwracanie jego wartości
node find(node head, int val); // odszukaj zadany element
void pushBefore(node* head, node current, int val); // dodaj element przed wskazanym
void pushAfter(node* head, node current, int val); // dodaj za wskazanym elementem
void removeNode(node* head, node current); // usuń wskazany element
node readFromFile(char *fname); // wczytaj zawartość listy z pliku
int saveToFile(node head, char *fname); // zapisz zawartość listy do pliku
void printList(node head); // wyświetl zawartość listy

// lista dwukierunkowa posortowana
node wartownik(); //wartownik pomocniczy
void addElementInOrder(node* head, int value); // dodaj element w kolejności
node findInOrder(node head, int value); // znajdowanie elementu o wskazanej wartości
void removeElementInOrder(node* head, node element); // usuwanie elementu wcześniej znalezionego
node readFromFileInOrder(char *fname); // wczytanie listy do pliku (w porządku, ale w pliku nie musi być zachowany porządek)

// UWAGA! W driverze należy dać użytkownikowi możlwość wyboru, czy chce działać na liście posortowanej czy też nie

