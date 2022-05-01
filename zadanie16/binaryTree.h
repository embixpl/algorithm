typedef struct tree {
    int value;
    struct tree *left;
    struct tree *right;
    struct tree *parent; //do szukania decendant
} treeNode;

typedef treeNode* node;

void insert(node* root, int val);
node treeMin(node root);
node descendant(node root);
int containSameValues(node* tree1, node* tree2);