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


void reverse(struct Node **head)
{
    struct Node *current = *head, *prev = NULL,*temp;
    while(current!= NULL){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    *head = prev;
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
      print(head);

     // add a node after node with data value 8
    reverse(&head);
  print(head);
    return 0;
}
