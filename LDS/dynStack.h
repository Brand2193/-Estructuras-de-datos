#include "doubleList.h"

template <typename mydata>
class STACK {
    private: 
        DOUBLELIST<mydata> L;
    public:
        STACK();
        ~STACK();
        void push(mydata x);
        void viewStack();
        void viewInvertedStack();
        mydata pop();
        int dataAmount();
        bool isEmpty();
        mydata getPeek();
};


template <typename mydata>
STACK<mydata>::STACK(){
    // TODO
}

template <typename mydata>
STACK<mydata>::~STACK(){
    while(!this->isEmpty()){
        this->pop();
    }
}

template <typename mydata>
void STACK<mydata>::push(mydata x){
    L.insertEnd(x);
}

template <typename mydata>
void STACK<mydata>::viewStack(){
    L.viewList();
}

template <typename mydata>
void STACK<mydata>::viewInvertedStack(){
    L.viewInvertedList();
}

template <typename mydata>
mydata STACK<mydata>::pop(){
    mydata aux = L.getLatest();
    L.deleteEnd();
    return(aux);
}

template <typename mydata>
int STACK<mydata>::dataAmount(){
    return (L.dataAmount());
}

template <typename mydata>
bool STACK<mydata>::isEmpty(){
    if(!dataAmount())
        return(true);
    return(false);
}

template <typename mydata>
mydata STACK<mydata>::getPeek(){
    if(!this->isEmpty())
        return(L.showData());    
}