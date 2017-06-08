#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

struct sNode{
    char data;
    struct sNode* next;
};
int  ismatchingpair(char op1,char op2)
{
    if(op1 == '(' && op2 ==')')
        return 1;
    if(op1 == '{' && op2 =='}')
        return 1;
        if(op1 == '{' && op2 =='}')
        return 1;

 return 0;
}
void push(struct sNode **top,char data)
{
    struct sNode* newnode= (struct sNode*)malloc(sizeof(struct sNode));

    if(newnode == NULL)
    {
        printf("Stack Overfull\n");
        getchar();
        exit(0);

    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}
char pop(struct sNode** top)
{
    char res;
    struct sNode* temp;

    if(*top == NULL)
    {

        printf("stack underflow\n");
        getchar();
        exit(0);
    }
    else
    {
    temp = *top;
    res = temp->data;
    *top = temp->next;
    free(temp);
    return res;
    }
}
int isBalanced(char* exp)
{
    int i =0;
    struct sNode *stack = NULL;

    while(exp[i])
    {
        if(exp[i]=='(' ||exp[i]=='[' ||exp[i]=='{' )
            push(&stack,exp[i]);
        if(exp[i]=='}' ||exp[i]==')' ||exp[i]==']' )
            {
                if(stack == NULL)
                    return 0;
                else if(!ismatchingpair(pop(&stack),exp[i]))
                    return 0;
            }
            i++;
    }
    if(stack == NULL)
    return 1;
    else
        return 0;

}


int main()
{
    char exp[] = "2(3";

    if(isBalanced(exp))
    {
        printf("Balanced\n");
    }
    else
    printf("Not Balanced\n");

    return 0;
}
