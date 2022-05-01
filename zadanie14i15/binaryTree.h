,typedef struct tree {
    char *word;
    struct tree *parent; //na potrzeby funkcji ancestor i decendant
    struct tree *left;
    struct tree *right;
} treeNode;

typedef treeNode* node;

void insert(node* root, char* value);
void removeNode(node* root, char* value);
char* treeMax(node root);
char* treeMin(node root);
char* ancestor(node root);
char* descendant(node root);
void printTree(node root);
// ZADANIE 15
void saveToFile(node root);
void readFromFile(node* root, char* filename);