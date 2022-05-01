typedef struct listNode
{
  int data;
  struct listNode *next;
} node;

// ZADANIE 1
void push(node **head, int val); // dodawanie na początek listy
void pushEnd(node **head, int val); // dodawanie na koniec listy
void pop(node **head); // usuwanie pierwszego elementu listy
void popEnd(node **head); // usuwanie ostatniego elementu listy
node* find(node *head, int val); // odszukaj zadany element
void pushBefore(node **head, node *current, int val); // dodaj element przed wskazanym
void pushAfter(node **head, node *current, int val); // dodaj za wskazanym elementem
void removeNode(node **head, node *current); // usuń wskazany element
node* readFromFile(char *fname); // wczytaj zawartość listy z pliku
int saveToFile(node *head, char *fname); // zapisz zawartość listy do pliku

// ZADANIE 2
void removeAll_iteratively(node **head, int val); // usuń wszystkie wartości val z listy iteracynie
void removeAll_recursively(node **head, int val); // usuń wszystkie wartości val z listy rekurencyjnie

// ZADANIE 3
int findMostCommon(node *head); // znajdź wartość najczęściej występującą na liście

// ZADANIE 4
void usunniepodz(node **l, int k); // usuń z listy l wszystkie liczby niepodzielne przez k

// ZADANIE 5 
// W tym zadaniu można wybrać typ zwracanego parametru i argumentu funkcji, w zależności od wybranego podejścia do problemu - proszę zastąpić typ void odpowiednim typem
void revert_iteratively(node **head); // odwróć listę iteracyjnie
void revert_recursively(node **head); //odwróć listę rekurencyjnie

