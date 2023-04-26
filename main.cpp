
#include "MyForm.h"
#include "Autorisation.h"
#define WINAPI      __stdcall

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	WinProject::MyForm form;
	WinProject::Autorisation formAutorization;
	Application::Run(% formAutorization);
	Application::Run(% form);

}