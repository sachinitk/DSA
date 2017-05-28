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


    void countIterative(struct Node *head){
   static int count = 0;
   struct Node* temp = head;
    while(temp !=NULL){
        count++;
        temp = temp->next;
    }
    printf("\n%d",count);
    }
    int countRecursive(struct Node* head)
    {
       if(head == NULL)
        return 0;
       return 1+ countRecursive(head->next);

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

     countIterative(head);
  int c= countRecursive(head);
    printf("%d",c);

    return 0;
}
