/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

#pragma once

#include "carta.h"
#include "Nodo.h"
//#include "queue.h"
//#include "stack.h"
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <windows.h>

using namespace std;

int cont;			// contador para llevar registro de las cartas sacadas en la fila del juego
string dir;			// string auxiliar para almacenar el path de las imagenes
ostringstream os;	// ostringstream auxiliar para convertir numeros a string

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TAR3
	/// </summary>

	int cantPilas;
	vector<int> arr; // Arreglo para ordenar aleatoriamente las cartas
	stack<carta> aux; // Arreglo auxiliar vacio para crear el vector de pilas
	stack<carta>* salida; // Pila de salida 
	queue<carta>* fila; // Fila de cartas
	vector< stack<carta> > vecP; // Arreglo de pilas 

	public ref class TAR3 : public System::Windows::Forms::Form
	{
	public:
		TAR3(void)
		{
			// Inicializacion de arreglo/vector con el que se ordenan aleatoriamente las cartas
			for (int i = 0; i<52; i++){
				arr.push_back(i);
			}

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TAR3()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::Button^  button1;		// Boton de pila 1
	public: System::Windows::Forms::Button^  button2;		// Boton de pila 2
	public: System::Windows::Forms::Button^  button3;		// Boton de pila 3
	public: System::Windows::Forms::Button^  button4;		// Boton de pila 4
	public: System::Windows::Forms::Button^  button5;		// Boton de pila 5
	public: System::Windows::Forms::Button^  button6;		// Boton de pila 6
	public: System::Windows::Forms::Button^  button7;		// Boton de pila 7
	public: System::Windows::Forms::Button^  button8;		// Boton de pila 8
	public: System::Windows::Forms::Button^  button9;		// Boton de fila
	public: System::Windows::Forms::Button^  button10;		// Boton de pila de salida
	public: System::Windows::Forms::ListBox^  listBox1;		// Lista de opciones de cantidad de pilas
	private: System::Windows::Forms::Button^  button11;		// Boton que indica que el juego se ha ciclado
	private: System::Windows::Forms::Button^  button12;		// Boton que indica que el jugador ha ganado
	private: System::Windows::Forms::Button^  button13;		// Boton para "pasar carta" de fila a pila

	public:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(TAR3::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->Location = System::Drawing::Point(28, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 144);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Visible = false;
			this->button1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button1_MouseClick);
			// 
			// button2
			// 
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(147, 45);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(98, 144);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button2_MouseClick);
			// 
			// button3
			// 
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(266, 45);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(98, 144);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Visible = false;
			this->button3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button3_MouseClick);
			// 
			// button4
			// 
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->Location = System::Drawing::Point(387, 45);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(98, 144);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Visible = false;
			this->button4->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button4_MouseClick);
			// 
			// button5
			// 
			this->button5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.BackgroundImage")));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->Location = System::Drawing::Point(509, 45);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(98, 144);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Visible = false;
			this->button5->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button5_MouseClick);
			// 
			// button6
			// 
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->Location = System::Drawing::Point(630, 45);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(98, 144);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Visible = false;
			this->button6->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button6_MouseClick);
			// 
			// button7
			// 
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button7->Location = System::Drawing::Point(748, 45);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(98, 144);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Visible = false;
			this->button7->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button7_MouseClick);
			// 
			// button8
			// 
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button8->Location = System::Drawing::Point(865, 45);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(98, 144);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button8_MouseClick);
			// 
			// button9
			// 
			this->button9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button9->Location = System::Drawing::Point(296, 229);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(98, 144);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &TAR3::button9_MouseClick);
			// 
			// button10
			// 
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button10->Location = System::Drawing::Point(531, 229);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(98, 144);
			this->button10->TabIndex = 9;
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Visible = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) { L"3", L"4", L"5", L"6", L"7", L"8" });
			this->listBox1->Location = System::Drawing::Point(768, 7);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(45, 30);
			this->listBox1->TabIndex = 10;
			this->listBox1->Click += gcnew System::EventHandler(this, &TAR3::listBox1_Click);
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(680, 217);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(218, 71);
			this->button11->TabIndex = 11;
			this->button11->Text = L"El juego se ha ciclado";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Visible = false;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(680, 294);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(218, 71);
			this->button12->TabIndex = 12;
			this->button12->Text = L"Felicidades! Has ganado el juego!";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Visible = false;
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(183, 269);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(92, 68);
			this->button13->TabIndex = 13;
			this->button13->Text = L"Pasar carta a pila";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Visible = false;
			this->button13->Click += gcnew System::EventHandler(this, &TAR3::button13_Click);
			// 
			// TAR3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(975, 410);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"TAR3";
			this->Text = L"TAR3";
			this->ResumeLayout(false);

		}
