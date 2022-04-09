#include "MyForm.h"
#include "string"

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	TestWinFormAppCpp::MyForm Form;
	Application::Run(% Form);
}