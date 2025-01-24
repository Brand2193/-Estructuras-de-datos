#include <iostream>
#include <conio.h>
//#include "LinkedList.h"
#include "Stack.h"
using namespace std;

int main(){
    /*
    LinkedList<int> l;
    int op;
    while(1){
        cout<<"N = "<<l.size()<<endl<<endl;
        l.print();
        cout<<"\n1) Insertar";
        cout<<"\n2) Borrar elemento";
        cout<<"\n3) Obtener elemento por su indice";
        cout<<"\n4) Comprobar si esta vacia";
        cout<<"\n5) Intercambiar elemento x del indice y";
        cout<<"\n6) Ordenar lista";
        cout<<"\n7) Buscar elemento\n\n";
        cout<<"Respuesta: "; 
        cin >> op; 
        switch(op){
            case 1: 
                cout<<" Que quieres insertar: "; 
                cin>>op; 
                l.add(op);
                break; 
            case 2: 
                cout<<"cual quieres borrar: ";
                cin>>op; 
                l.remove(op);
                break; 
            case 3: 
                cout<<" introduce indice: "; 
                cin>>op; 
                cout<<" El elemento es: "<<l.get(op)<<endl;
                getch();
                break;
            case 4:
                cout<<l.isEmpty();
                getch();
                break;
            case 5:
                int element;
                cout<<"Introduce el indice: "; 
                cin>>op; 
                cout<<"\nIntroduce el nuevo elemento: ";
                cin>>element;
                l.set(op, element);
                break;
            case 6: 
                l.sort();
                break;
            case 7: 
                cout<<"Introduce el elemento que buscas: ";
                cin>>op;
                cout<<l.exists(op);
                getch();
            default : break;
        }
        system("cls");
    }
    */
    int op;
    Stack<int> s;
    while(1){
        cout<<"N = "<<s.size()<<endl<<endl;
        s.print();
        cout<<"\n\n1) push";
        cout<<"\n2) pop";
        cout<<"\n3) isEmpty";
        cout<<"\n4) peek";
        cout<<"\n5) clear";
        cout<<"\n\nOpcion:";
        cin>>op;
        switch(op){
            case 1: 
                cout<<"Ingresa el dato: ";
                cin>>op;
                s.push(op);
                break;
            case 2: 
                cout<<endl<<s.pop();
                getch();
                break;
            case 3: 
                cout<<s.isEmpty();
                getch();
                break;
            case 4:
                cout<<s.peek();
                getch();
                break;
            case 5:
                s.clear();
                break;
            default : break;
        }
        system("cls");
    }
    
    return 0;
}