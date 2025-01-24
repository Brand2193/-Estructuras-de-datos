/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos lineales.
*/

#include "Node.h"
using namespace std;

/* Esta es una interface que contiene los 
   metodos mas comunes de una lista */
template <typename E>
class ListInterface{
    public: 
        bool add(E);
        bool remove(E);
        void print();
        int size();
        void clear();
        bool isEmpty();
};