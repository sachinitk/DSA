#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};



    // function to insert a node in the front
    struct Node* Append(struct Node **head,int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->data = data;
    node->next = *head;
    *head = node;
    return node;

    }
    void print(struct Node *node){
    while(node!=NULL)
    {
    printf("%d\t",node->data);
    node= node->next;
    }
    }


int searchR(struct Node* node, int data)
{
    static int count = 0;
    if(node == NULL)
        return -1;
     else if(node->data == data)
        return count;
        else{
        count++;
        searchR(node->next,data);

        }



}
int search(struct Node* node, int data)
{
    int count = 0 ;
       while(node->data != data  && node != NULL)
       {node= node->next;
            count++;
       }
       if(node == NULL)
        return -1;
       else return count;

}

int main()
{
    struct Node *head = NULL;

     Append(&head, 5); // passing reference to add
     Append(&head, 6);
     Append(&head, 7);
     Append(&head, 8);
     Append(&head, 9);
     Append(&head, 10);
     // add a node after node with data value 8

   int c  = search(head,8);
    if(c ==-1 )
        printf("\nelement not in the linked list");
    else
        printf("\nElement found at position %d : \t" , c);
        int cR  = searchR(head,8);
    if(cR ==-1 )
        printf("\nelement not in the linked list");
    else
        printf("\nElement found at position %d : \t" , cR);
    return 0;
}
