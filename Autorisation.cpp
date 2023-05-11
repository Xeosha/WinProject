
#include "Autorisation.h"
using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void main(array<String^>^ arg)
{
	std::setlocale(LC_CTYPE, "ru_RU.UTF-8");


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WinProject::Autorisation formAutorization;
	Application::Run(% formAutorization);

}