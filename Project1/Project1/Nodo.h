/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

template <class T>
class Nodo{
    public:
        T info;
        Nodo<T>* sig;
        Nodo(){
            sig=nullptr;
        }
        Nodo(T dato){
            info=dato;
            sig=nullptr;
        }
};