#pragma endregion

// Codigo de evento de presionar el boton correspondiente a la fila

private: System::Void button9_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 // Se mete carta de tope de fila al fondo de la fila
			 fila->push(fila->front());
			 fila->pop();

			 os.str("");
			 os << fila->front().getNum() + fila->front().getFig() * 13;
			 dir = "C:\\cards\\" + os.str() + ".png";
			 str3 = gcnew String(dir.c_str());
			 button9->BackgroundImage = Image::FromFile(str3);

			 cont++;

			 // Si se completo un ciclo en la fila, se evalua que el programa no se haya ciclado
			 if (cont == fila->size()){
				 bool bueno = 0;
				 bool terminado = 1;
				 for (int k = 0; k<cantPilas; k++){ // Se evalua que las pilas no esten vacias

					 if (!vecP[k].empty()){
						 terminado = 0;
						 if (salida->empty()){
							 bueno = 1; break;
						 }
						 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
							 bueno = 1; break;
						 }
					 }

				 }

				 for (int i = 0; i < fila->size(); i++){ // Se evalua que la fila aun tenga opciones de juego
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1;
					 }
					 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
						 bueno = 1;
					 }
					 fila->push(fila->front());
					 fila->pop();
				 }

				 if (bueno == 0){ // Si el juego se ha ciclado, se despliega el boton de partida terminada
					 button11->Visible = true;
				 }
				 else if (terminado){ // Si el juego se ha completado satisfactoriamente, se despliega el boton de victoria
					 button13->Visible = true;
				 }
			 }

}

// Codigo de evento de presionar el boton correspondiente a la pila 1
	
private: System::Void button1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;

	if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
		cont = 0;
		os.str("");
		os << vecP[0].top().getNum() + vecP[0].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);

		salida->push(vecP[0].top());
		vecP[0].pop();
		os.str("");
		os << vecP[0].top().getNum() + vecP[0].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button1->BackgroundImage = Image::FromFile(str3);
		// Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
	}
	else if (vecP[0].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[0].top().getNum() + 1) % 13){
		cont = 0;
		os.str("");
		os << vecP[0].top().getNum() + vecP[0].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);

		salida->push(vecP[0].top());
		vecP[0].pop();
		os.str("");
		if (!vecP[0].empty()){ // Si la pila no queda vacia con el movimiento realizado, se despliega la siguiente carta
			os << vecP[0].top().getNum() + vecP[0].top().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button1->BackgroundImage = Image::FromFile(str3);
		} // Si la pila quedo vacia con el movimiento, se despliega la imagen de pila vacia
		else {
			dir = "C:\\cards\\gray.png";
			str3 = gcnew String(dir.c_str());
			button1->BackgroundImage = Image::FromFile(str3);
		}
	}

	// Validacion de juego terminado / ciclado (explicado con anterioridad)
	bool bueno = 0;
	bool terminado = 1;
	for (int k = 0; k<cantPilas; k++){

		if (!vecP[k].empty()){
			terminado = 0;
			if (salida->empty()){
				bueno = 1; break;
			}
			else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
				bueno = 1; break;
			}
		}

	}

	for (int i = 0; i < fila->size(); i++){
		terminado = 0;
		if (salida->empty()){
			bueno = 1;
		}
		else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
			bueno = 1;
		}
		fila->push(fila->front());
		fila->pop();
	}

	if (bueno == 0){
		button11->Visible = true;
	}
	else if (terminado){
		button13->Visible = true;
	}
}

