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

void swapXY(struct Node **head , int x, int y)
{
    struct Node *PrevX= NULL, *CurrentX= *head,*PrevY= NULL, *CurrentY= *head,*temp; // to trace x and y
    while(CurrentX == NULL || CurrentY == NULL)
    {
        printf("\n the linked list is empty");  // if the linked list is empty
        return;
    }
    while(CurrentX->data != x && CurrentX != NULL)
    {
        PrevX = CurrentX;
        CurrentX = CurrentX->next;

    }
    while(CurrentY->data != y && CurrentY != NULL)
    {
        PrevY = CurrentY;
        CurrentY = CurrentY->next;

    }
    while(CurrentX == NULL || CurrentY == NULL)
    {
        printf("\n Either x or y or both are  not present in the list");  // if the linked list is empty
        return;
    }
    if(CurrentX == *head)
        *head = CurrentY ;
    else
        PrevX->next = CurrentY;
    if(CurrentY == *head)
        *head = CurrentX ;
    else
        PrevY->next = CurrentX;

        temp = CurrentX->next;
        CurrentX->next = CurrentY->next;
        CurrentY->next = temp;



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
    print(head);
    swapXY(&head,6,8);
    printf("\nAfter Swapping 6 & 8\n");

  print(head);
    return 0;
}
