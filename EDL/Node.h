/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/

template <typename E>
class Node{
    private: 
        E data;         /* Contenido del nodo*/
        Node *next;     /* Apuntador al nodo siguiente */
        Node *prev;     /* Apuntador al nodo previo */
    public:
        Node();
        Node(E);
        ~Node();
        Node<E> *getNext();
        Node<E> *getPrev();
        E getData();
        void setData(E);
        void setNext(Node<E> *);
        void setPrev(Node<E> *);
};


/* Constructor sin argumentos - 
   recuerde que para este metodo, 
   sera responsabilidad del programador 
   inicializar el atributo "data" */
template <typename E>
Node<E>::Node(){
    this->next = NULL; 
    this->prev = NULL;
}

/* Constructor con argumentos */
template <typename E> 
Node<E>::Node(E data){
    this->data = data; 
    this->prev = NULL;
    this->next = NULL;
}

/* Destructor */
template <typename E> 
Node<E>::~Node(){}

/* Metodo para cambiar el apuntador al nodo siguiente */
template <typename E> 
void Node<E>::setNext(Node<E> *node){
    this->next = node;
}

/* Metodo para cambiar el apuntador al nodo previo */
template <typename E> 
void Node<E>::setPrev(Node<E> *node){
    this->prev = node;
}

/* Metodo para obtener el apuntador al nodo siguiente */
template <typename E> 
Node<E> *Node<E>::getNext(){
    return(this->next);
}

/* Metodo para obtener el apuntador al nodo previo */
template <typename E> 
Node<E> *Node<E>::getPrev(){
    return(this->prev);
}

/* Metodo que devuelve el dato de un nodo */
template <typename E> 
E Node<E>::getData(){
    return(this->data);
}

/* Metodo para modificar el valor del dato del nodo */
template <typename E>
void Node<E>::setData(E data){
    this->data = data;
}
