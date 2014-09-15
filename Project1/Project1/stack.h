/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

template <class T>
class stack{
    private:
        Nodo<T>* fondo;
    public:
        stack(){
            fondo=nullptr;
		}
        void push(T dato);
        void pop();
        T top();
        bool empty();
        ~stack();
};

template <class T>
stack<T>::~stack(){

	Nodo<T> *aux1, *aux2;
	aux2 = fondo;
	aux1 = fondo;
	if (fondo != nullptr)
		do{
			aux2 = aux2->sig;
			delete aux1;
			aux1 = aux2;
		} while (aux1 != fondo);

}

template <class T>
void stack<T>::push(T dato){
    Nodo<T>* aux=new Nodo<T>(dato);
    if(fondo==nullptr){
        fondo=aux;
        fondo->sig=fondo;
    } else {
        aux->sig=fondo->sig;
        fondo->sig=aux;
    }
}

template <class T>
void stack<T>::pop(){
    Nodo<T>* aux=fondo->sig->sig;
    if(fondo!=fondo->sig){
        delete fondo->sig;
        fondo->sig=aux;
    } else {
        delete fondo;
        fondo=nullptr;
    }

}

template <class T>
T stack<T>::top(){
    return fondo->sig->info;

}

template <class T>
bool stack<T>::empty(){
    return (fondo==nullptr);
}

