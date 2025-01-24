/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos no lineales.
*/

#include "Node.h"
using namespace std;

template <typename E>
class BinarySearchTree{
    private: 
        Node<E> *root;
        bool connectNode(Node<E> *, E);
        void inorder(Node<E> *);
        void preorder(Node<E> *);
        void postorder(Node<E> *);
        Node<E> *seekNode(Node<E> *, E);
    public: 
        BinarySearchTree();
        ~BinarySearchTree();
        bool isEmpty();
        bool add(E);
        bool remove(E);
        void print(int);
        Node<E> *search(E);
};

template <typename E>
BinarySearchTree<E>::BinarySearchTree(){
    this->root = NULL;
}

/* Destructor */
template <typename E>
BinarySearchTree<E>::~BinarySearchTree(){}

/* Este metodo revuelve true si el arbol esta vacio
   y false en caso contrario */
template <typename E>
bool BinarySearchTree<E>::isEmpty(){
    if(this->root)
        return(false);
    return(true);
}

/* Este metodo conecta un nuevo nodo en un arbol 
   no vacio */
template <typename E>
bool BinarySearchTree<E>::connectNode(Node<E> *node, E data){
    if(node->getData() == data){
        return(false);
    }else if(node->getData() > data){
        if(node->getLeftSon())
            return(connectNode(node->getLeftSon(), data));
        else{
            Node<E> *leaf = new Node<E>(data);
            leaf->setFather(node);
            node->setLeftSon(leaf);
            return(true);
        }
    }else if(node->getData() < data){
        if(node->getRightSon())
            return(connectNode(node->getRightSon(), data));
        else{
            Node<E> *leaf = new Node<E>(data);
            leaf->setFather(node);
            node->setRightSon(leaf);
            return(true);
        }
    }
}

/* Este metodo agrega un nuevo nodo al arbol, 
   si el nodo ya existe en el arbol, se devuelve 
   false */
template <typename E>
bool BinarySearchTree<E>::add(E data){
    if(this->isEmpty()){
        this->root = new Node<E>(data);
        (this->root)->setFather(NULL);
        return(true);
    }
    return(connectNode(this->root, data));
}

/* 
   Este metodo imprime el arbol binario de busqueda 
   usando alguno de sus recorridos. 
    mode = 1 -> inorder 
    mode = 2 -> preorder
    mode = 3 -> postorder
    default -> inorder
 */
template <typename E>
void BinarySearchTree<E>::print(int mode){
    switch(mode){
        case 1:
            this->inorder(this->root);
            break; 
        case 2: 
            this->preorder(this->root);
            break;
        case 3:
            this->postorder(this->root);
            break;
        default: 
            this->inorder(this->root);
    }
}

/* Este metodo imprime el arbol en in-orden */
template <typename E>
void BinarySearchTree<E>::inorder(Node<E> *root){
    if(!root)
        return;
    inorder(root->getLeftSon());
    cout<<root->getData()<<" ";
    inorder(root->getRightSon());
}

/* Este metodo imprime el arbol en pre-orden */
template <typename E>
void BinarySearchTree<E>::preorder(Node<E> *root){
    if(!root)
        return;
    cout<<root->getData()<<" ";
    preorder(root->getLeftSon());
    preorder(root->getRightSon());
}

/* Este metodo imprime el arbol en post-orden */
template <typename E> 
void BinarySearchTree<E>::postorder(Node<E> *root){
    if(!root)
        return;
    postorder(root->getLeftSon());
    postorder(root->getRightSon());
    cout<<root->getData()<<" ";
}

/* Este metodo busca un nodo en el arbol */
template <typename E> 
Node<E> *BinarySearchTree<E>::search(E data){
    if(this->isEmpty())
        return (NULL);
    return(this->seekNode(this->root, data));
}

/* Este metodo busca un nodo en un arbol no vacio 
   y lo devuelve */
template <typename E> 
Node<E> *BinarySearchTree<E>::seekNode(Node<E> *node, E data){
    if(node->getData() == data)
        return(node);
    else if(node->getData() > data){
            if(node->getLeftSon())
                return(seekNode(node->getLeftSon(), data));
            else
                return(NULL);
    }else if(node->getData() < data){
        if(node->getRightSon())
            return(seekNode(node->getRightSon(), data));
        else 
            return(NULL);
    }
}

/* WIP */
template <typename E> 
bool BinarySearchTree<E>::remove(E target){
    Node<E> *node = this->search(target);
    if(!node)
        return(false);
    else if(node->isLeaf()){
        if(this->root->getData() == node->getData()){
            free(node);
            this->root = NULL;
        }else if(node->getFather()->getRightSon() != NULL){
            if((node->getFather()->getRightSon())->getData() == node->getData())
                node->getFather()->setRightSon(NULL);
            else
                node->getFather()->setLeftSon(NULL);
        }else 
            node->getFather()->setLeftSon(NULL);
        free(node);
        return(true);
    }else if(node->onlyOneSon()){
        cout<<"Tiene solo un hijo";
    }
}