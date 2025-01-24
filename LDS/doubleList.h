#include "dynNode.h"
#include "iostream"
using namespace std;

template <typename mydata>
class DOUBLELIST{
    private: 
        NODE<mydata> *head;
        int N;
    public: 
        DOUBLELIST();
        ~DOUBLELIST();
        void viewList();
        void viewInvertedList();
        void insertStart(mydata x);
        void insertEnd(mydata x);
        bool deleteStart();
        bool deleteEnd();
        int dataAmount();
        mydata showData();
        mydata getLatest();
};

template <typename mydata>
DOUBLELIST<mydata>::DOUBLELIST(){
    this->N = 0; 
    this->head = NULL;
}

template <typename mydata>
DOUBLELIST<mydata>::~DOUBLELIST(){
    // TODO
}

template <typename mydata> 
void DOUBLELIST<mydata>::viewList(){
    if(!this->N){
        cout<<"Estructura vacia...";
        return;
    }
    NODE<mydata> *aux = this->head;
    while(aux){
        cout<<" "<<aux->getData()<<" ";
        aux = aux->getNext();
    }
    delete (aux);    
}

template <typename mydata>
void DOUBLELIST<mydata>::viewInvertedList(){
    if(!this->N){
        cout<<"Estructura vacia...";
        return;
    }
    NODE<mydata> *aux = this->head;
    while(aux->getNext()){
        aux = aux->getNext();
    }

    while(aux){
        cout<<" "<<aux->getData()<<" ";
        aux = aux->getPrev();
    }    
}

template <typename mydata>
void DOUBLELIST<mydata>::insertStart(mydata x){
    NODE<mydata> *new_node = new NODE<mydata>(x);
    if(!this->N){
        new_node->setNext(this->head);
        head = new_node;
        this->N++;
        return;
    }
    this->head->setPrev(new_node);
    new_node->setNext(this->head);
    head = new_node;
    this->N++;
}

template <typename mydata>
void DOUBLELIST<mydata>::insertEnd(mydata x){
    if(!this->N){
        insertStart(x);
        return;
    } 
    NODE<mydata> *new_node = new NODE<mydata>(x);
    NODE<mydata> *aux = this->head;
    while(aux->getNext()){
        aux = aux->getNext();
    }
    aux->setNext(new_node);
    new_node->setPrev(aux);
    this->N++;    
}

template <typename mydata>
bool DOUBLELIST<mydata>::deleteStart(){
    if(!this->N){
        return (false);
    }
    NODE<mydata> *aux = this->head;
    this->head = head->getNext();
    if(!head){
        this->N--;
        delete(aux);
        return (true);
    }
    head->setPrev(NULL);
    delete(aux);
    this->N--;
    return(true);    
}

template <typename mydata> 
bool DOUBLELIST<mydata>::deleteEnd(){
    if(this->N <= 1){
        deleteStart();
        return(true);
    }
    NODE<mydata> *aux = this->head;
    NODE<mydata> *objetive;
    for(int i=1; i<N-1; i++)
        aux = aux->getNext();
    objetive = aux->getNext();
    aux->setNext(NULL);
    this->N--;
    delete(objetive);
}

template<typename mydata> 
int DOUBLELIST<mydata>::dataAmount(){
    return(this->N);
}

template<typename mydata> 
mydata DOUBLELIST<mydata>::showData(){
    return(head->getData());
}

template<typename mydata> 
mydata DOUBLELIST<mydata>::getLatest(){
    if(!this->N)
        return 0;
    NODE<mydata> *aux = this->head;
    while(aux->getNext())
        aux = aux->getNext();
    return(aux->getData());
}