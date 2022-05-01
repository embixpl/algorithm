#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

void insert(node* root, int val)
{
    node q=NULL;
    int tmp;
    if(*root==NULL)
    {
        q=(node)malloc(sizeof(treeNode));
        q->value=value;
        q->left=NULL;
        q->right=NULL;
        *root=q;
    }
    else{   
        if((*root)->value>=val)
        {
            insert(&((*root)->left),val);
        }
        else{
            insert(&((*root)->right),val);
        }
    }
}
//minimum, nastepnik i containSameValues
node treeMin(node root)
{
    if(root!=NULL)
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
    }
    return root;
}
node descendant(node root)
{
    node q;  
    if(root==0)
    {
        return 0;
    }
    if(root->right)
    {
        return treeMin(root->right);
    }
    do{
        q=root;
        root=root->parent;
    }while(root!=NULL && root->right==q);
    return root;

}
int containSameValues(node* tree1,node* tree2)
{
    node* k=treeMin(tree1);
    node* l=treeMin(tree2);
    if((*tree1)==0 && (tree2)==0)
    {
        return 1;// rowne
    }
    do
    {
        if((*k)->value !=(*l)->value)
        {
            return 0;//nierowne drzewa
        }
        k=descendant(*k);
        l=descendant(*l);

    }while((*k)!=NULL && (*l)!=NULL);
    return 1;//rowne
}
