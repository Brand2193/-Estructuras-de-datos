/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/

typedef struct Node{
    struct Node *next; 
    struct Node *prev;
    char data;
}Node;

/* Esta funcion sirve para crear 
   un nodo */
Node *createNode(char x){
    Node *node = (Node *)malloc(sizeof(Node));
    if(node){
        node->data = x; 
        node->next = NULL;
        node->prev = NULL;
        return (node);
    }return (NULL);
}
