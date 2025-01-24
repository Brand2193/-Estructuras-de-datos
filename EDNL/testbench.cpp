#include "BinarySearchTree.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main(){
    int op;
    int mode = 1;
    BinarySearchTree<int> t;
    while(1){
        t.print(3);
    cout<<"\n\nElige una opcion: ";
    cout<<"\n1) Agregar nodo";
    cout<<"\n2) Buscar nodo";
    cout<<"\n3) Borrar nodo";
    cout<<"\n\nOpcion: ";
    cin>>op;
    switch(op){
        case 1: 
            cout<<"Ingresa el elemento: ";
            cin>>op; 
            if(!t.add(op))
                cout<<"No se ingreso, ya existe";
            else 
                cout<<"Se ingreso correctamente";    
            getch();
            break;
        case 2:
            cout<<"Ingresa el que quieres bucar: ";
            cin>>op;
            if(t.search(op))
                cout<<"Encontrado !";
            else 
                cout<<"no encontrado :(";
            getch();
            break;
        case 3: 
            cout<<"Ingresa el que quieres eliminar: ";
            cin>>op;
            t.remove(op);
            getch();
            break;
    }
    system("cls");
    }
    return 0;
}