package EDL;

public class Node<E>{
    private Node<E> next;
    private Node<E> prev;
    private E data;
    
    public Node(){}
    
    public Node(E data){
        this.data = data;
        this.next = null; 
        this.prev = null;
    }
    
    /* Metodo que devuelve el dato de un nodo */
    public E getData(){
        return(this.data);
    }
    
    /* Metodo para obtener el apuntador al nodo siguiente */
    public Node<E> getNext(){
        return(this.next);
    }
    
    /* Metodo para obtener el apuntador al nodo previo */
    public Node<E> getPrev(){
        return(this.prev);
    }
    
    /* Metodo para cambiar el apuntador al nodo siguiente */
    public void setNext(Node<E> node){
        this.next = node;
    }
    
    /* Metodo para cambiar el apuntador al nodo previo */
    public void setPrev(Node<E> node){
        this.prev = node;
    }
    
    /* Metodo para modificar el valor del dato del nodo */
    public void setData(E data){
        this.data = data;
    }
}
