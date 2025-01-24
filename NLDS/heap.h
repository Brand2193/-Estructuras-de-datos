#include <iostream>
using namespace std;

template <typename E>
class HEAP{
    private: 
        E *Array;
        int n;
        int size;
        E father(int i);
        E lefSon(int i);
        E rightSon(int i);
        void bubbleUp(int i);
        void bubbleDown(int i);
        void swap(int i, int j);
    public:
        HEAP();
        ~HEAP();
        HEAP(int size);
        int getDataAmount();
        void print();
        void insert(E);
        void deleteMin();
        E getMin();
};

template <typename E>
HEAP<E>::HEAP(){
    // TODO
}

/* Destructor */
template <typename E>
HEAP<E>::~HEAP(){}

/* Numero total de datos en el heap */
template <typename E>
int HEAP<E>::getDataAmount(){
    return(this->n);
}

/* Este metodo devuelve el dato minimo contenido en
   el heap */
template <typename E>
E HEAP<E>::getMin(){
    return(Array[1]);
}

template <typename E>
HEAP<E>::HEAP(int size){
    this->size = size;
    this->Array = new E[size];
    this->n = 0;
}

/* Este metodo imprime el heap en 
   la consola */
template <typename E>
void HEAP<E>::print(){
    for(int i=0; i<this->n; i++)
        cout<<" "<<Array[i+1]<<" ";
}

/* Este metodo devuelve el padre de un 
   elemento segun su indice */
template <typename E>
E HEAP<E>::father(int i){
    return(this->Array[i/2]);
}

/* Este metodo devuelve el hijo izquierdo 
   de un elemento segun su indice */
template <typename E>
E HEAP<E>::lefSon(int i){
    return(this->Array[2*i]);
}

/* Este metodo devuelve el hijo derecho 
   de un elemento segun su indice */
template <typename E> 
E HEAP<E>::rightSon(int i){
    return(this->Array[2*i+1]);
}

/* Este metodo hace un intercambio entre
   2 nodos del arbol segun sus indices */
template <typename E>
void HEAP<E>::swap(int i, int j){
    E aux = this->Array[i];
    this->Array[i] = this->Array[j]; 
    this->Array[j] = aux;
}

/* Este metodo hace uso del algoritmo 
   bubble up */
template <typename E>
void HEAP<E>::bubbleUp(int i){
    if(i>1){
        if(this->Array[i] < father(i)){
            swap(i, i/2);
            bubbleUp(i/2);
        }
    }
}

/* Este metodo hace uso del algoritmo 
   bubble down */
template <typename E>
void HEAP<E>::bubbleDown(int i){
    int min;
    if(2*i <= this->n){
        min = 2*i;
        if(2*i+1 <= this->n && Array[2*i+1]<Array[2*i])
            min = 2*i+1;

        if(Array[min] < Array[i]){
            swap(i, min);
            bubbleDown(min);
        }
    }

}

/* Este metodo inserta un nuevo elemento
   en el heap */
template <typename E>
void HEAP<E>::insert(E data){
    if(this->n == this->size)
        return;
    this->n++;
    Array[n] = data;
    bubbleUp(n);
}

/* Este elemento elimina el elemento minimo 
   del heap */
template <typename E> 
void HEAP<E>::deleteMin(){
    if(this->n > 0){
        Array[1] = Array[this->n];
        this->n--;
        bubbleDown(1);
    }
}