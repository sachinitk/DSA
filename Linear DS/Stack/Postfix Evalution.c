#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack{
    int top;
    unsigned capacity;
    int* array;

};

int isoperand(char ch)
{

    return((ch >= 'a' && ch <='z') ||(ch >= 'A' && ch <='Z' ));
}
void push(struct Stack* stack, char ch)
{
    stack->array[++stack->top] = ch;

}
int isEmpty(struct Stack* stack)
{
    return stack->top  == -1;
}
char pop(struct Stack* stack)
{
    if(!isEmpty(stack))
    return stack->array[stack->top--];
    return '$';

    }
    char peek(struct Stack *stack)
    {
        return stack->array[stack->top];
    }




struct Stack* createstack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if(!stack)
        return NULL;
    stack->top =-1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    return stack;

}
int res(int op1,int op2, char ch){

switch (ch)
    {
    case '+': return op1 + op2;
    case '-': return op1 - op2;

    case '*': return op1 * op2;
    case '/': return op1 / op2;

    }
    return -1;

}
int infixtopostfix(char* exp)
{   int i, k,j,result,op1,op2,c;

    struct Stack* stack= createstack(strlen(exp));
    if(!stack)
        return -1;
    for(i  = 0 ; exp[i]; i++)
    {
        if(!isdigit(exp[i]))
        {
            op1 = pop(stack);
        op2 = pop(stack);
       c =  res(op1,op2, exp[i]);
       push(stack,c);
        }
        else
            push(stack,exp[i]- '0');

    }
    result = pop(stack);


return result;
}


int main()
{
    char exp[] = "99*";
   printf( "%d",infixtopostfix(exp));
    return 0;
}
