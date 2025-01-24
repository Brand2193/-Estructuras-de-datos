/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/


#include "ListInterface.h"

template <typename E>
class LinkedList : public ListInterface<E>{
    private: 
        int dataAmount;
        Node<E> *head;
    public:
        /* Estos son los metodos mas comunes que podemos 
           identificar en listas que vienen en las bibliotecas 
           de los lenguajes de programacion */
        LinkedList();
        ~LinkedList();
        bool add(E);
        bool remove(E);
        void print();
        int size();
        bool isEmpty();
        E get(int);
        bool set(int, E);
        LinkedList<E> indexOf(E);
        bool exists(E);
        void sort();
        void clear();
};

/* Usted debe notar que varias de las operaciones que vera 
   a continuacion, son de complejidad O(n) en el mejor caso, 
   ya que se debe recorrer toda la lista para realizarlas. 
   Consecuentemente, no son eficientes */

template <typename E>
LinkedList<E>::LinkedList(){
    this->dataAmount = 0;
    this->head = NULL;
}

template <typename E>
LinkedList<E>::~LinkedList(){}

/* Este metodo añade un nuevo nodo a la lista */
template <typename E>
bool LinkedList<E>::add(E data){
    Node<E> *node = new Node<E>(data);
    if(!this->head){
        node->setNext(this->head);
        this->head = node;
    }else{
        this->head->setPrev(node);
        node->setNext(this->head);
        this->head = node; 
    }
    this->dataAmount++;
    return(true);
}

/* Este metodo imprime en consola los elementos de la 
   lista, solo en caso de ser posible */
template <typename E>
void LinkedList<E>::print(){
    Node<E> *aux = this->head; 
    while(aux){
        cout<<" "<<aux->getData()<<" ";
        aux = aux->getNext();
    }
    cout<<"\n";
}

/* Este metodo devuelve el numero de elementos que 
   hay en la lista */
template <typename E> 
int LinkedList<E>::size(){
    return(this->dataAmount);
}           

/* Este metodo devuelve TRUE si la lista esta vacia 
   y FALSE en caso contrario */
template <typename E> 
bool LinkedList<E>::isEmpty(){
    if(this->head)
        return(false);
    return(true);    
}           


/* Este metodo devuelve una lista con los indices 
   de un elemento en particular*/
template <typename E> 
LinkedList<E> LinkedList<E>::indexOf(E element){
    Node<E> *aux = this->head;
    LinkedList<int> indexList;
    for(int i=0; i<this->size(); i++){
        if(aux->getData() == element)
            indexList.add(i);
        aux = aux->getNext();
    }
    return(indexList);
}

/* Este metodo devuelve el elemento que se 
   encuentra en el indice especificado */
template <typename E>
E LinkedList<E>::get(int index){
    Node<E> *aux = this->head;
    for(int i=0; i<index; i++)
        aux = aux->getNext();
    return(aux->getData());
}

/* Este metodo modifica un elemento que se 
   encuentra en el indice especificado */
template <typename E> 
bool LinkedList<E>::set(int index, E element){
    if(index>this->size())
        return(false);
    Node<E> *aux = this->head;
    for(int i=0; i<index; i++)
        aux = aux->getNext();
    aux->setData(element);
}


/* Este metodo elimina todos los elementos de 
   la lista que coinciden con el elemento 
   indicado */
template <typename E> 
bool LinkedList<E>::remove(E element){
    Node<E> *aux = this->head;
    while(aux){
        if(aux->getData() == element){
            if(aux->getNext() == NULL && aux->getPrev() == NULL){
                free(aux);
                this->head = NULL;
                this->dataAmount--;
                break;
            }else if(aux->getPrev() == NULL){
                (aux->getNext())->setPrev(NULL);
                head = aux->getNext();
                free(aux);
                aux = this->head;
                this->dataAmount--;
            }else if(aux->getNext() == NULL){
                (aux->getPrev())->setNext(NULL);
                free(aux);
                this->dataAmount--;
                break;
            }else{
                (aux->getPrev())->setNext(aux->getNext());
                (aux->getNext())->setPrev(aux->getPrev());
                Node<E> *auxNext = aux->getNext();
                free(aux);
                aux = auxNext;
                this->dataAmount--;
                cout<<aux->getData();
            }
        }else{
            aux = aux->getNext();
        }
    }
}

/* Este metodo devuelve verdadero si el elemento 
   indicado se encuentra en la lista, en caso 
   contrario devuelve falso */
template <typename E> 
bool LinkedList<E>::exists(E element){
    Node<E> *aux = this->head; 
    while(aux){
        if(aux->getData() == element)
            return(true);
        aux = aux->getNext();
    }
    return (false);
}

/* Este metodo ordena la lista haciendo uso del 
   algoritmo bubbleSort, el cual tiene como complejidad 
   computacional Theta(n^2) en el peor y mejor caso 
   (Algoritmo super ineficiente, manejese con listas 
   muy pequenias) */
template <typename E> 
void LinkedList<E>::sort(){
    for(int i=0; i<this->size(); i++){
        for(int j=0; j<this->size()-i-1; j++){
            E x = get(j), y = get(j+1);
            if(x > y){
                this->set(j, y);
                this->set(j+1, x);
            }
        }
    }
}

/* 
   Recuerde que para el manejo de strings u otro 
   tipo de objetos, usted es el responsable de  
   modificar varios de los metodos, ya que, por 
   ejemplo, dos cadenas no se comparan simplemente 
   escribiendo cad1 == cad2 
*/