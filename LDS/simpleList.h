#include "dynNode.h"
#include "iostream"
using namespace std;

template <typename mydata>
class SIMPLELIST{
    private: 
        NODE<mydata> *head;
        int N;
    public: 
        SIMPLELIST();
        ~SIMPLELIST();
        void viewList();
        void insertStart(mydata x);
        void insertEnd(mydata x);
        bool deleteStart();
        bool deleteEnd();
        int dataAmount();
};


template <typename mydata>
SIMPLELIST<mydata>::SIMPLELIST(){
    this->N = 0;
    this->head = NULL;
}

template <typename mydata>
SIMPLELIST<mydata>::~SIMPLELIST(){
    // TODO
}

template <typename mydata> 
void SIMPLELIST<mydata>::viewList(){
    if(!this->N){
        cout<<" Lista vacia !";
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
void SIMPLELIST<mydata>::insertStart(mydata x){
    NODE<mydata> *new_node = new NODE<mydata>(x);
    new_node->setNext(this->head);
    this->head = new_node;
    this->N++;
}

template<typename mydata> 
void SIMPLELIST<mydata>::insertEnd(mydata x){
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
    this->N++;
}

template<typename mydata> 
bool SIMPLELIST<mydata>::deleteStart(){
    if(!this->N)
        return (false);
    NODE<mydata> *aux = this->head;
    this->head  = head->getNext();
    delete (aux);
    this->N--;
    return (true);
}

template<typename mydata> 
bool SIMPLELIST<mydata>::deleteEnd(){
    if(this->N < 1){
        deleteStart();
        return (true);
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
int SIMPLELIST<mydata>::dataAmount(){
    return(this->N);
}