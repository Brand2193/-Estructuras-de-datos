/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos no lineales.
*/

#include "drawer.h" 
#include <iostream>
using namespace std;

/* Nota: falta implementar algunas funciones */
template <typename E> 
class HASHTABLE{
    private:
        DRAWER<E> *Array;  /* Arreglo de cajones */
        int size;
        int n;
        double chargeFactor;
        int hashKey(E);

        /* Metodos de hashing*/
        int linearScan(int);
        int quadraticScan(int);
        // @WIP
    public:
        HASHTABLE();
        ~HASHTABLE();
        HASHTABLE(int);
        double getChargeFactor();
        bool add(E, int);
        bool _delete(E);
        void print();
};

template <typename E> 
HASHTABLE<E>::HASHTABLE(){
    // TODO
}

/* Destructor */
template <typename E> 
HASHTABLE<E>::~HASHTABLE(){}

template <typename E> 
HASHTABLE<E>::HASHTABLE(int size){
    this->size = size;
    this->n = 0;
    this->Array = new DRAWER<E>[this->size];
}

/* Este metodo devuelve el factor de carga de la 
   tabla hash */
template <typename E> 
double HASHTABLE<E>::getChargeFactor(){
    return(this->n / this->size );
}

/* Este metodo devuelve una clave hash sencilla 
   para ser utilizada en alguna operacion */
template <typename E>
int HASHTABLE<E>::hashKey(E k){
    return ( k % this->size);
}

/*
    mood=1 -> Exploracion lineal
    mood=2 -> Exploracion cuadratica
*/
template <typename E> 
bool HASHTABLE<E>::add(E x, int mood){
    this->n++;
    int k = hashKey(x);
    if(!Array[k].getStatus()){
        Array[k].setData(x);
        Array[k].setStatus(true);
        return(true);
    }else{
        switch(mood){
            case 1: 
                k = linearScan(k);
                Array[k].setData(x);
                Array[k].setStatus(true);
                break;
            case 2: 
                k = quadraticScan(k);
                Array[k].setData(x);
                Array[k].setStatus(true);
                break;
        }
        return(true);
    }
}

/* FIX ME */
template <typename E>
bool HASHTABLE<E>::_delete(E x){
    int k = hashKey(x);
    if(Array[k].getStatus() && x == Array[k].getData()){
        this->n--; 
        Array[k].setStatus(false);
        return(true);
    }
    return(false);
}

/* Este metodo imprime el contenido de la tabla hash 
   en la consola */
template <typename E> 
void HASHTABLE<E>::print(){
    if(!this->n)
        cout<<"The table is empty";
    else{
        for(int i=0; i<this->size; i++){
            if(Array[i].getStatus())
                cout<<" "<<Array[i].getData()<<" ";
            else 
                cout<<" _ ";
        }
    }
}

/* Este metodo utiliza el algoritmo de exploracion 
   lineal para encontrar una posicion h_i en la tabla 
   hash la cual se encuentre libre */
template <typename E>
int HASHTABLE<E>::linearScan(int h_k){
    int h_i = h_k, i=0;
    while(Array[h_i].getStatus()){
        h_i = (h_k + i)%this->size;
        i++;
    }
    return(h_i);
}

/* Este metodo utiliza el algoritmo de exploracion 
   cuadratica para encontrar una posicion h_i en la 
   tabla hash la cual se encuentre libre */
template <typename E>
int HASHTABLE<E>::quadraticScan(int h_k){
    int h_i = h_k, i=0;
    while(Array[h_i].getStatus()){
        h_i = (h_k + i*i)%this->size;
        i++;   
    }
    return(h_i);
}