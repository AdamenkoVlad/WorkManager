#include "MyForm.h"
#include <Windows.h>
#include "AboutForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyProgram::MainForm^ mainForm = gcnew MyProgram::MainForm();
    Application::Run(mainForm);

    return 0;
}
