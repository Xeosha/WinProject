
#include "Autorisation.h"
using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void main(array<String^>^ arg)
{
	setlocale(0, "rus");


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WinProject::Autorisation formAutorization;
	Application::Run(% formAutorization);

}