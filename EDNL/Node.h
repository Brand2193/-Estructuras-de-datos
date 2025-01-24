/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos no lineales.
*/

#include <iostream>
using namespace std;

template <typename E> 
class Node{
    private:
        E data;
        Node *father;
        Node *leftSon;
        Node *rightSon;
    public:
        Node();
        ~Node();
        Node(E);
        Node<E> *getLeftSon();
        Node<E> *getRightSon();
        Node<E> *getFather();
        E getData();
        void setData(E);
        void setLeftSon(Node<E> *);
        void setRightSon(Node<E> *);
        void setFather(Node<E> *);
        bool isLeaf();
        bool onlyOneSon();
};

template <typename E>
Node<E>::Node(){
    this->rightSon = NULL;
    this->leftSon = NULL;
}

/* Destructor */
template <typename E>
Node<E>::~Node(){}

template <typename E>
Node<E>::Node(E data){
    this->father = NULL;
    this->rightSon = NULL; 
    this->leftSon = NULL; 
    this->data = data;
}

template <typename E>
Node<E> *Node<E>::getLeftSon(){
    return(this->leftSon);
}

template <typename E>
Node<E> *Node<E>::getRightSon(){
    return(this->rightSon);
}

template <typename E>
Node<E> *Node<E>::getFather(){
    return(this->father);
}

template <typename E>
E Node<E>::getData(){
    return(this->data);
}

template <typename E>
void Node<E>::setLeftSon(Node<E> *node){
    this->leftSon = node;
}

template <typename E>
void Node<E>::setRightSon(Node<E> *node){
    this->rightSon = node;
}

template <typename E>
void Node<E>::setFather(Node<E> *node){
    this->father = node;
}

template <typename E>
void Node<E>::setData(E data){
    this->data = data;
}

/* Este metodo devuelve true si el nodo es una 
   hoja y false en caso contrario */
template <typename E>
bool Node<E>::isLeaf(){
    if(this->leftSon == NULL && this->rightSon == NULL)
        return(true);
    return(false);
}

/* Este metodo devuelve true si el nodo posee un
   solo hijo, y false en caso de tener ambos o 
   ninguno.

   Notese que p y q son logicamente excluyentes. */
template <typename E>
bool Node<E>::onlyOneSon(){
    bool p = this->leftSon == NULL && this->rightSon != NULL;
    bool q = this->leftSon != NULL && this->rightSon == NULL;
    if(p || q)
        return (true);
    return(false);    
}