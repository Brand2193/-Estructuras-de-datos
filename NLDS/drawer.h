/*
    Brandon Juarez Rosas - 2193035695
    Ingenieria en computacion - Estructuras de datos no lineales.
*/

template <typename E> 
class DRAWER{
    private: 
        bool status;
        E data;
    public: 
        DRAWER();
        void setStatus(bool status);
        bool getStatus();
        E getData();
        void setData(E x);
};

/* El estado inicial de todo cajon de una tabla 
   hash es vacio (false) ya que no se ha insertado 
   ningun elemento dentro */
template <typename E> 
DRAWER<E>::DRAWER(){
    this->status = false;
}

template <typename E> 
void DRAWER<E>::setStatus(bool status){
    this->status = status;
}

template <typename E> 
bool DRAWER<E>::getStatus(){
    return(this->status);
}

template <typename E> 
E DRAWER<E>::getData(){
    return(this->data);
}

template <typename E> 
void DRAWER<E>::setData(E x){
    this->data = x;
}