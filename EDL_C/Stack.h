/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/

#include "Node.h"

/* Tipo de dato abstracto 
   que representa una pila */
typedef struct Stack{
    Node *top;
    Node *bottom;
    int dataAmount;
}Stack;


/* ------ Prototipo de las funciones ------ */
Stack createStack();
void push(char, Stack *);
void printStack(Stack);
char pop(Stack *);
int infixToPostfix(char *, char *);



/* ------- Implementacion de las funciones ----- */

/* Esta funcion devuelve una pila 
   lista para usarse */
Stack createStack(){
    Stack stack;
    stack.dataAmount = 0; 
    stack.top = NULL;
    return (stack);
}

/* Esta funcion inserta un nuevo 
   dato en la pila */
void push(char data, Stack *stack){
    if(stack->top == NULL){
        stack->top = createNode(data);
        stack->bottom = stack->top;
        stack->dataAmount++;
        return;
    }
    Node *node = createNode(data);
    node->next = stack->top;
    (stack->top)->prev = node;
    stack->top = node;
    stack->dataAmount++;
}

/* Esta funcion extrae un elemento de 
   la pila */
char pop(Stack *stack){
    if(stack->dataAmount == 0)
        return(NULL);
    Node *aux = stack->top;
    char x = aux->data;
    stack->top = aux->next;
    free(aux);
    stack->dataAmount--;
    return(x);
}

/* Esta funcion imprime la pila en 
   consola */
void printStack(Stack stack){
    Node *aux = stack.top;
    while(aux){
        printf(" %c ",aux->data);
        aux = aux->next;
    }
}

/* Esta funcion convierte una expresion infija 
   en una postfija, haciendo uso de una pila y 
   el manejo de archivos */
int infixToPostfix(char *fileNameInfix, char *fileNamePostfix){
    FILE  *pointer = fopen(fileNameInfix, "r");
    if(!pointer)
        return(0);
    char generalBuffer[20];
    char ipBuffer;
    int len;
    fscanf(pointer, "%d", &len);
    for(int i=0; i<len+1; i++){
        fscanf(pointer, "%c", &ipBuffer);
        if(i!=0){
            generalBuffer[i-1] = ipBuffer;
        }
    }
    fclose(pointer);
    pointer = fopen(fileNamePostfix, "w");
    if(!pointer)
        return(0);
    Stack stack = createStack();
    for(int i=0; i<len; i++){
        ipBuffer = generalBuffer[i];
        switch(ipBuffer){
            case '(':
            case ')':
            case '+':
            case '-':
            
        }
    }
    
}
