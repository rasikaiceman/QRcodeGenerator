#include "MainWindowsForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;
using namespace System::Collections::Generic;
using namespace System::Configuration;
using namespace System::Collections::Specialized;

[System::STAThread]
int main(array<System::String^>^ args) { // Entry point

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SampleTestQR::MainWindowsForm form1;
	Application::Run(% form1); // opens MainWindowsForm.h as main interface
	return 0;

}
