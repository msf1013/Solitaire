/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

template <class T>
class queue{
    private:
        Nodo<T>* fin;
    public:
        queue(){
            fin=nullptr;
        }
        void push(T dato);
        void pop();
        T front();
        bool empty();
        int size();
        ~queue();
};

template <class T>
queue<T>::~queue(){

	Nodo<T> *aux1, *aux2;
	aux2 = fin;
	aux1 = fin;
	if (fin!=nullptr)
		do{
			aux2 = aux2->sig;
			delete aux1;
			aux1 = aux2;
		} while (aux1!=fin);

}

template <class T>
void queue<T>::push(T dato){
    Nodo<T>* aux=new Nodo<T>(dato);
    if(fin==nullptr){
        fin=aux;
        fin->sig=fin;
    } else {
        aux->sig=fin->sig;
        fin->sig=aux;
        fin=aux;
    }
}

template <class T>
void queue<T>::pop(){
    Nodo<T>* aux=fin->sig->sig;
    if(fin!=fin->sig){
        delete fin->sig;
        fin->sig=aux;
    } else {
        delete fin;
        fin=nullptr;
    }

}

template <class T>
T queue<T>::front(){
    return fin->sig->info;

}

template <class T>
bool queue<T>::empty(){
    return (fin==nullptr);
}

template <class T>
int queue<T>::size(){
    int tam=1;
    if(fin==nullptr) return 0;
	Nodo<T> * aux = fin->sig;
    while(aux!=fin){
        tam++;
        aux=aux->sig;
    }
    return tam;
}



