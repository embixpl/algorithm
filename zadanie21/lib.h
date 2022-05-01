typedef struct sort{
    int por; //porownanie
    int prze; //przestawienia
}sort;

void copy(int z[],int d[],int size);
void pokazdane(sort pomiary[], int iteruj, FILE *xyz);
int Losuj(int min, int max);

void bubbleSort(int arr[],int size,sort *pomiar);
void insertSort(int arr[],int size,sort *pomiar);
void shellSort(int arr[],int size,sort *pomiar);
void quickSort(int arr[],int poczatek,int koniec,sort *pomiar);
int partition(int arr[],int start,int koniec,sort* pomiar);