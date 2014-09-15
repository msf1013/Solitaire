/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

class carta{

private:
	int fig;
	int num;
public:
	carta();
	carta(int n, int f);
	int getNum();
	int getFig();

};

carta::carta(){
	num = 0;
	fig = 0;
}

carta::carta(int n, int f){
	num = n;
	fig = f;
}

int carta::getNum(){
	return num;
}

int carta::getFig(){
	return fig;
}

