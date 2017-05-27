#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};
void AddAfter(struct Node *head,int after, int data){
  struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
struct Node *next1,*prev;
next1 = head;
prev = NULL;
while(next1->data !=after ){
   prev = next1;
   next1 = next1->next;
}
node->next = next1->next;
next1->next = node;

}

void Deletion(struct Node **head,int data){

struct Node *next1,*prev;
next1 = *head;
prev = NULL;
if(head!= NULL && next1->data == data){
    *head =  next1->next;
    free(next1);

}
while(next1->data !=data ){
   prev = next1;
   next1 = next1->next;
}
prev->next = next1->next;
free(next1);

}
// function the add node at the ens
struct Node *AtEnd(struct Node *head,int data)
{
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    struct Node *temp = head;

    while(temp->next !=NULL)
    {
        temp= temp->next;
    }
    temp->next = node;
    return node;

}



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
    AddAfter(head,8,16);
     AtEnd(head,45);
     print(head);
     printf("\n");
     Deletion(&head,16);
     print(head);


    return 0;
}