// Codigo de evento de presionar el boton correspondiente a la pila 2

private: System::Void button2_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
				 cont = 0;
				 os.str("");
				 os << vecP[1].top().getNum() + vecP[1].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[1].top());
				 vecP[1].pop();
				 os.str("");
				 os << vecP[1].top().getNum() + vecP[1].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button2->BackgroundImage = Image::FromFile(str3);

			 } // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
			 else if (vecP[1].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[1].top().getNum() + 1) % 13){
				 cont = 0;
				 os.str("");
				 os << vecP[1].top().getNum() + vecP[1].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[1].top());
				 vecP[1].pop();
				 os.str("");
				 if (!vecP[1].empty()){
					 os << vecP[1].top().getNum() + vecP[1].top().getFig() * 13;
					 dir = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(dir.c_str());
					 button2->BackgroundImage = Image::FromFile(str3);
				 }
				 else {
					 dir = "C:\\cards\\gray.png";
					 str3 = gcnew String(dir.c_str());
					 button2->BackgroundImage = Image::FromFile(str3);
				 }
			 }

			 // Validacion de juego terminado / ciclado
			 bool bueno = 0;
			 bool terminado = 1;
			 for (int k = 0; k<cantPilas; k++){

				 if (!vecP[k].empty()){
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1; break;
					 }
					 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
						 bueno = 1; break;
					 }
				 }

			 }

			 for (int i = 0; i < fila->size(); i++){
				 terminado = 0;
				 if (salida->empty()){
					 bueno = 1;
				 }
				 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
					 bueno = 1;
				 }
				 fila->push(fila->front());
				 fila->pop();
			 }

			 if (bueno == 0){
				 button11->Visible = true;
			 }
			 else if (terminado){
				 button13->Visible = true;
			 }
}

// Codigo de evento de presionar el boton correspondiente a la pila 3

private: System::Void button3_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
		if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
			cont = 0;
			os.str("");
			os << vecP[2].top().getNum() + vecP[2].top().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button10->BackgroundImage = Image::FromFile(str3);

			salida->push(vecP[2].top());
			vecP[2].pop();
			os.str("");
			os << vecP[2].top().getNum() + vecP[2].top().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button3->BackgroundImage = Image::FromFile(str3);

		} // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
		else if (vecP[2].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[2].top().getNum() + 1) % 13){
			cont = 0;
			os.str("");
			os << vecP[2].top().getNum() + vecP[2].top().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button10->BackgroundImage = Image::FromFile(str3);

			salida->push(vecP[2].top());
			vecP[2].pop();
			os.str("");
			if (!vecP[2].empty()){
				os << vecP[2].top().getNum() + vecP[2].top().getFig() * 13;
				dir = "C:\\cards\\" + os.str() + ".png";
				str3 = gcnew String(dir.c_str());
				button3->BackgroundImage = Image::FromFile(str3);
			}
			else {
				dir = "C:\\cards\\gray.png";
				str3 = gcnew String(dir.c_str());
				button3->BackgroundImage = Image::FromFile(str3);
			}
		}

		// Validacion de juego terminado / ciclado
		bool bueno = 0;
		bool terminado = 1;
		for (int k = 0; k<cantPilas; k++){

			if (!vecP[k].empty()){
				terminado = 0;
				if (salida->empty()){
					bueno = 1; break;
				}
				else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
					bueno = 1; break;
				}
			}

		}

		for (int i = 0; i < fila->size(); i++){
			terminado = 0;
			if (salida->empty()){
				bueno = 1;
			}
			else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
				bueno = 1;
			}
			fila->push(fila->front());
			fila->pop();
		}

		if (bueno == 0){
			button11->Visible = true;
		}
		else if (terminado){
			button13->Visible = true;
		}
}

// Codigo de evento de presionar el boton correspondiente a la pila 4

