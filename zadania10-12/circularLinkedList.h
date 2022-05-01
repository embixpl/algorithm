typedef struct listNode
{
  int data;
  struct listNode* next;
} linkedListNode;

typedef linkedListNode* node;

// ZADANIE 10 dla listy jednokierunkowej cyklicznej
void push(node* head, int value); // dodawanie na początek listy
void pushEnd(node* head, int value); // dodawanie na koniec listy
void pop(node* head); // usuwanie pierwszego elementu listy
void popEnd(node* head); // usuwanie ostatniego elementu listy
node find(node head, int value); // odszukaj zadany element
void pushBefore(node current, int val); // dodaj element przed wskazanym
void pushAfter(node current, int val); // dodaj za wskazanym elementem
void removeNode(node* head, node current); // usuń wskazany element
node readFromFile(char* fname); // wczytaj zawartość listy z pliku
int saveToFile(node head, char* fname); // zapisz zawartość listy do pliku
void printList(node head); // dodalem sobie printList dla wygody
// ZADANIE 11
void removeEveryK(node* head, int k); // usuń co k-ty element aż na liście pozostanie tylko jeden element

// ZADANIE 12
void diffList(node* a, node* b); // usuń z listy a wszystkie wystąpienia elementów z listy b
//                         ^---- dodalem gwiazdke