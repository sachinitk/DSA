#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

// Program for Depth first Traversal in case of pre-oder/In-oder/post-oder traversal of a  Binary tree
// this program also include the binary tree implementation

struct Node{
int data;
struct Node* left;
struct Node* right;
};

void inoder(struct Node* node)
{
    if(node == NULL)
    return;
    inoder(node->left);
    printf("%d->",node->data);
    inoder(node->right);


}
void preoder(struct Node* node)
{
    if(node == NULL)
    return;
    printf("%d->",node->data);
    preoder(node->left);

    preoder(node->right);


}
void postoder(struct Node* node)
{
    if(node == NULL)
    return;
    postoder(node->left);

    postoder(node->right);
    printf("%d->",node->data);

}
struct Node* newNOde(int data)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;

}

int main()
{
    struct Node* root = newNOde(6);
    root->left = newNOde(5);
    root->right = newNOde(8);
    root->left->left = newNOde(4);
    root->right->left = newNOde(7);
    root->right->right = newNOde(9);
    printf("Inoder traversal:");
    inoder(root);
    printf("Pre oder traversal:");
    preoder(root);
    printf("Post oder traversal:");
    postoder(root);


    return 0;
}
