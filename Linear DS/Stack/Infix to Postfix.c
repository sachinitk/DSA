#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Stack{
    int top;
    unsigned capacity;
    char* array;

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

    int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
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
int infixtopostfix(char* exp)
{   int i, k,j;
for(j = 0; exp[j]; j++)
        printf("%c",exp[j]);


    struct Stack* stack= createstack(strlen(exp));
    for( i = 0 , k=-1; exp[i];i++)
    {
        if(isoperand(exp[i]))
        exp[++k]= exp[i];

        else if(exp[i] == '(')
                push(stack,exp[i]);

            else if(exp[i]== ')')
            {

                while(!isEmpty(stack) && peek(stack)!= '(')
                        exp[++k] = pop(stack);

                   if (!isEmpty(stack) && peek(stack) != '(')
                return -1  ;
                else pop(stack);
            }

                 else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop(stack);
            push(stack, exp[i]);
        }

           /* for(j = 0; exp[j]; j++)
        printf("%c",exp[j]);
        printf("\n");*/
            }
            while (!isEmpty(stack))
        exp[++k] = pop(stack );


    exp[++k] = '\0';

    for(j = 0; exp[j]; j++)
        printf("%c",exp[j]);


}


int main()
{
    char exp[] = "a+b(c^d-e)^(f+g*h)-i";
    infixtopostfix(exp);
    return 0;
}
