#include <stdio.h>
#include <stdlib.h>
struct Node{
int data;
struct Node *next;
};

void Merge(struct Node *a , struct Node* b)
{
    struct Node* headM = NULL;
    struct Node* temp = headM ;
     if(a->data <= b->data)
        {
    temp= a;
     a = a->next;}
     else
      {
        temp= b;
          b = b->next;
      }
      headM = temp;


      while(a != NULL && b!= NULL)
      {
         if(a->data<= b->data)
        {
     temp->next= a;
     a = a->next;}
     else
      {
          temp->next = b;
          b = b->next;
      }
      temp = temp->next;
      }
        printf("\n");

        if(a!=NULL)
            temp= a;
        if(b!=NULL)
            temp = b;

     print(headM);

}




    // function to insert a node in the front
    struct Node* Append(struct Node **headA,int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->data = data;
    node->next = *headA;
    *headA = node;
    return node;

    }
      struct Node* AppendB(struct Node **headB,int data){
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->data = data;
    node->next = *headB;
    *headB = node;
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
    struct Node *headA = NULL;
  struct Node *headB = NULL;

     Append(&headA, 11); // passing reference to add
     Append(&headA, 9);
     Append(&headA, 7);
     Append(&headA, 5);
     Append(&headA, 3);
     Append(&headA, 1);
      print(headA);
      printf("\n");

    AppendB(&headB, 10); // passing reference to add
     AppendB(&headB, 8);
     AppendB(&headB, 6);
     AppendB(&headB, 4);
     AppendB(&headB, 2);
     AppendB(&headB, 0);
     print(headB);

     Merge(headA,headB);
     // add a node after node with data value 8 8

    return 0;
}
