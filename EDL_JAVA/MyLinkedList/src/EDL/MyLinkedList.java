package EDL;

public class MyLinkedList<E> implements MyLinkedList_I<E>{
    private Node<E> head;
    private int     dataAmount;
    
    public MyLinkedList(){
        this.dataAmount = 0; 
        this.head = null;
    }
    
    /* Este metodo sirve para insertar un nuevo 
       elemento a la lista */
    @Override
    public void add(E data){
        Node<E> node = new Node<>(data);
        if(this.head == null){
            node.setNext(this.head);
            head = node; 
        }else{
            this.head.setPrev(node);
            node.setNext(this.head);
            this.head = node;
        }
        this.dataAmount++;
    }
    
    /* Este metodo imprime la lista en pantalla */
    @Override
    public void print(){
        Node<E> aux = this.head;
        while(aux != null){
            System.out.print(" "+aux.getData()+" ");
            aux = aux.getNext();
        }
    }

    public MyLinkedList<Integer> indexOf(E element){
        int i = 0;
        Node<E> aux = this.head;
        MyLinkedList<Integer> indexList = new MyLinkedList<>();
        while(aux != null){
            if(aux.getData() == element)
                indexList.add(i);
            i++;
            aux = aux.getNext();
        }
        if(this.isEmpty())
            return(null);
        return(indexList);
    }


    @Override 
    public int size(){
        return(this.dataAmount);
    }

    @Override 
    public boolean isEmpty(){
        if(this.size() == 0)
            return(true);
        return(false);
    }
}
