/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/

#include "Node.h"
using namespace std;

template <typename E> 
class Stack{
    private:
        Node<E> *top;
        int dataAmount;
    public: 
        Stack();
        ~Stack();
        void push(E);
        E pop();
        void print();
        E peek();
        int size();
        bool isEmpty();
        void clear();
};


template <typename E>
Stack<E>::Stack(){
    this->top = NULL;
    this->dataAmount = 0;
}

/* Destructor */
template <typename E> 
Stack<E>::~Stack(){}

/* Este metodo sirve para agregar un 
   nuevo elemento a la pila */
template <typename E> 
void Stack<E>::push(E item){
    Node<E> *node = new Node<E>(item); 
    node->setNext(this->top);
    this->top = node;
    this->dataAmount++;
}

/* Este metodo sirve para extraer un 
   elemento de la pila */
template <typename E>
E Stack<E>::pop(){
    if(this->isEmpty())
        return(NULL);   // Warning
    Node<E> *aux = this->top;
    E dataTop = aux->getData();
    this->top = aux->getNext();
    free(aux);
    this->dataAmount--;
    return(dataTop);
}

/* Este metodo sirve para imprimir la 
   pila en pantalla */
template <typename E> 
void Stack<E>::print(){
    Node<E> *aux = this->top;
    while(aux){
        cout<<" "<<aux->getData()<<" ";
        aux = aux->getNext();
    }
}

/* Este metodo devuelve la cantidad 
   de elementos que se encuentran en 
   la pila */
template <typename E> 
int Stack<E>::size(){
    return(this->dataAmount);
}

/* Este metodo devuelve true si la pila 
   esta vacia y false en caso contrario */
template <typename E> 
bool Stack<E>::isEmpty(){
    if(!this->top)
        return(true);
    return(false);
}

/* Este metodo devuelve el elemento que
   se encuentra en el tope de la pila */
template <typename E>
E Stack<E>::peek(){
    if(!this->top)
        return(NULL);   // Warning
    return(top->getData());
}

/* Este metodo se encarga de vaciar 
   la pila */
template <typename E> 
void Stack<E>::clear(){
    while(!this->isEmpty()){
        this->pop();
    }
}

/* 
   Para esta implementacion, se descarta el concepto
   del maximo numero de elementos en la pila, ya que 
   es totalmente dinamica
 */