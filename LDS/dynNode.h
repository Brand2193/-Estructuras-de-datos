#include "iostream"

template <class mytype>
class NODE{
    private: 
        mytype data;
        NODE<mytype> *next, *prev;
        
    public: 
        NODE();
        ~NODE();
        NODE(mytype _data);
        NODE<mytype> *getNext();
        NODE<mytype> *getPrev();
        void setNext(NODE<mytype> *node);
        void setPrev(NODE <mytype> *node);
        mytype getData();
};

template <typename mytype>
NODE<mytype>::NODE(){
    this->next = NULL;
    this->prev = NULL;
}

template <typename mytype>
NODE<mytype>::~NODE(){
    // TODO
}

template <typename mytype>
NODE<mytype>::NODE(mytype _data){
    this->data = _data; 
    this->next = NULL;
    this->prev = NULL;
}

template <typename mytype> 
NODE<mytype>* NODE<mytype>::getNext(){
    return(this->next);
}

template <typename mytype>
NODE<mytype>* NODE<mytype>::getPrev(){
    return(this->prev);
}

template <typename mytype>
void NODE<mytype>::setNext(NODE<mytype> *node){
    this->next = node;
}

template <typename mytype> 
void NODE<mytype>::setPrev(NODE<mytype> *node){
    this->prev = node;
}

template <typename mytype> 
mytype NODE<mytype>::getData(){
    return(this->data);
}