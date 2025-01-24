template  <typename E>
class NODE_BT{
    private: 
        E data;
        NODE_BT<E> *left_son;
        NODE_BT<E> *right_son;
        NODE_BT<E> *father;
    public: 
        NODE_BT();
        ~NODE_BT();
        NODE_BT(E x);
        NODE_BT<E> *getLeft_son();
        NODE_BT<E> *getRight_son();
        E getData();
        void setLeft_son(NODE_BT<E> *node);
        void setRight_son(NODE_BT<E> *node);
        void setData(E data);

        /* Metodos sin implementar */
        void setFather(NODE_BT<E> *node);
        NODE_BT<E> *getFather();
};

template <typename E> 
NODE_BT<E>::NODE_BT(){
    this->left_son = NULL;
    this->right_son = NULL;
    this->father = NULL;
    this->data = NULL;
}

template <typename E> 
NODE_BT<E>::~NODE_BT(){
    // TODO
}

template <typename E> 
NODE_BT<E>::NODE_BT(E x){
    this->left_son = NULL; 
    this->right_son = NULL; 
    this->father = NULL; 
    this->data = x;
}

template <typename E> 
NODE_BT<E> *NODE_BT<E>::getLeft_son(){
    return(this->left_son);
}

template <typename E> 
NODE_BT<E> *NODE_BT<E>::getRight_son(){
    return(this->right_son);
}

template <typename E> 
E NODE_BT<E>::getData(){
    return(this->data);
}

template <typename E> 
void NODE_BT<E>::setLeft_son(NODE_BT<E> *node){
    this->left_son = node;
}

template <typename E> 
void NODE_BT<E>::setRight_son(NODE_BT<E> *node){
    this->right_son = node;
}

template <typename E> 
void NODE_BT<E>::setData(E x){
    this->data = x;
}

template <typename E> 
void NODE_BT<E>::setFather(NODE_BT<E> *node){
    this->father = node;
}

template <typename E> 
NODE_BT<E> *NODE_BT<E>::getFather(){
    return(this->father);
}