private: System::Void button4_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
	if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
		os.str("");
		os << vecP[3].top().getNum() + vecP[3].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);

		salida->push(vecP[3].top());
		vecP[3].pop();
		os.str("");
		os << vecP[3].top().getNum() + vecP[3].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button4->BackgroundImage = Image::FromFile(str3);

	} // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
	else if (vecP[3].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[3].top().getNum() + 1) % 13){
		cont = 0;
		os.str("");
		os << vecP[3].top().getNum() + vecP[3].top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);

		salida->push(vecP[3].top());
		vecP[3].pop();
		os.str("");
		if (!vecP[3].empty()){
			os << vecP[3].top().getNum() + vecP[3].top().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button4->BackgroundImage = Image::FromFile(str3);
		}
		else {
			dir = "C:\\cards\\gray.png";
			str3 = gcnew String(dir.c_str());
			button4->BackgroundImage = Image::FromFile(str3);
		}
	}

	// Validacion de juego terminado / ciclado
	bool bueno = 0;
	bool terminado = 1;
	for (int k = 0; k<cantPilas; k++){

		if (!vecP[k].empty()){
			terminado = 0;
			if (salida->empty()){
				bueno = 1; break;
			}
			else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
				bueno = 1; break;
			}
		}

	}

	for (int i = 0; i < fila->size(); i++){
		terminado = 0;
		if (salida->empty()){
			bueno = 1;
		}
		else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
			bueno = 1;
		}
		fila->push(fila->front());
		fila->pop();
	}

	if (bueno == 0){
		button11->Visible = true;
	}
	else if (terminado){
		button13->Visible = true;
	}
}

// Codigo de evento de presionar el boton correspondiente a la pila 5

private: System::Void button5_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
				 os.str("");
				 os << vecP[4].top().getNum() + vecP[4].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[4].top());
				 vecP[4].pop();
				 os.str("");
				 os << vecP[4].top().getNum() + vecP[4].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button5->BackgroundImage = Image::FromFile(str3);

			 } // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
			 else if (vecP[4].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[4].top().getNum() + 1) % 13){
				 cont = 0;
				 os.str("");
				 os << vecP[4].top().getNum() + vecP[4].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[4].top());
				 vecP[4].pop();
				 os.str("");
				 if (!vecP[4].empty()){
					 os << vecP[4].top().getNum() + vecP[4].top().getFig() * 13;
					 dir = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(dir.c_str());
					 button5->BackgroundImage = Image::FromFile(str3);
				 }
				 else {
					 dir = "C:\\cards\\gray.png";
					 str3 = gcnew String(dir.c_str());
					 button5->BackgroundImage = Image::FromFile(str3);
				 }
			 }

			 // Validacion de juego terminado / ciclado
			 bool bueno = 0;
			 bool terminado = 1;
			 for (int k = 0; k<cantPilas; k++){

				 if (!vecP[k].empty()){
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1; break;
					 }
					 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
						 bueno = 1; break;
					 }
				 }

			 }

			 for (int i = 0; i < fila->size(); i++){
				 terminado = 0;
				 if (salida->empty()){
					 bueno = 1;
				 }
				 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
					 bueno = 1;
				 }
				 fila->push(fila->front());
				 fila->pop();
			 }

			 if (bueno == 0){
				 button11->Visible = true;
			 }
			 else if (terminado){
				 button13->Visible = true;
			 }
}

// Codigo de evento de presionar el boton correspondiente a la pila 6

private: System::Void button6_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
				 os.str("");
				 os << vecP[5].top().getNum() + vecP[5].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[5].top());
				 vecP[5].pop();
				 os.str("");
				 os << vecP[5].top().getNum() + vecP[5].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button6->BackgroundImage = Image::FromFile(str3);

			 } // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
			 else if (vecP[5].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[5].top().getNum() + 1) % 13){
				 cont = 0;
				 os.str("");
				 os << vecP[5].top().getNum() + vecP[5].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[5].top());
				 vecP[5].pop();
				 os.str("");
				 if (!vecP[5].empty()){
					 os << vecP[5].top().getNum() + vecP[5].top().getFig() * 13;
					 dir = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(dir.c_str());
					 button6->BackgroundImage = Image::FromFile(str3);
				 }
				 else {
					 dir = "C:\\cards\\gray.png";
					 str3 = gcnew String(dir.c_str());
					 button6->BackgroundImage = Image::FromFile(str3);
				 }
			 }

			 // Validacion de juego terminado / ciclado
			 bool bueno = 0;
			 bool terminado = 1;
			 for (int k = 0; k<cantPilas; k++){

				 if (!vecP[k].empty()){
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1; break;
					 }
					 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
						 bueno = 1; break;
					 }
				 }

			 }

			 for (int i = 0; i < fila->size(); i++){
				 terminado = 0;
				 if (salida->empty()){
					 bueno = 1;
				 }
				 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
					 bueno = 1;
				 }
				 fila->push(fila->front());
				 fila->pop();
			 }

			 if (bueno == 0){
				 button11->Visible = true;
			 }
			 else if (terminado){
				 button13->Visible = true;
			 }
}

