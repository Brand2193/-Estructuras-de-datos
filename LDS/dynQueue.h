#include "doubleList.h"

template <typename mydata>
class QUEUE{
    private:
        DOUBLELIST<mydata> L;
    public:
        QUEUE();
        ~QUEUE();
        void enQueue(mydata x);
        void deQueue();
        void viewQueue();
        void viewInvertedQueue();
        bool isEmpty();
        int dataAmount();
        mydata consult();
};


template <typename mydata>
QUEUE<mydata>::QUEUE(){
    // TODO
}

template <typename mydata>
QUEUE<mydata>::~QUEUE(){
    while(!this->isEmpty())
        this->deQueue();
}

template <typename mydata>
void QUEUE<mydata>::enQueue(mydata x){
    L.insertEnd(x);
}

template <typename mydata>
void QUEUE<mydata>::deQueue(){
    L.deleteStart();
}

template <typename mydata>
void QUEUE<mydata>::viewQueue(){
    L.viewList();
}

template <typename mydata>
void QUEUE<mydata>::viewInvertedQueue(){
    L.viewInvertedList();
}

template <typename mydata>
bool QUEUE<mydata>::isEmpty(){
    if(!this->dataAmount())
        return (true);
    return (false);    
}

template <typename mydata>
int QUEUE<mydata>::dataAmount(){
    return(L.dataAmount());
}

template <typename mydata>
mydata QUEUE<mydata>::consult(){
    if(!this->isEmpty())
        return(L.showData());
}