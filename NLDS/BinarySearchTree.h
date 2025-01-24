#include "nodeBT.h"

template <typename E>
class Binary_ST{
    private: 
        NODE_BT<E> *root;
    public: 
        Binary_ST();
        ~Binary_ST();
        NODE_BT<E> *getRoot();
        NODE_BT<E> *searchNode(E x, NODE_BT<E> *node);
        bool isEmpty();
        bool insertNode(NODE_BT<E> *node, E x);
        bool deleteNode(NODE_BT<E> *node, E x);
};

template <typename E> 
Binary_ST<E>::Binary_ST(){
    this->root = new NODE_BT<E>();
}

template <typename E> 
Binary_ST<E>::~Binary_ST(){
    // TODO
}

template <typename E> 
NODE_BT<E> *Binary_ST<E>::getRoot(){
    return(this->root);
}

template <typename E>
NODE_BT<E> *Binary_ST<E>::searchNode(E x, NODE_BT<E> *node){
    if(!node)   
        return(NULL);
    else if(x == node->getData())
        return(node);
    else if(x < node->getData())
        return(searchNode(x, node->getLeft_son()));
    else
        return(searchNode(x, node->getRight_son()));
}

template <typename E> 
bool Binary_ST<E>::isEmpty(){
    if(!root->getLeft_son() && !root->getRight_son() && !root->getData())
        return (true);
    return (false);
}

template <typename E>
bool Binary_ST<E>::insertNode(NODE_BT<E> *node, E x){
   if(isEmpty()){
       node->setData(x);
       return (true);
   }else if(x == node->getData()){
       return (false);
    }else if(x < node->getData()){
        if(node->getLeft_son()){
            return (insertNode(node->getLeft_son(), x));
        }else{
            NODE_BT<E> *new_node = new NODE_BT<E>(x);
            node->setLeft_son(new_node);
            return (true);
        }
    }else{
       if(node->getRight_son()){
           return (insertNode(node->getRight_son(), x));
       }else{
           NODE_BT<E> *new_node = new NODE_BT<E>(x);
           node->setRight_son(new_node);
           return (true);
       }
    }
}

template <typename E> 
bool Binary_ST<E>::deleteNode(NODE_BT<E> *node, E x){
    // TODO
}

/* -------------------Recorridos de arboles-------------------- */ 

template <typename E>
void Inorder(NODE_BT<E> *root){
    if(!root)
        return; 
    Inorder(root->getLeft_son()); 
    cout<<root->getData()<<" ";
    Inorder(root->getRight_son());
}

template <typename E>
void Preorder(NODE_BT<E> *root){
    if(!root)
        return;
    cout<<root->getData()<<" ";
    Preorder(root->getLeft_son());
    Preorder(root->getRight_son());
}

template <typename E>
void Postorder(NODE_BT<E> *root){
    if(!root)
        return; 
    Postorder(root->getLeft_son());
    Postorder(root->getRight_son());
    cout<<root->getData()<<" ";
}