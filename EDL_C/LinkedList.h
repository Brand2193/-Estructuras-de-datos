#include "Node.h"

/* Esta estructura corresponde a una 
   lista enlazada */
typedef struct linkedList {
    Node *head;
    int dataAmount;
}linkedList;

/* Esta funcion inicializa los valores de 
   una lista */
void initializeList(linkedList *list){
    (*list).head = NULL;
    (*list).dataAmount = 0;
}

/* Esta funcion sirve para insertar un 
   nuevo nodo a la lista */
void addNode(linkedList *list, int data){
    Node *node = createNode(data);
    if(!(*list).head){
        (*list).head = node;
    }else{
        node->next = (*list).head;
        ((*list).head)->prev = node;
        (*list).head = node;
    }
    (*list).dataAmount++;
}

/* Esta funcion sirve para eliminar todos 
   los nodos de la lista que coinciden con   
   el especificado */
void deleteNode(linkedList *list, int target){
    Node *aux = (*list).head;
    while(aux){
        if(aux->data == target){
            if(aux->next == NULL && aux->prev == NULL){
                free(aux);
                (*list).head = NULL;
                (*list).dataAmount = 0;
                break;
            }else if(aux->prev == NULL){
                (aux->next)->prev = NULL;
                (*list).head = aux->next;
                free(aux);
                aux = (*list).head;
                (*list).dataAmount--;
            }else if(aux->next == NULL){
                (aux->prev)->next = NULL;
                free(aux);
                (*list).dataAmount--;
                break;
            }else{
                (aux->prev)->next = aux->next;
                (aux->next)->prev = aux->prev;
                Node *auxNext = aux->next;
                free(aux);
                aux = auxNext;
                (*list).dataAmount--;
            }
        }else{
            aux = aux->next;
        }
    }
}

/* Esta funcion imprime la lista en 
   pantalla */
void printList(linkedList *list){
    Node *aux = (*list).head; 
    while(aux){
        printf(" %d ",aux->data);
        aux = aux->next;
    }
}

/* Esta funcion devuelve el tamanio 
   de una lista */
int sizeOfList(linkedList list){
    return(list.dataAmount);
}

/* Esta funcion borra todos los nodos
   que se encuentran en la lista */
void clear(linkedList *list){
    while((*list).dataAmount != 0){
        Node *aux = (*list).head;
        (*list).head = aux->next;
        free(aux);
        (*list).dataAmount--;
    }
}

/* Esta funcion devuelve el elemento 
   del indice especificado */
int getElement(linkedList list, int index){
    Node *aux = list.head;
    for(int i=0; i<index; i++)
        aux = aux->next;
   return(aux->data);
}

/* Esta funcion modifica el elemento del 
   indice indicado */
void setElement(linkedList *list, int index, int element){
    if(index > (*list).dataAmount)
        return; 
    Node *aux = (*list).head;
    for(int i=0; i<index; i++)
        aux = aux->next;
    aux->data = element;
}

/* Esta funcion ordena la lista haciendo 
   uso del algoritmo bubbleSort, aunque 
   debe prestar atencion que es un algoritmo 
   extremadamente ineficiente, por lo que uselo 
   con listas muy pequenias */
void sortList(linkedList *list){
    for(int i=0; i<(*list).dataAmount; i++){
        for(int j=0; j<(*list).dataAmount-i-1; j++){
            int x = getElement(*list, j), y = getElement(*list, j+1);
            if(x > y){
                setElement(list, j, y);
                setElement(list, j+1, x);
            }
        }
    }
}

/*
    Tome en cuenta que la mayoria de operaciones 
    expuestas aqui, tienen una complejidad O(n), 
    por lo que para valores de n suficientemente 
    grandes NO son eficientes.
*/