// Codigo de evento de presionar el boton correspondiente a la pila 7

private: System::Void button7_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
				 os.str("");
				 os << vecP[6].top().getNum() + vecP[6].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[6].top());
				 vecP[6].pop();
				 os.str("");
				 os << vecP[6].top().getNum() + vecP[6].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button7->BackgroundImage = Image::FromFile(str3);

			 } // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
			 else if (vecP[6].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[6].top().getNum() + 1) % 13){
				 cont = 0;
				 os.str("");
				 os << vecP[6].top().getNum() + vecP[6].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[6].top());
				 vecP[6].pop();
				 os.str("");
				 if (!vecP[6].empty()){
					 os << vecP[6].top().getNum() + vecP[6].top().getFig() * 13;
					 dir = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(dir.c_str());
					 button7->BackgroundImage = Image::FromFile(str3);
				 }
				 else {
					 dir = "C:\\cards\\gray.png";
					 str3 = gcnew String(dir.c_str());
					 button7->BackgroundImage = Image::FromFile(str3);
				 }
			 }

			 // Validacion de juego terminado / ciclado
			 bool bueno = 0;
			 bool terminado = 1;
			 for (int k = 0; k<cantPilas; k++){

				 if (!vecP[k].empty()){
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1; break;
					 }
					 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
						 bueno = 1; break;
					 }
				 }

			 }

			 for (int i = 0; i < fila->size(); i++){
				 terminado = 0;
				 if (salida->empty()){
					 bueno = 1;
				 }
				 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
					 bueno = 1;
				 }
				 fila->push(fila->front());
				 fila->pop();
			 }

			 if (bueno == 0){
				 button11->Visible = true;
			 }
			 else if (terminado){
				 button13->Visible = true;
			 }
}

// Codigo de evento de presionar el boton correspondiente a la pila 8

private: System::Void button8_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 String^ str3;
			 if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
				 os.str("");
				 os << vecP[7].top().getNum() + vecP[7].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[7].top());
				 vecP[7].pop();
				 os.str("");
				 os << vecP[7].top().getNum() + vecP[7].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button8->BackgroundImage = Image::FromFile(str3);

			 } // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
			 else if (vecP[7].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[7].top().getNum() + 1) % 13){
				 cont = 0;
				 os.str("");
				 os << vecP[7].top().getNum() + vecP[7].top().getFig() * 13;
				 dir = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(dir.c_str());
				 button10->BackgroundImage = Image::FromFile(str3);

				 salida->push(vecP[7].top());
				 vecP[7].pop();
				 os.str("");
				 if (!vecP[7].empty()){
					 os << vecP[7].top().getNum() + vecP[7].top().getFig() * 13;
					 dir = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(dir.c_str());
					 button8->BackgroundImage = Image::FromFile(str3);
				 }
				 else {
					 dir = "C:\\cards\\gray.png";
					 str3 = gcnew String(dir.c_str());
					 button8->BackgroundImage = Image::FromFile(str3);
				 }
			 }

			 // Validacion de juego terminado / ciclado
			 bool bueno = 0;
			 bool terminado = 1;
			 for (int k = 0; k<cantPilas; k++){

				 if (!vecP[k].empty()){
					 terminado = 0;
					 if (salida->empty()){
						 bueno = 1; break;
					 }
					 else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
						 bueno = 1; break;
					 }
				 }

			 }

			 for (int i = 0; i < fila->size(); i++){
				 terminado = 0;
				 if (salida->empty()){
					 bueno = 1;
				 }
				 else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
					 bueno = 1;
				 }
				 fila->push(fila->front());
				 fila->pop();
			 }

			 if (bueno == 0){
				 button11->Visible = true;
			 }
			 else if (terminado){
				 button13->Visible = true;
			 }
}

