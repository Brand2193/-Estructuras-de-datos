package test;
import java.util.Scanner;

import EDL.MyLinkedList;

public class Testbench {
    public static void main(String[] args) {
        MyLinkedList<Integer> l = new MyLinkedList<>();
        Scanner p = new Scanner(System.in);
        boolean t = true;
        int op;
        while(t){
            l.print();
            System.out.print("\n\nElige una:  1) insertar, 2) eliminar, 3) indice de, 4) salir \n\nopcion: ");
            op = p.nextInt();
            switch(op){
                case 1: 
                    System.out.print("Ingresa el dato: ");
                    op = p.nextInt();
                    l.add(op);
                    break; 
        
                case 2: 

                    break; 
                
                case 3: 
                    System.out.print("Ingresa el dato: ");
                    op = p.nextInt();
                    System.out.print("El dato se encuentra en: ");
                    l.indexOf(op).print();
                    try{
                        Thread.sleep(1000);
                    }catch(InterruptedException M){
                        
                    }
                    break; 
                
                case 4: 
                    t = false; 
                    break;
                
                default: 
                    break;
            }
            System.out.print("\033[H\033[2J");
            System.out.flush();
        }
    }
}