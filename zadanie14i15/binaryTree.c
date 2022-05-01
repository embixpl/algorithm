#include "binaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void show(node d,int lvl)
{
    int i;
    if(d==0)
    {
        return;
    }
    for(i=0;i<lvl;i++)
    {
        putchar('_');
    }
    printf("%p",d->word);
    show(d->right,lvl+1);
}
void printTree(node root)
{
    show(root,0);
    putchar('\n');
}
void insert(node* root, char* value)
{
    node q=NULL;
    int tmp;
    if(*root==NULL)
    {
        q=(node)malloc(sizeof(treeNode));
        q->word=value;
        q->left=NULL;
        q->right=NULL;
        *root=q;
    }
    else{
        tmp=strcmp((*root)->word,value);
        if(tmp>=0)
        {
            insert(&((*root)->left),value);
        }
        else{
            insert(&((*root)->right),value);
        }
    }
}
char* treeMax(node root)
{
    if(root!=NULL)
    {
        while(root->right!=NULL)
        {
            root=root->right;
        }
    }
    return root->word;
}
char* treeMin(node root)
{
    if(root!=NULL)
    {
        while(root->left!=NULL)
        {
            root=root->left;
        }
    }
    return root->word;
}
node* find(node* root,char* value)
{
    while(*root!=NULL)
    {
        if((*root)->word==value)
        {
            break;
        }
        int tmp=strcmp((*root)->word,value);
        if(tmp>=0)
        {
            root=&((*root)->left);
        }
        else{
            root=&((*root)->right);
        }
    }
    return root;
}
// void removeNode(node* root,char* value)
// {
//     if(*root==NULL)
//     {
//         return;
//     }
//     int tmp=strcmp((*root)->word,value);
//     if(tmp>=0)
//     {
//         removeNode((*root)->left,value);
//     }
//     else if(tmp<0){
//         removeNode((*root)->right,value);
//     }
//     else{
//         if((*root)->left==NULL)
//         {
//             node q=(*root)->right;
//             free(root);
//         }
//         else if((*root)->right==NULL)
//         {
//             node w=(*root)->left;
//             free(root);
//         }
//         node e=treeMin(root->right);
//         root->word=e->word;
//         root->right=remove

//     }
// }
void removeNode(node* root,char* value)
{
    node q=*(find(root,value));
    if(q->left==NULL && q->right==NULL)
    {
        *root=NULL;
        free(q);
    }
    if(q->left!=NULL && q->right==NULL)
    {
        *root=q->left;
        free(q);
    }
    if(q->left==NULL && q->right!=NULL)
    {
        *root=q->right;
        free(q);
    }
    if(q->left!=NULL && q->right!=NULL)
    {
        char* w=treeMax(q->left);
        q->word=w;
        node s=q;
        q=s->left;
        if(q!=NULL)
        {
            q->parent=s->parent;
            free(s);
        }
    }
}
//poprzednik
char* ancestor(node root)
{
    node q;  
    if(root==0)
    {
        return 0;
    }
    if(root->left)
    {
        return treeMax(root->left);
    }
    do{
        q=root;
        root=root->parent;
    }while(root!=NULL && root->left==q);
    return root->word;

}
//nastepnik
char* descendant(node root)
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
    return root->word;

}