// Codigo de evento de presionar el boton para pasar la carta frente de la fila a la pila de salida

private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ str3;
	if (salida->empty()){ // Si la pila de salida esta vacia, el primer movimiento es valido
		cont = 0;
		salida->push(fila->front());
		fila->pop();

		os.str("");
		os << fila->front().getNum() + fila->front().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button9->BackgroundImage = Image::FromFile(str3);

		os.str("");
		os << salida->top().getNum() + salida->top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);
	} // Si la pila de salida no esta vacia, se evalua que el movimiento intentado sea valido
	else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
		cont = 0;
		salida->push(fila->front());
		fila->pop();

		os.str("");
		os << salida->top().getNum() + salida->top().getFig() * 13;
		dir = "C:\\cards\\" + os.str() + ".png";
		str3 = gcnew String(dir.c_str());
		button10->BackgroundImage = Image::FromFile(str3);

		os.str("");

		if (!fila->empty()){ // Si la fila no quedo vacia con el movimiento, se despliega la siguiente carta
			os << fila->front().getNum() + fila->front().getFig() * 13;
			dir = "C:\\cards\\" + os.str() + ".png";
			str3 = gcnew String(dir.c_str());
			button9->BackgroundImage = Image::FromFile(str3);
		}
		else { // Si la fila quedo vacia con el movimiento, se depliega una imagen que indica que la pila esta vacia
			dir = "C:\\cards\\gray.png";
			str3 = gcnew String(dir.c_str());
			button9->BackgroundImage = Image::FromFile(str3);
		}


	}


	// Validacion de juego terminado / ciclado
	bool bueno = 0;
	bool terminado = 1;
	for (int k = 0; k<cantPilas; k++){

		if (!vecP[k].empty()){
			terminado = 0;
			if (salida->empty()){
				bueno = 1; break;
			}
			else if (vecP[k].top().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (vecP[k].top().getNum() + 1) % 13){
				bueno = 1; break;
			}
		}

	}

	for (int i = 0; i < fila->size(); i++){
		terminado = 0;
		if (salida->empty()){
			bueno = 1;
		}
		else if (fila->front().getNum() == (salida->top().getNum() + 1) % 13 || salida->top().getNum() == (fila->front().getNum() + 1) % 13){
			bueno = 1;
		}
		fila->push(fila->front());
		fila->pop();
	}

	if (bueno == 0){
		button11->Visible = true;
	}
	else if (terminado){
		button13->Visible = true;
	}

}

