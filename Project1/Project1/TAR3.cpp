/*
Mario Sergio Fuentes Juarez		A01036141
Estructuras de datos	20 de febrero de 2014
Tarea 3: Juego de solitario
*/

// El programa es completamente funcional

#include "TAR3.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace std;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::TAR3 form;
	Application::Run(%form);

}