private: System::Void listBox1_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 random_shuffle(arr.begin(), arr.end()); // Se organiza aleatoriamente el vector de cartas
			 cont = 0; // El contador de ciclo, en la fila, se reinicia con 0

			 cantPilas = listBox1->SelectedIndex + 3; // La cantidad de pilas del juego se toma del valor seleccionado de listBox
			 vecP.clear(); // El contenido del vector con las pilas se vacia

			 button11->Visible = false; // Boton de derrota se oculta
			 button12->Visible = false; // Boton de victoria se oculta
			// Botones de pilas 1, 2 y 3 se muestran
			 button1->Visible = true;
			 button2->Visible = true;
			 button3->Visible = true;
			 // Boton de fila se muestra
			 button9->Visible = true;
			 // Boton de pila de salida se muestra
			 button10->Visible = true;
			 // Boton de pasar carta de fila a pila se muestra
			 button13->Visible = true;
			 
			 delete salida; // Se elimina la pila de salida y se crea una nueva
			 salida = new stack<carta>;
			 delete fila; // Se elimina la fila y se crea una nueva
			 fila = new queue<carta>;

			 vecP.assign(cantPilas, aux); // Se inicializa el vector de pilas con la cantidad de pilas especificada

			 for (int i = 0; i < 52; i++){ // Se crea el contenido de los vectores de pila haciendo uso del 
											// vector ordenado aleatoriamente
				 if (i % (cantPilas + 1) == cantPilas) fila->push(carta(arr[i] % 13, arr[i] / 13));
				 else vecP[i % (cantPilas + 1)].push(carta(arr[i] % 13, arr[i] / 13));
			 }
			 
			 string liga;
			 String^ str3;

				 // Inicializacion de imagen de pila salida (boton 10)

			 button10->BackgroundImage = Image::FromFile("C:\\cards\\gray.png");

				 // Inicializacion de imagen de fFila (boton 9)
				os.str("");
				os << fila->front().getNum() + fila->front().getFig() * 13;
				 liga = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(liga.c_str());
				 button9->BackgroundImage = Image::FromFile(str3);
			 
				 // Inicializacion de imagen de pila 1, Boton 1
				 os.str("");
				 os << vecP[0].top().getNum() + vecP[0].top().getFig() * 13;
				 liga = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(liga.c_str());
				 button1->BackgroundImage = Image::FromFile(str3);
				 // Inicializacion de imagen de pila 2, Boton 2
				 os.str(""); 
				 os << vecP[1].top().getNum() + vecP[1].top().getFig() * 13;
				 liga = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(liga.c_str());
				 button2->BackgroundImage = Image::FromFile(str3);
				 // Inicializacion de imagen de pila 3, Boton 3
				 os.str("");
				 os << vecP[2].top().getNum() + vecP[2].top().getFig() * 13;
				 liga = "C:\\cards\\" + os.str() + ".png";
				 str3 = gcnew String(liga.c_str());
				 button3->BackgroundImage = Image::FromFile(str3);
				 // Inicializacion de imagen de pila 4, Boton 4 (solo en caso de que la cantidad de pilas sea la correcta)
				 if (cantPilas < 4){
					 button4->Visible = false;
				 }
				 else {
					 button4->Visible = true;
					 os.str("");
					 os << vecP[3].top().getNum() + vecP[3].top().getFig() * 13;
					 liga = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(liga.c_str());
					 button4->BackgroundImage = Image::FromFile(str3);
				 }
				 // Inicializacion de imagen de pila 5, Boton 5 (solo en caso de que la cantidad de pilas sea la correcta)
				 if (cantPilas < 5){
					 button5->Visible = false;
				 }
				 else {
					 button5->Visible = true;
					 os.str("");
					 os << vecP[4].top().getNum() + vecP[4].top().getFig() * 13;
					 liga = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(liga.c_str());
					 button5->BackgroundImage = Image::FromFile(str3);
				 }
				 /// Inicializacion de imagen de pila 6, Boton 6 (solo en caso de que la cantidad de pilas sea la correcta)
				 if (cantPilas < 6){
					 button6->Visible = false;
				 }
				 else {
					 button6->Visible = true;
					 os.str("");
					 os << vecP[5].top().getNum() + vecP[5].top().getFig() * 13;
					 liga = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(liga.c_str());
					 button6->BackgroundImage = Image::FromFile(str3);
				 }
				 // Inicializacion de imagen de pila 7, Boton 7 (solo en caso de que la cantidad de pilas sea la correcta)
				 if (cantPilas < 7){
					 button7->Visible = false;
				 }
				 else {
					 button7->Visible = true;
					 os.str("");
					 os << vecP[6].top().getNum() + vecP[6].top().getFig() * 13;
					 liga = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(liga.c_str());
					 button7->BackgroundImage = Image::FromFile(str3);
				 }
				 // Inicializacion de imagen de pila 8, Boton 8 (solo en caso de que la cantidad de pilas sea la correcta)
				 if (cantPilas < 8){
					 button8->Visible = false;
				 }
				 else {
					 button8->Visible = true;
					 os.str("");
					 os << vecP[7].top().getNum() + vecP[7].top().getFig() * 13;
					 liga = "C:\\cards\\" + os.str() + ".png";
					 str3 = gcnew String(liga.c_str());
					 button8->BackgroundImage = Image::FromFile(str3);
				 }
				 
			 			 
}


};
}
